# Teensy Spatial Audio Player

This is a simple spatial audio player for the Teensy platform. Teensy 4.0 or 4.1 must be used for this to work. Each Teensy is responsible for playing 2 channels of a spatial audio recording. The recording of these 2 channels must be stored in a stereo wav file named `spatial.wav` with the following format: signed 16 bits PCM. A button must be connected to pin 32 on all the Teensys with a 10k pull down resistor. The button can be powered by on the Teensys. When the button is pressed, `spatial.wav` is played with **perfect synchronicity** on all the Teensy. Perfect synchronicity is ensured by the use of `AudioOutputI2SSync`. Pressing the button makes sure that all i2s transceivers on all Teensys are started at the same time.

The recordings placed in the various versions of `spatial.wav` can be encoded using any spatial audio technique: vbap, WFS, ambisonics, etc.

This work is the fruit of a collaboration between SRST at RISD (RI, USA) and the Emeraude Team at Inria (France).
