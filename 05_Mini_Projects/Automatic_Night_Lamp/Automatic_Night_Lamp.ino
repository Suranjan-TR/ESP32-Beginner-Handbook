// Project 1 - Automatic Night Lamp (LDR + LED)
// Wiring: 3V3 -> LDR -> GPIO34 -> 10 kohm -> GND;  GPIO26 -> 220 ohm -> LED -> GND
// Uses two thresholds (hysteresis) so the lamp does not flicker near the switching point.

const int LDR_PIN = 34;
const int LED_PIN = 26;

const int DARK_ON_THRESHOLD = 1400;    // Below this value -> lamp ON   (measure and adjust!)
const int LIGHT_OFF_THRESHOLD = 1800;  // Above this value -> lamp OFF  (must be higher than the ON value)

bool lampIsOn = false;                 // Remembers the current lamp state

// Average 10 readings to smooth the noise
int readLightLevel()
{
  long sum = 0;
  for (int i = 0; i < 10; i++)
  {
    sum += analogRead(LDR_PIN);
    delay(5);
  }
  return sum / 10;
}

void setup()
{
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
}

void loop()
{
  int light = readLightLevel();

  if (!lampIsOn && light < DARK_ON_THRESHOLD)
  {
    lampIsOn = true;                   // It became dark
  }
  else if (lampIsOn && light > LIGHT_OFF_THRESHOLD)
  {
    lampIsOn = false;                  // It became bright
  }

  digitalWrite(LED_PIN, lampIsOn ? HIGH : LOW);

  Serial.print("Light level: ");
  Serial.print(light);
  Serial.print("   Lamp: ");
  Serial.println(lampIsOn ? "ON" : "OFF");

  delay(300);
}
