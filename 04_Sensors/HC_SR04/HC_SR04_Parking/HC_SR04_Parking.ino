// Car parking sensor: the closer the object, the faster the buzzer beeps.
// Same wiring as HC_SR04.ino

const int TRIG_PIN = 18;
const int ECHO_PIN = 19;
const int BUZZER_PIN = 25;

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
  Serial.println(distance);

  if (distance < 0 || distance > 100)          // Nothing near: stay silent
  {
    digitalWrite(BUZZER_PIN, LOW);
    delay(200);
  }
  else if (distance < 10)                      // Very close: continuous tone
  {
    digitalWrite(BUZZER_PIN, HIGH);
    delay(100);
  }
  else                                         // Beep gap grows with distance
  {
    int gap = (int)(distance * 5);             // e.g. 50 cm -> 250 ms
    digitalWrite(BUZZER_PIN, HIGH);
    delay(50);
    digitalWrite(BUZZER_PIN, LOW);
    delay(gap);
  }
}
