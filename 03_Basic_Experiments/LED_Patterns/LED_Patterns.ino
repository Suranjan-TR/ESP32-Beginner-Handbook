// Experiment 3 - Different blink patterns
// Wiring: GPIO26 -> 220 ohm resistor -> LED anode (+); LED cathode (-) -> GND

const int LED_PIN = 26;

// Blink the LED "times" times. Each blink is ON for onMs and OFF for offMs.
void blinkLed(int times, int onMs, int offMs)
{
  for (int i = 0; i < times; i++)
  {
    digitalWrite(LED_PIN, HIGH);
    delay(onMs);
    digitalWrite(LED_PIN, LOW);
    delay(offMs);
  }
}

void setup()
{
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
}

void loop()
{
  Serial.println("Pattern 1: fast blink");
  blinkLed(5, 100, 100);
  delay(1000);

  Serial.println("Pattern 2: heartbeat (two quick blinks)");
  blinkLed(2, 150, 150);
  delay(1000);

  Serial.println("Pattern 3: SOS (... --- ...)");
  blinkLed(3, 200, 200);    // three short
  blinkLed(3, 600, 200);    // three long
  blinkLed(3, 200, 200);    // three short
  delay(2000);
}
