
# ESP32-DevKitC & hvcc

This repo demonstrates a single file solution for running [hvcc](https://github.com/enzienaudio/hvcc) sources on the [ESP32-devkitc](https://docs.espressif.com/projects/esp-idf/en/latest/hw-reference/get-started-devkitc.html), inspired by the [Faust ESP32 architecture example](https://faust.grame.fr/doc/tutorials/#dsp-on-the-esp32-with-faust). The hvcc compiler leverages the use of (a subset of) puredata operators on the cheap and fast esp32 uprocessor. The ESP32-devkitc combined with dual PCM5102 CODECs and an 8 port MCP3208 ADC provides a complete and available audio development platform with a very reasonable pricetag. UI provided via 4 buttons, 4 potentiometers and 4 leds.

# Goal

The goal of this development is to realise a generic eurorack module that is based on the ESP32 and programmable via puredata. Each cheap module consists of four control voltage inputs and four audio / cv outputs (all io -5v -> +5v and fully eurorack compatible). All parts are easily obtainable and all software and hardware is open source, so ordering your own set of PCB's is also possible

# Status

25-oct-2020: PCB design ready, gerbers generated and boards ordered.
18-oct-2020: Code cleanup and PCB design ongoing. Current schematic tested and working!

# Installation

- Install Espressif IoT Development Framework 4.1, the official development framework for ESP32.
- Install the hvcc compiler
- Clone this repo

# Hardware setup

Check the Kicad schematics in the schematics folder

# Usage

- Create your puredata patch, using the [supported objects](supportedobjects.md) only. Use `tabread` with a $0-array instead of the `table` object, seems to work better.
- Issue a Issue a `python2.7 hvcc.py input.pd -o ./heavy/` to generate the source files, where input.pd is your puredata patch
- MAC: compile using hvcc and libs and copy to project subdir: `python2.7 hvcc.py esp32_2.pd -p ./Hoclib/ ./Josephlarralde/ ./ParkinsonHashizume/ ./MikeMorenoAudio/ ./Heavylib -o ./heavy/ ; cp ./heavy/c/Heavy_heavy.* ~/Documents/GitHub/esp32-hvcc/main/heavy/`
- WIN: compile and copy: `c:\Python27\python.exe` rest as above, then a `copy /Y heavy\c\Heavy_* c:\Users\Arthur\Github\esp32-hvcc\main\heavy`
- Add all heavy c and cpp sources to /main/CMakeLists.txt (only when adding new objects)
- Run `idf.py -p /dev/tty.SLAB_USBtoUART flash monitor` to compile, upload and monitor the esp32 binary
- MAC: `idf.py -p /dev/cu.usbserial-1A14301 -b 921600 flash monitor`
- WIN: `idf.py -p COM4 -b 921600 flash monitor`
- Enjoy your pd patch!

# Performance

A large and nice sounding puredata patch from "manwithfeathers" on rebeltech.org named ["Fascination IV"](https://www.rebeltech.org/patch-library/patch/Fascination_IV) yields about 60% performance of the ESP32 which looks like a very nice performance / cost ratio!
