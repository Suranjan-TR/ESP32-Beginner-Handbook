// Button -> ESP32 -> LED
// Wiring: button between GPIO27 and GND; LED with 220 ohm resistor on GPIO26 (other end to GND)

const int BUTTON_PIN = 27;
const int LED_PIN = 26;

void setup()
{
  Serial.begin(115200);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
}

void loop()
{
  int buttonState = digitalRead(BUTTON_PIN);

  if (buttonState == LOW)              // Pressed
  {
    digitalWrite(LED_PIN, HIGH);       // LED ON
    Serial.println("Pressed -> LED ON");
  }
  else                                 // Released
  {
    digitalWrite(LED_PIN, LOW);        // LED OFF
    Serial.println("Released -> LED OFF");
  }

  delay(100);
}
