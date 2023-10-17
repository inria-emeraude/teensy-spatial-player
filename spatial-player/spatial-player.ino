#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>
#include "output_i2s_sync.h"

AudioPlaySdWav playWav1;
AudioOutputI2SSync out;
AudioControlSGTL5000 audioShield;
AudioConnection patchCord0(playWav1,0,out,0);
AudioConnection patchCord1(playWav1,1,out,1);

bool once = false;

void setup() {  
  AudioMemory(2);
  if (!(SD.begin(BUILTIN_SDCARD))) {
    while (1) {
      delay(500);
    }
  }

  pinMode(32,INPUT);
}

void playFile(const char *filename)
{
  playWav1.play(filename);
  delay(25);
  while (playWav1.isPlaying()) {
  }
  playFile(filename);
}

void loop() {
  if(digitalRead(32)){
    if(!once){
      once = true;
      out.begin();
      delay(100);
      audioShield.enable();
      audioShield.volume(0.5);
      delay(100);
      playFile("spatial.wav");
    }
  }
  else{
    once = false;
  }
}
