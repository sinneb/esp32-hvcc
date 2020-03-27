# ESP32-DevKitC & hvcc

This repo demonstrates a single file solution for running [hvcc](https://github.com/enzienaudio/hvcc) sources on the [ESP32-devkitc](https://docs.espressif.com/projects/esp-idf/en/latest/hw-reference/get-started-devkitc.html), inspired by the [Faust ESP32 architecture example](https://faust.grame.fr/doc/tutorials/#dsp-on-the-esp32-with-faust). The hvcc compiler leverages the use of (a subset of) puredata operators on the cheap and fast esp32 uprocessor. The ESP32-devkitc combined with dual WM8731 CODECs and an 8 port MCP3208 ADC provides a complete and available audio development platform with a very reasonable pricetag. UI provided via a SSD1306 display, some buttons and a rotary encoder.

# Goal

The goal of this development is to realise a generic eurorack module, based on the ESP32 and programmable via puredata. Each cheap module consists of four control voltage inputs, four audio inputs, and four audio / cv outputs (all io -5v -> +5v and fully eurorack compatible). An OLED-display, some buttons and a rotaty encoder enable user interaction.

Total cost breakdown

Hardware | cost
--- | ---
ESP32 devkitc | &euro; 9
WM8731 | &euro; 3 (>10)
MCP3208 | &euro; 3,13
SSD1306 | &euro; 1,79
Encoder | &euro; 1,00
pcb | &euro; 3,00
power / opamps / various | &euro; 6,00

total ~ &euro; 25,00

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
