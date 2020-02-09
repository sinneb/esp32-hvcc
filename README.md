# ESP32-Audio-Kit & hvcc

This repo demonstrates a single file solution for running [hvcc](https://github.com/enzienaudio/hvcc) sources on the [ESP32-Audio-Kit](https://nl.aliexpress.com/af/ESP32%25252dAudio%25252dKit.html), inspired by the [Faust ESP32 architecture example](https://faust.grame.fr/doc/tutorials/#dsp-on-the-esp32-with-faust). The hvcc compiler leverages the use of (a subset of) puredata operators on the cheap and fast esp32 uprocessor. The ESP32-Audio-Kit provides a complete audio development platform with a very reasonable pricetag.

# Installation

- Install Espressif IoT Development Framework, the official development framework for ESP32.
- Install the hvcc compiler
- Clone this repo

# Usage

- Create your puredata patch, using the [supported objects](supportedobjects.md) only.
- Issue a Issue a `python2.7 hvcc.py input.pd -o ./heavy/` to generate the source files, where input.pd is your puredata patch
- Copy this folder to the main/heavy folder of the esp32-hvcc repo.
- Add all heavy c and cpp sources to /main/CMakeLists.txt
- Run `idf.py -p /dev/tty.SLAB_USBtoUART flash monitor` to compile, upload and monitor the esp32 binary
- Enjoy your pd patch running on the ESP32-Audio-Kit
