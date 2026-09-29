// Project 4 - Gas Warning PROTOTYPE (MQ-2 + buzzer)  -  educational, NOT a certified safety device
// Wiring: MQ-2 VCC->VIN(5V), GND->GND, AO->10k->node->GPIO35, node->20k->GND
//         GPIO25 -> active buzzer (+)

const int MQ2_PIN = 35;
const int BUZZER_PIN = 25;

const int WARMUP_SECONDS = 30;
const int ALERT_MARGIN = 300;
int baseline = 0;

int readAverage()
{
  long sum = 0;
  for (int i = 0; i < 10; i++)
  {
    sum += analogRead(MQ2_PIN);
    delay(10);
  }
  return sum / 10;
}

void setup()
{
  Serial.begin(115200);
  pinMode(BUZZER_PIN, OUTPUT);

  Serial.println("Warming up in clean air...");
  delay(WARMUP_SECONDS * 1000UL);
  baseline = readAverage();
  Serial.print("Baseline: ");
  Serial.println(baseline);
}

void loop()
{
  int value = readAverage();
  Serial.print("Value: ");
  Serial.println(value);

  if (value > baseline + ALERT_MARGIN)
  {
    // Beeping alarm: beep, pause, beep
    digitalWrite(BUZZER_PIN, HIGH);
    delay(200);
    digitalWrite(BUZZER_PIN, LOW);
    delay(200);
  }
  else
  {
    digitalWrite(BUZZER_PIN, LOW);
    delay(300);
  }
}
