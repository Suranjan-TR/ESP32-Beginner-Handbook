# Chapter 5 — Introduction to the ESP32

## 5.1 What is the ESP32?

The **ESP32** is a low-cost **microcontroller** made by **Espressif Systems**. It contains a CPU, RAM, Flash access, many I/O pins and built-in **Wi-Fi** and **Bluetooth**.

**Why is it a microcontroller?** Because CPU, memory and input/output hardware are all on one chip, and it is designed to run one dedicated program controlling real-world devices.

> **Development board vs chip.** The ESP32 chip is tiny. A **development board** (DevKit) mounts the ESP32 module on a board with a USB connector, a USB-to-serial chip, a voltage regulator, buttons and pin headers so you can use it easily. When students say "ESP32" they usually mean this board.

## 5.2 Main features (only what beginners need)

| Feature | Meaning | Why you care |
|---|---|---|
| **CPU** | Dual-core Xtensa processor, up to 240 MHz | Fast enough for any beginner project |
| **RAM** | About 520 KB on-chip | Holds variables while running |
| **Flash** | Typically 4 MB on the module | Stores your program |
| **GPIO** | General-Purpose Input/Output pins | Connect LEDs, buttons, sensors |
| **ADC** | Analog-to-Digital Converter | Reads analog voltages (LDR, MQ-2) |
| **PWM** | Pulse Width Modulation | Dim LEDs, control motor speed |
| **UART** | Serial communication | USB Serial Monitor, GPS, etc. |
| **I2C** | 2-wire communication bus | Displays, many sensors |
| **SPI** | Fast 4-wire communication bus | SD cards, TFT displays |
| **Wi-Fi** | Wireless network | Send data to internet/phone |
| **Bluetooth** | Short-range wireless | Talk to phone |

Wi-Fi and Bluetooth are not needed in this handbook, but they are the reason the ESP32 is popular.

## 5.3 Terms explained before we use them

- **GPIO** – *General-Purpose Input/Output.* A metal pin whose job (input or output) **you choose in your program**. See [GPIO](gpio.md).
- **ADC** – *Analog-to-Digital Converter.* It converts an analog voltage into a digital number the ESP32 can process. The ESP32 ADC is **12-bit**: it gives numbers from **0 to 4095**. (0 ≈ 0 V, 4095 ≈ the top of the measurable range, about 3.3 V.)
- **PWM** – *Pulse Width Modulation.* The pin switches ON/OFF very fast. If it is ON 25 % of the time, an LED looks dim; ON 90 % looks bright.
- **UART** – *Universal Asynchronous Receiver/Transmitter.* A simple two-wire serial link (TX to send, RX to receive). The USB cable to your laptop uses UART through a USB-serial chip. That is how `Serial.println()` reaches the Serial Monitor.
- **I2C** – *Inter-Integrated Circuit.* Two wires (SDA data, SCL clock) shared by many devices, each with its own address.
- **SPI** – *Serial Peripheral Interface.* Faster than I2C, uses 4 wires (MOSI, MISO, SCK, CS).

## 5.4 Digital vs analog signals

- **Digital signal:** only two levels. HIGH (about 3.3 V) or LOW (about 0 V). Like a light switch.
- **Analog signal:** any value in a range, e.g. 0 V to 3.3 V. Like a dimmer knob.

## 5.5 Voltage levels — the 3.3 V rule

The ESP32 works with **3.3 V logic**:

| Level | Voltage |
|---|---|
| LOW (0) | ≈ 0 V |
| HIGH (1) | ≈ 3.3 V |

The GPIO pins are **not designed for 5 V**. A 5 V signal can damage the pin or the whole chip.

> ⚠️ **WARNING — DO NOT connect a 5 V signal directly to an ESP32 GPIO** unless the exact board/input specification confirms it is safe.
> Examples that need care in this handbook: **HC-SR04 ECHO** (often 5 V) and **MQ-2 analog output** (may reach up to 5 V). We will use **voltage dividers** for them.

Also:
- Use `3V3` pin to power 3.3 V sensors. Use the 5 V pin (`VIN`/`5V`, from USB) only for parts that need 5 V.
- Each GPIO can supply only a few milliamps. An LED **needs a resistor**.

## 5.6 Why is the ESP32 popular?

Cheap, powerful, Wi-Fi/Bluetooth built-in, works in Arduino IDE, huge community.

## 5.7 Check yourself

1. Name three peripherals inside the ESP32 and what each does.
2. What number range does the ESP32 ADC give?
3. Why must we not connect a 5 V ECHO directly to a GPIO?

---
Next: [GPIO](gpio.md)
