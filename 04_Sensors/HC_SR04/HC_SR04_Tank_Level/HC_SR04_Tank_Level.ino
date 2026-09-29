// Water tank level meter (demonstration)
// Mount the sensor at the TOP of the tank pointing DOWN at the water surface.
// Same wiring as HC_SR04.ino (buzzer optional). Keep the module dry!

const int TRIG_PIN = 18;
const int ECHO_PIN = 19;
const int BUZZER_PIN = 25;

const float EMPTY_DISTANCE_CM = 30.0;   // Distance from sensor to water when tank is EMPTY (measure yours)
const float FULL_DISTANCE_CM  = 5.0;    // Distance from sensor to water when tank is FULL (measure yours)

float readDistanceCm()
{
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  unsigned long echoTime = pulseIn(ECHO_PIN, HIGH, 30000);
  if (echoTime == 0) return -1.0;
  return echoTime * 0.0343 / 2.0;
}

void setup()
{
  Serial.begin(115200);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop()
{
  float distance = readDistanceCm();

  if (distance < 0)
  {
    Serial.println("No echo");
  }
  else
  {
    // Convert distance to a percentage: FULL_DISTANCE -> 100 %, EMPTY_DISTANCE -> 0 %
    float level = (EMPTY_DISTANCE_CM - distance) * 100.0 / (EMPTY_DISTANCE_CM - FULL_DISTANCE_CM);
    level = constrain(level, 0.0, 100.0);

    Serial.print("Distance: ");
    Serial.print(distance, 1);
    Serial.print(" cm   Level: ");
    Serial.print(level, 0);
    Serial.println(" %");

    if (level >= 95.0)
    {
      digitalWrite(BUZZER_PIN, HIGH);          // Tank almost full
    }
    else
    {
      digitalWrite(BUZZER_PIN, LOW);
    }
  }

  delay(500);
}
