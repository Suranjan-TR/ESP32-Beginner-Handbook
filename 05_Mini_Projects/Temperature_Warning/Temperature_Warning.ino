// Project 3 - Temperature Warning (DHT11 + LED + buzzer)
// Wiring: DHT11 VCC->3V3, DATA->GPIO4, GND->GND (10k pull-up on bare sensors)
//         GPIO26 -> 220 ohm -> LED -> GND;  GPIO25 -> active buzzer (+)
// Library: "DHT sensor library" by Adafruit (+ "Adafruit Unified Sensor")

#include "DHT.h"

const int DHT_PIN = 4;
const int LED_PIN = 26;
const int BUZZER_PIN = 25;

const float WARNING_C = 30.0;    // LED ON above this
const float ALARM_C = 35.0;      // Buzzer ON above this

DHT dht(DHT_PIN, DHT11);

void setup()
{
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  dht.begin();
}

void loop()
{
  delay(2000);

  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  if (isnan(temperature) || isnan(humidity))
  {
    Serial.println("DHT11 read failed - check wiring");
    return;
  }

  Serial.print("Temp: ");
  Serial.print(temperature, 1);
  Serial.print(" C  Humidity: ");
  Serial.print(humidity, 0);
  Serial.print(" %  ");

  if (temperature >= ALARM_C)
  {
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(BUZZER_PIN, HIGH);
    Serial.println("-> ALARM");
  }
  else if (temperature >= WARNING_C)
  {
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(BUZZER_PIN, LOW);
    Serial.println("-> WARNING");
  }
  else
  {
    digitalWrite(LED_PIN, LOW);
    digitalWrite(BUZZER_PIN, LOW);
    Serial.println("-> normal");
  }
}
