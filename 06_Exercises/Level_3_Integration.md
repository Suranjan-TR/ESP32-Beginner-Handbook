# Level 3 — Threshold Control, Multiple Sensors and Outputs

## 3.1 Threshold control
1. LDR: three zones — DARK (LED ON), DIM (LED blinks), BRIGHT (LED OFF).
2. Add **hysteresis** so the lamp never flickers (see [Night Lamp](../05_Mini_Projects/Automatic_Night_Lamp/README.md)).
3. HC-SR04: LED at < 50 cm, buzzer also at < 20 cm.

## 3.2 Multiple sensors
1. LDR + DHT11: print both on one line: `Light: 2100  Temp: 28.0 C`.
2. Night lamp that only turns on when it is dark **and** the temperature is below 35 °C.
3. HC-SR04 + LDR: a "robot" that beeps only when an obstacle is near **and** it is dark.

## 3.3 Multiple outputs
1. Traffic-light sequence with three LEDs (GPIO26, 25, 33): red 3 s, green 3 s, yellow 1 s.
2. Distance → number of blinking LEDs (near = 3 LEDs, far = 1 LED).
3. Temperature levels: green LED (< 28 °C), yellow (28–32 °C), red + buzzer (> 32 °C).

## 3.4 Flame, MQ-2, TCS3200
1. Find and document the polarity of your flame module.
2. Determine a good `ALERT_MARGIN` for MQ-2 by testing (ventilated area).
3. Calibrate the TCS3200 and classify red/green/blue objects with a success table.

## Check your understanding
- What is a threshold? How did you choose yours?
- Why do we average readings?
- What is the difference between `&&` and `||`?
