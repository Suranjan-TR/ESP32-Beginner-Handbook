// Push button reading
// Wiring: one leg of the button -> GPIO27, the other leg -> GND. No external resistor needed.

const int BUTTON_PIN = 27;

void setup()
{
  Serial.begin(115200);
  pinMode(BUTTON_PIN, INPUT_PULLUP);   // Input with the internal pull-up resistor enabled
}

void loop()
{
  int buttonState = digitalRead(BUTTON_PIN);   // HIGH or LOW

  if (buttonState == LOW)
  {
    Serial.println("Button PRESSED  (pin reads LOW)");
  }
  else
  {
    Serial.println("Button RELEASED (pin reads HIGH)");
  }

  delay(200);   // Read 5 times per second so the Serial Monitor is readable
}
