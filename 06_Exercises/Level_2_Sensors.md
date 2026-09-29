# Level 2 — LDR, DHT11, Ultrasonic

## 2.1 LDR
1. Build the LDR circuit and print the ADC value.
2. Make a table: bright light / room / shadow / covered → ADC values.
3. Swap the LDR and the 10 kΩ. Predict the new behaviour, then check.
4. Print the approximate voltage using `value * 3.3 / 4095.0`.

## 2.2 DHT11
1. Install the library and print temperature and humidity.
2. Convert the temperature to Fahrenheit.
3. Breathe on the sensor; watch humidity rise. How long until it returns to normal?
4. Print "Comfortable" if 20–28 °C, else "Uncomfortable".

## 2.3 Ultrasonic (HC-SR04)
1. **Check your divider with a multimeter first** (node ≤ 3.3 V).
2. Print the distance; compare with a ruler at 10, 20, 50 cm. Make an error table.
3. Print the distance in cm and inches.
4. Point the sensor at a soft cushion and at a wall. What changes? Why?

## Check your understanding
- Why can't `analogRead()` measure resistance directly?
- What does the ECHO pulse width represent?
- Why does the DHT11 need a delay between readings?
