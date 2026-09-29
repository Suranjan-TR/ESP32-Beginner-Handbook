# Level 1 — LED, Button, Serial Monitor

## 1.1 LED blink
1. Blink the LED with 200 ms ON, 800 ms OFF.
2. Make it blink 3 times, pause 2 s, repeat.
3. Add a second LED (GPIO25 + 220 Ω) and make the two LEDs blink alternately.

## 1.2 Serial Monitor
1. Print your name and today's date every 2 seconds.
2. Print the numbers 1 to 10, one per line, then stop printing (hint: use a variable and `if`).
3. Counter demonstration (RAM vs Flash, see [Memory chapter](../01_Basics/memory.md)):

```cpp
int count = 0;              // Stored in RAM

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  count = count + 1;        // Add 1 each time
  Serial.println(count);
  delay(1000);
}
```
Press the **EN** button. Why does the count restart from 1 while the program still runs?

## 1.3 Button
1. Print "PRESSED" only **once** per press (hint: remember the previous state).
2. LED ON while pressed (already done); now make it OFF while pressed.
3. **Toggle:** each press flips the LED between ON and OFF.
4. Count button presses and print the total.

## Check your understanding
- Why do we use `INPUT_PULLUP`?
- What voltage does a HIGH pin have?
- What does `delay(1000)` do to the rest of the program?
