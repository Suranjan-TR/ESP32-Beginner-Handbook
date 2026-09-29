// LDR automatic night lamp
// Wiring: 3V3 -> LDR -> GPIO34 -> 10 kohm -> GND   (GPIO34 = ADC1 input)
//         GPIO26 -> 220 ohm -> LED -> GND

const int LDR_PIN = 34;             // Analog input (junction of LDR and 10 kohm resistor)
const int LED_PIN = 26;             // Lamp (LED)
const int DARK_THRESHOLD = 1500;    // CHANGE THIS after observing your own readings

void setup()
{
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
}

void loop()
{
  int ldrValue = analogRead(LDR_PIN);            // 0 to 4095
  float voltage = ldrValue * 3.3 / 4095.0;       // Approximate voltage at the pin

  Serial.print("ADC value: ");
  Serial.print(ldrValue);
  Serial.print("   Voltage (approx): ");
  Serial.print(voltage, 2);
  Serial.print(" V");

  if (ldrValue < DARK_THRESHOLD)                 // Low value = little light = dark
  {
    digitalWrite(LED_PIN, HIGH);
    Serial.println("   -> DARK  -> LED ON");
  }
  else
  {
    digitalWrite(LED_PIN, LOW);
    Serial.println("   -> LIGHT -> LED OFF");
  }

  delay(500);
}
