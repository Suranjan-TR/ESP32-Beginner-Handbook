// Project 2 - Obstacle Detector (HC-SR04 + buzzer + LED)
// Wiring: VIN(5V)->VCC, GND->GND, GPIO18->TRIG, ECHO->1k->node->GPIO19, node->2k->GND
//         GPIO25 -> active buzzer (+);  GPIO26 -> 220 ohm -> LED -> GND

const int TRIG_PIN = 18;
const int ECHO_PIN = 19;
const int BUZZER_PIN = 25;
const int LED_PIN = 26;

const float OBSTACLE_CM = 30.0;

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
  pinMode(LED_PIN, OUTPUT);
}

void loop()
{
  float distance = readDistanceCm();

  bool obstacle = (distance > 0 && distance < OBSTACLE_CM);

  if (obstacle)
  {
    Serial.print("OBSTACLE at ");
    Serial.print(distance, 1);
    Serial.println(" cm");
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(BUZZER_PIN, HIGH);     // short beep
    delay(100);
    digitalWrite(BUZZER_PIN, LOW);
    delay(100);
  }
  else
  {
    Serial.println("Path clear");
    digitalWrite(LED_PIN, LOW);
    digitalWrite(BUZZER_PIN, LOW);
    delay(200);
  }
}
