# Optional Introduction: Arduino / Tinkercad LED Demo (10–15 minutes)

> **This page is optional and short.** The main practical work in this handbook uses the **physical ESP32** connected to your laptop. The demo below only shows the *idea* of a microcontroller turning an LED on and off, before you do it for real.

## Purpose
See the idea **SENSE → PROCESS → ACT** in its simplest form (no sensor yet: PROCESS → ACT) on an on-screen board.

## Instructor demonstration (about 10–15 minutes)
1. Open Tinkercad Circuits (https://www.tinkercad.com/circuits) with an Arduino Uno.
2. Place an LED and a 220 Ω resistor; connect pin 13 → resistor → LED → GND.
3. Use the code editor: `pinMode(13, OUTPUT); digitalWrite(13, HIGH); delay(1000); digitalWrite(13, LOW); delay(1000);`
4. Start the simulation; show the LED blinking.
5. Ask: *What decides how fast it blinks? Where is the program stored on a real board?*

## Then move to the real board
The ESP32 uses the **same** `pinMode / digitalWrite / delay` functions. The difference: on the physical ESP32 you pick a GPIO such as **GPIO26**, connect real wires, and upload through USB. Continue with [Hello ESP32](Hello_ESP32/README.md).
