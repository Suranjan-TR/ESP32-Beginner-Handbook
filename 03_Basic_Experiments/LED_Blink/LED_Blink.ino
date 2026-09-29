// Experiment 2 - LED blinking
// Wiring: GPIO26 -> 220 ohm resistor -> LED anode (+); LED cathode (-) -> GND

const int LED_PIN = 26;

void setup()
{
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
}

void loop()
{
  digitalWrite(LED_PIN, HIGH);   // LED ON
  Serial.println("LED ON");
  delay(1000);                   // Stay ON for 1 second

  digitalWrite(LED_PIN, LOW);    // LED OFF
  Serial.println("LED OFF");
  delay(1000);                   // Stay OFF for 1 second
}
