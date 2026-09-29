// HC-SR04 obstacle detector
// Wiring: VIN(5V) -> VCC, GND -> GND, GPIO18 -> TRIG,
//         ECHO -> 1 kohm -> node -> GPIO19, node -> 2 kohm -> GND   (voltage divider!)
//         GPIO25 -> active buzzer (+), buzzer (-) -> GND

const int TRIG_PIN = 18;
const int ECHO_PIN = 19;
const int BUZZER_PIN = 25;

const float ALERT_DISTANCE_CM = 20.0;        // Buzzer ON if closer than this
const unsigned long TIMEOUT_US = 30000;      // Stop waiting for echo after 30 ms (about 5 m)

// Measure distance in centimetres. Returns -1 if no echo was received.
float readDistanceCm()
{
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);              // 10 microsecond trigger pulse
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  unsigned long echoTime = pulseIn(ECHO_PIN, HIGH, TIMEOUT_US);   // microseconds

  if (echoTime == 0)
  {
    return -1.0;                             // Timeout: nothing detected
  }
  return echoTime * 0.0343 / 2.0;            // Speed of sound = 0.0343 cm/us, divide by 2 (go and return)
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
    Serial.println("No echo received");
    digitalWrite(BUZZER_PIN, LOW);
  }
  else
  {
    Serial.print("Distance: ");
    Serial.print(distance, 1);
    Serial.println(" cm");

    if (distance < ALERT_DISTANCE_CM)
    {
      digitalWrite(BUZZER_PIN, HIGH);        // Obstacle close -> buzzer ON
    }
    else
    {
      digitalWrite(BUZZER_PIN, LOW);
    }
  }

  delay(200);
}
