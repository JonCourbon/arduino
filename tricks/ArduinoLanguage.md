Tricks concerning Arduino Language
---------

- The Arduino language is based on C/C++
- [Language reference!](https://www.arduino.cc/en/Reference/HomePage)


### Variables #
- double and float

On the Uno and other ATMEGA based boards, the double implementation is exactly the same as the float, with no gain in precision (4 bytes)
- constant values for pin number

The global definition of PIN is often like: `int led = 13;` or `const int led = 13;`. It is preferable to use the #define directive because the compiler will replace references to these constants with the defined value at compile time thus defined constants don't take up any program memory space on the chip. -> `#define led 13`


### Functions #
- Do not forget to define the mode of the digital input/output before using it with `pinMode()`
- To get time comparison, we can use the `millis()` function that returns the number of milliseconds since the Arduino board began running the current program.

