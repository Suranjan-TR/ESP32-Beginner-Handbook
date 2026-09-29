// Flame sensor warning PROTOTYPE (educational - NOT a certified fire detector)
// Wiring: module VCC -> 3V3, GND -> GND, DO -> GPIO32, AO -> GPIO33
//         GPIO25 -> active buzzer (+), GPIO26 -> 220 ohm -> LED

const int FLAME_DO_PIN = 32;
const int FLAME_AO_PIN = 33;
const int BUZZER_PIN = 25;
const int LED_PIN = 26;

// Most modules give DO = LOW when a flame is detected. VERIFY YOURS and change if needed.
const bool FLAME_ACTIVE_LOW = true;

void setup()
{
  Serial.begin(115200);
  pinMode(FLAME_DO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop()
{
  int digitalState = digitalRead(FLAME_DO_PIN);   // HIGH or LOW
  int analogValue = analogRead(FLAME_AO_PIN);     // 0 to 4095

  bool flameDetected;
  if (FLAME_ACTIVE_LOW)
  {
    flameDetected = (digitalState == LOW);
  }
  else
  {
    flameDetected = (digitalState == HIGH);
  }

  Serial.print("DO: ");
  Serial.print(digitalState);
  Serial.print("   AO: ");
  Serial.print(analogValue);

  if (flameDetected)
  {
    digitalWrite(BUZZER_PIN, HIGH);
    digitalWrite(LED_PIN, HIGH);
    Serial.println("   -> FLAME DETECTED");
  }
  else
  {
    digitalWrite(BUZZER_PIN, LOW);
    digitalWrite(LED_PIN, LOW);
    Serial.println("   -> no flame");
  }

  delay(300);
}
