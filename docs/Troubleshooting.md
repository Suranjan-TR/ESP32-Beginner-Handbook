# Troubleshooting Guide

For each problem: **possible cause → how to check → solution.**

## 1. ESP32 not detected by the laptop
| | |
|---|---|
| **Cause** | Charge-only USB cable; missing driver; faulty port/board |
| **Check** | Try another cable (a known data cable) and another USB port; Device Manager → look for an unknown device |
| **Solution** | Use a data cable; install CP210x or CH340 driver (links in the [setup guide](../02_ESP32/arduino_ide_setup.md)) |

## 2. COM port missing
| | |
|---|---|
| **Cause** | Driver not installed; board not powered; cable problem |
| **Check** | Unplug/replug and watch **Device Manager → Ports** |
| **Solution** | Install the driver; change cable/port; reboot laptop; try another board |

## 3. Upload failed ("Failed to connect", stuck at "Connecting…")
| | |
|---|---|
| **Cause** | Board not in download mode; wrong port/board; something connected to GPIO0/2/12/15; bad cable |
| **Check** | Tools → Board = ESP32 Dev Module; Tools → Port correct; disconnect wires from pins |
| **Solution** | Hold **BOOT** when "Connecting…" appears (release when upload starts); use a data cable; unplug sensors during upload |

## 4. ESP32 keeps resetting
| | |
|---|---|
| **Cause** | Short circuit; too much current drawn (buzzer/sensor); weak USB power; program crash |
| **Check** | Unplug everything except USB; upload Hello ESP32; add parts one by one; read the Serial Monitor for "Guru Meditation" or "Brownout" |
| **Solution** | Remove short; use a better USB port/cable or powered hub; power large loads separately |

## 5. Sensor gives zero
| | |
|---|---|
| **Cause** | No power; wrong GPIO; missing GND; divider miswired |
| **Check** | Multimeter on VCC and signal pins; print raw value |
| **Solution** | Fix wiring; check pin numbers in code match your wires |

## 6. Sensor gives unstable readings
| | |
|---|---|
| **Cause** | Loose breadboard contact; noise; USB power noise; ADC nature |
| **Check** | Wiggle wires; watch readings for a minute |
| **Solution** | Shorter wires; average 10 readings; add `delay`; add a 0.1 µF capacitor from ADC pin to GND |

## 7. LED does not glow
| | |
|---|---|
| **Cause** | LED reversed; no resistor path; wrong GPIO; pin not set as OUTPUT |
| **Check** | Long leg to resistor/GPIO side; measure GPIO voltage while HIGH (≈3.3 V) |
| **Solution** | Flip LED; correct wiring; use `pinMode(pin, OUTPUT)` |

## 8. DHT11 reading fails
| | |
|---|---|
| **Cause** | Missing pull-up (bare sensor); wrong pin or type; read too quickly; library missing |
| **Check** | Wiring order VCC/DATA/GND; `DHT dht(4, DHT11)` matches pin |
| **Solution** | Add 10 kΩ pull-up; wait ≥2 s between reads; install the libraries |

## 9. HC-SR04 gives incorrect distance
| | |
|---|---|
| **Cause** | VCC not 5 V; ECHO divider wrong; soft/angled target; reading timeout |
| **Check** | Measure VCC = ≈5 V and ECHO node ≤ 3.3 V; test with a flat wall at 30 cm |
| **Solution** | Correct power and divider; aim at a hard flat surface; keep >2 cm |

## 10. ADC values don't make sense
| | |
|---|---|
| **Cause** | Used an ADC2 pin; divider wrong; input above 3.3 V; ADC non-linearity |
| **Check** | Verify pin (use ADC1 GPIO32–39); measure the voltage with a multimeter |
| **Solution** | Use ADC1 pins; correct the divider; treat readings as relative, not lab-accurate |

## 11. Serial Monitor shows garbage characters
| | |
|---|---|
| **Cause** | Baud rate mismatch; boot messages at 74880 baud; wrong port |
| **Check** | Baud rate dropdown vs `Serial.begin()` |
| **Solution** | Set the Serial Monitor to **115200** (same as code) and press EN |

## General method
1. Simplify: remove everything except USB.
2. Upload **Hello ESP32**.
3. Add **one** component at a time.
4. Print raw values.
5. Check voltage with a multimeter.
