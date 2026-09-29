// TCS3200 colour sensor - RGB measurement and simple colour classification
// Wiring (module powered at 3.3 V): S0->GPIO16, S1->GPIO17, S2->GPIO21, S3->GPIO22, OUT->GPIO23, OE->GND

const int S0_PIN = 16;
const int S1_PIN = 17;
const int S2_PIN = 21;
const int S3_PIN = 22;
const int OUT_PIN = 23;

// ---- CALIBRATION VALUES (pulse widths in microseconds) ----
// These are PLACEHOLDERS. Measure your own: hold a WHITE sheet, then a BLACK sheet, about 2 cm away.
long redWhite   = 30,  redBlack   = 200;
long greenWhite = 30,  greenBlack = 200;
long blueWhite  = 30,  blueBlack  = 200;

// Select a filter (S2, S3) and measure the pulse width of OUT (LOW part of the wave)
long readPulse(int s2State, int s3State)
{
  digitalWrite(S2_PIN, s2State);
  digitalWrite(S3_PIN, s3State);
  delay(50);                                  // Let the sensor settle
  return pulseIn(OUT_PIN, LOW, 100000);       // Microseconds; 0 if timeout
}

// Convert a pulse width to a 0-255 colour value using the white/black calibration
int toColorValue(long pulse, long whitePulse, long blackPulse)
{
  if (pulse == 0) return 0;                   // Timeout -> treat as no signal
  long value = map(pulse, whitePulse, blackPulse, 255, 0);
  return constrain(value, 0, 255);
}

void setup()
{
  Serial.begin(115200);
  pinMode(S0_PIN, OUTPUT);
  pinMode(S1_PIN, OUTPUT);
  pinMode(S2_PIN, OUTPUT);
  pinMode(S3_PIN, OUTPUT);
  pinMode(OUT_PIN, INPUT);

  digitalWrite(S0_PIN, HIGH);                 // S0=HIGH, S1=LOW -> 20 % frequency scaling
  digitalWrite(S1_PIN, LOW);
}

void loop()
{
  long redPulse   = readPulse(LOW, LOW);      // S2=LOW,  S3=LOW  -> RED filter
  long bluePulse  = readPulse(LOW, HIGH);     // S2=LOW,  S3=HIGH -> BLUE filter
  long greenPulse = readPulse(HIGH, HIGH);    // S2=HIGH, S3=HIGH -> GREEN filter

  int red   = toColorValue(redPulse,   redWhite,   redBlack);
  int green = toColorValue(greenPulse, greenWhite, greenBlack);
  int blue  = toColorValue(bluePulse,  blueWhite,  blueBlack);

  Serial.print("Pulse R/G/B (us): ");
  Serial.print(redPulse);   Serial.print(" / ");
  Serial.print(greenPulse); Serial.print(" / ");
  Serial.print(bluePulse);
  Serial.print("   RGB value: ");
  Serial.print(red);   Serial.print(", ");
  Serial.print(green); Serial.print(", ");
  Serial.print(blue);

  // Very simple classification: the strongest colour wins if it is clearly stronger than the others
  if (red > green + 30 && red > blue + 30)
  {
    Serial.println("   -> RED   (Bin 1)");
  }
  else if (green > red + 30 && green > blue + 30)
  {
    Serial.println("   -> GREEN (Bin 2)");
  }
  else if (blue > red + 30 && blue > green + 30)
  {
    Serial.println("   -> BLUE  (Bin 3)");
  }
  else
  {
    Serial.println("   -> UNKNOWN (Bin 4)");
  }

  delay(500);
}
