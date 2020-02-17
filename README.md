# ESP32-Audio-Kit & hvcc

This repo demonstrates a single file solution for running [hvcc](https://github.com/enzienaudio/hvcc) sources on the [ESP32-Audio-Kit](https://nl.aliexpress.com/af/ESP32%25252dAudio%25252dKit.html), inspired by the [Faust ESP32 architecture example](https://faust.grame.fr/doc/tutorials/#dsp-on-the-esp32-with-faust). The hvcc compiler leverages the use of (a subset of) puredata operators on the cheap and fast esp32 uprocessor. The ESP32-Audio-Kit provides a complete audio development platform with a very reasonable pricetag.

# Installation

- Install Espressif IoT Development Framework, the official development framework for ESP32.
- Install the hvcc compiler
- Clone this repo
- Create a folder `components` and issue a `git clone https://github.com/olikraus/u8g2.git` there. You might check [nkolban's repo](https://github.com/nkolban/esp32-snippets/tree/master/hardware/displays/U8G2) for more information regarding ESP32 and SSD1306 displays.

# Hardware setup

To be elaborated more upon, but for now ->

OLED Display (SSD1306)

ESP32 pin | SSD1306 pin
--- | ---
15 | CS
23 | DC
12 | RST
14 | CLK (D0)
13 | MOSI (D1)

Rotary Encoder

ESP32 pin | Rotary pin
--- | ---
21 | A
22 | B
GND | C / GND

The jumpers on the ESP32-Audio-kit should be arranged like OFF-OFF-OFF-ON-ON to be able to use the JTAG headers as normal ESP pins 14 12 13 15.

# Usage

- Create your puredata patch, using the [supported objects](supportedobjects.md) only.
- Issue a Issue a `python2.7 hvcc.py input.pd -o ./heavy/` to generate the source files, where input.pd is your puredata patch
- Copy this folder to the main/heavy folder of the esp32-hvcc repo.
- Add all heavy c and cpp sources to /main/CMakeLists.txt
- Run `idf.py -p /dev/tty.SLAB_USBtoUART flash monitor` to compile, upload and monitor the esp32 binary
- Enjoy your pd patch running on the ESP32-Audio-Kit

# Performance

A large and nice sounding puredata patch from "manwithfeathers" on rebeltech.org named ["Fascination IV"](https://www.rebeltech.org/patch-library/patch/Fascination_IV) yields about 60% performance of the ESP32 which looks like a very nice performance / cost ratio!
