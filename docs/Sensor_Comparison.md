# Sensor Comparison

| Sensor | What it detects | Working principle | Signal type | ESP32 interface | Simple application |
|---|---|---|---|---|---|
| **LDR** | Light intensity | Resistance decreases as light increases; divider turns it into voltage | Analog voltage | `analogRead()` on ADC1 pin (GPIO34) | Automatic night lamp |
| **HC-SR04** | Distance | Ultrasonic burst; echo time gives distance | Pulse width (ECHO) | `digitalWrite()` TRIG + `pulseIn()` ECHO (GPIO18/19, ECHO through divider) | Obstacle detector |
| **DHT11** | Temperature, humidity | Thermistor + moisture-sensitive element; internal chip digitises | Digital data protocol (40 bits) | Adafruit DHT library (GPIO4) | Room temperature monitor |
| **MQ-2** | Combustible gas / smoke (relative level) | Heated SnO₂ element; resistance falls with gas | Analog voltage (AO) / digital (DO) | `analogRead()` via divider (GPIO35) | Gas/smoke warning prototype |
| **Flame sensor** | Infrared from flame | IR photodiode; comparator makes DO | Digital (DO) + analog (AO) | `digitalRead()` / `analogRead()` (GPIO32/33) | Flame warning |
| **TCS3200** | Colour (R, G, B) | Filtered photodiodes → current-to-frequency converter | Frequency (square wave) | `pulseIn()` with S0–S3 control (GPIO16/17/21/22/23) | Colour sorting |

## Voltage summary

| Sensor | Supply used in this handbook | Output level at ESP32 pin | Needs divider? |
|---|---|---|---|
| LDR + 10 kΩ | 3.3 V | 0–3.3 V | No |
| HC-SR04 | **5 V** | ECHO ≈ 5 V | **Yes (1 kΩ / 2 kΩ)** |
| DHT11 | 3.3 V | 3.3 V | No |
| MQ-2 | **5 V** | AO up to ≈ 5 V | **Yes (10 kΩ / 20 kΩ)** |
| Flame | 3.3 V | ≤ 3.3 V | No |
| TCS3200 | 3.3 V | ≤ 3.3 V | No |

Back to [Table of Contents](Table_of_Contents.md)
