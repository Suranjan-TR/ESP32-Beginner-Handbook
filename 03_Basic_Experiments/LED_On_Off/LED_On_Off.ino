// Experiment 1 - LED ON / OFF
// Wiring: GPIO26 -> 220 ohm resistor -> LED anode (+); LED cathode (-) -> GND

const int LED_PIN = 26;      // The GPIO pin connected to the LED

void setup()
{
  pinMode(LED_PIN, OUTPUT);      // Make the pin an OUTPUT
  digitalWrite(LED_PIN, HIGH);   // HIGH = 3.3 V -> LED ON
  // Change HIGH to LOW, upload again, and the LED will stay OFF.
}

void loop()
{
  // Nothing to repeat in this experiment.
}
