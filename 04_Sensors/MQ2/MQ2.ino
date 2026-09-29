// MQ-2 gas/smoke warning PROTOTYPE (educational - NOT a certified safety device)
// Wiring: MQ-2 VCC -> VIN(5V), GND -> GND,
//         AO -> 10 kohm -> node -> GPIO35, node -> 20 kohm (2 x 10 kohm) -> GND
//         GPIO25 -> active buzzer (+), GPIO26 -> 220 ohm -> LED

const int MQ2_PIN = 35;
const int BUZZER_PIN = 25;
const int LED_PIN = 26;

const int WARMUP_SECONDS = 30;     // Use longer (2-5 minutes) for better stability
const int ALERT_MARGIN = 300;      // Alarm if reading rises this much above clean-air baseline

int baseline = 0;                  // Clean-air reading measured after warm-up

// Average 10 readings to reduce noise
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
  pinMode(LED_PIN, OUTPUT);

  Serial.println("MQ-2 warming up in CLEAN AIR...");
  for (int s = WARMUP_SECONDS; s > 0; s--)
  {
    Serial.print("Warm-up: ");
    Serial.print(s);
    Serial.println(" s");
    delay(1000);
  }

  baseline = readAverage();
  Serial.print("Baseline (clean air) ADC value: ");
  Serial.println(baseline);
}

void loop()
{
  int value = readAverage();

  Serial.print("MQ-2 ADC value: ");
  Serial.print(value);
  Serial.print("   (baseline ");
  Serial.print(baseline);
  Serial.print(")");

  if (value > baseline + ALERT_MARGIN)
  {
    digitalWrite(BUZZER_PIN, HIGH);
    digitalWrite(LED_PIN, HIGH);
    Serial.println("   -> GAS/SMOKE WARNING");
  }
  else
  {
    digitalWrite(BUZZER_PIN, LOW);
    digitalWrite(LED_PIN, LOW);
    Serial.println("   -> normal");
  }

  delay(300);
}
