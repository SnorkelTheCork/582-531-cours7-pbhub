#include <Arduino.h>
#include <FastLED.h>
#define MA_BROCHE_BOUTON 39
#define BROCHE_ATOM_FIL_BLANC 32
#define BROCHE_ATOM_FIL_JAUNE 26

CRGB keyPixel;
CRGB pixelAtom;

void setup() {
    // Initialiser FastLED pour contrôler le pixel RGB du M5Stack Key Unit
    FastLED.addLeds< WS2812, BROCHE_ATOM_FIL_JAUNE , GRB >(&keyPixel, 1);
    // Initialiser la touch de key Unit 
    pinMode( BROCHE_ATOM_FIL_BLANC , INPUT_PULLUP );
    // Initialiser FastLED pour contrôler le pixel RGB du M5Atom
    FastLED.addLeds<WS2812, 27, GRB>(&pixelAtom, 1); 
    pinMode( MA_BROCHE_BOUTON , INPUT );

}

void loop() {
  int maLectureBouton = digitalRead( BROCHE_ATOM_FIL_BLANC );
  int maLectureButton = digitalRead( MA_BROCHE_BOUTON );

  if (maLectureBouton == 1) {
    keyPixel = CRGB(0, 0, 0);
    FastLED.show();
  } else {
    keyPixel = CRGB(175,255,0);
    FastLED.show();
  }

  if (maLectureButton == 1) {
    pixelAtom = CRGB(0, 0, 0);
    FastLED.show();
  } else {
    pixelAtom = CRGB(255, 25, 0);
    FastLED.show();
  }
  
  delay(20);
}