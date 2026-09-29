// DHT11 room temperature monitor
// Wiring: DHT11 VCC -> 3V3, DATA -> GPIO4, GND -> GND (10 kohm pull-up DATA->3V3 if bare sensor)
//         GPIO26 -> 220 ohm -> LED -> GND (warning LED)
// Library needed: "DHT sensor library" by Adafruit (and "Adafruit Unified Sensor")

#include "DHT.h"

const int DHT_PIN = 4;
const int LED_PIN = 26;
const float TEMP_LIMIT_C = 30.0;   // LED turns ON above this temperature

DHT dht(DHT_PIN, DHT11);           // Create a DHT object for a DHT11 on GPIO4

void setup()
{
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  dht.begin();
  Serial.println("DHT11 started");
}

void loop()
{
  delay(2000);                                   // DHT11 needs time between readings

  float humidity = dht.readHumidity();           // Percent
  float temperature = dht.readTemperature();     // Degrees Celsius

  if (isnan(humidity) || isnan(temperature))     // isnan = "is not a number" -> reading failed
  {
    Serial.println("Failed to read from DHT11 - check wiring");
    return;                                      // Skip the rest and try again
  }

  Serial.print("Temperature: ");
  Serial.print(temperature, 1);
  Serial.print(" C   Humidity: ");
  Serial.print(humidity, 0);
  Serial.println(" %");

  if (temperature > TEMP_LIMIT_C)
  {
    digitalWrite(LED_PIN, HIGH);
    Serial.println("WARNING: temperature above limit");
  }
  else
  {
    digitalWrite(LED_PIN, LOW);
  }
}
