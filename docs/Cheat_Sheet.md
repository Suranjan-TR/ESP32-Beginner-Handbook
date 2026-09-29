# ESP32 Arduino CHEAT SHEET (one page)

| Function | What it does (one sentence) |
|---|---|
| `setup()` | Runs **once** at power-up/reset; used to start Serial and set pin modes. |
| `loop()` | Runs **repeatedly forever** after `setup()`; contains the main program. |
| `pinMode(pin, mode)` | Sets a pin as `OUTPUT`, `INPUT` or `INPUT_PULLUP`. |
| `digitalRead(pin)` | Returns `HIGH` (3.3 V) or `LOW` (0 V) for a digital input. |
| `digitalWrite(pin, value)` | Sets an output pin to `HIGH` (3.3 V) or `LOW` (0 V). |
| `analogRead(pin)` | Returns 0–4095 for the voltage (0–3.3 V) on an ADC pin. |
| `Serial.begin(baud)` | Starts serial communication with the laptop at the given speed (use 115200). |
| `Serial.print(x)` / `Serial.println(x)` | Sends text/number to the Serial Monitor (`println` adds a new line). |
| `delay(ms)` | Pauses the program for the given milliseconds. |
| `delayMicroseconds(us)` | Pauses the program for the given microseconds. |
| `pulseIn(pin, level, timeout)` | Measures how long (µs) a pin stays at `level`; returns 0 on timeout. |

## Handbook pin map (ESP32 DevKit 38-pin — verify yours)
LED 26 · Button 27 · Buzzer 25 · LDR 34 · MQ-2 AO 35 · HC-SR04 TRIG 18 / ECHO 19 · DHT11 4 · Flame DO 32 / AO 33 · TCS3200 S0 16, S1 17, S2 21, S3 22, OUT 23

## Rules
- Logic is **3.3 V**. **Never** connect 5 V to a GPIO.
- HC-SR04 ECHO and MQ-2 AO → **voltage divider**.
- GPIO 34–39 = **input only**. Avoid 0, 2, 5, 12, 15 and 6–11.
- Use ADC1 (32–39) for `analogRead`.
- Serial Monitor baud = **115200**.
- Observe **raw values first**, then choose thresholds.
