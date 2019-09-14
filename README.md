# LedStreamers
Arduino/ESP32 to receive BenTo compatible UDP led streaming and other fun stuff

# Installation

This version is focusing on ESP32 but it should be fairly easy to adapt it to other Arduino compatible boards

- Install Arduino IDE : https://www.arduino.cc/en/main/software
- Add ESP32 board definition : https://github.com/espressif/arduino-esp32/blob/master/docs/arduino-ide/boards_manager.md
- Add FastLED library from the library manager in Arduino IDE (Sketch > Include library > Manage Libraries... then search for FastLED and install it)
- Add OSC library (same as for FastLED, be sure to install the one called exactly "OSC" by Adrian Freed and Yotam Mann !)
- If you want to use Capacitive touch sensing, add the QTouch library from Seeed

Then you just have to choose your board and upload.

# Setup the pins

The pins used for the LEDs are defined in FastLEDDefs.h. It's currently set up for my own projects but you can just change the LED data pin, LEDStrip type and number of LEDs there.
Currently it will output the LED data on 2 differents pins, you can change that in LEDStripManager.h, in the init() function.
