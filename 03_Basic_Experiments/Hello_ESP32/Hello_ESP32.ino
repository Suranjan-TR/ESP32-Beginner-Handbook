// Hello_ESP32 - prints a message once per second to the Serial Monitor.

void setup()
{
  Serial.begin(115200);   // Start serial communication at 115200 bits per second
}

void loop()
{
  Serial.println("Hello ESP32");   // Send text followed by a new line
  delay(1000);                     // Wait 1000 milliseconds (1 second)
}
