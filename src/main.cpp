#include <Arduino.h>
#include <FastLED.h>
#define MA_BROCHE_BOUTON 39
#define BROCHE_ATOM_FIL_BLANC 32
#define BROCHE_ATOM_FIL_JAUNE 26
#define CANAL_KEY_UNIT 0

//CRGB keyPixel;
CRGB pixelAtom;

#include <M5_PbHub.h>
M5_PbHub myPbHub;


void setup() {
    // Initialiser FastLED pour contrôler le pixel RGB du M5Stack Key Unit
    //FastLED.addLeds< WS2812, BROCHE_ATOM_FIL_JAUNE , GRB >(&keyPixel, 1);
    // Initialiser la touch de key Unit 
    //pinMode( BROCHE_ATOM_FIL_BLANC , INPUT_PULLUP );
    // Initialiser FastLED pour contrôler le pixel RGB du M5Atom
    FastLED.addLeds<WS2812, 27, GRB>(&pixelAtom, 1); 
    pinMode( MA_BROCHE_BOUTON , INPUT );
    Wire.begin();
    myPbHub.begin();
    myPbHub.setPixelCount(CANAL_KEY_UNIT, 1);
}

void loop() {
  //int maLectureBouton = digitalRead( BROCHE_ATOM_FIL_BLANC );
  int maLectureBouton = myPbHub.digitalRead(CANAL_KEY_UNIT );
  int maLectureButton = digitalRead( MA_BROCHE_BOUTON );

  if (maLectureBouton == 1) {
    //keyPixel = CRGB(0, 0, 0);
    myPbHub.setPixelColor( CANAL_KEY_UNIT , 0 , 0,0,0 );
  } else {
    //Fonction random
    int rouge = random(0, 256);
    int vert = random(0, 256);
    //keyPixel = CRGB(rouge,vert,0);
    myPbHub.setPixelColor(CANAL_KEY_UNIT , 0 , rouge,vert,0 );
  }

  if (maLectureButton == 1) {
    pixelAtom = CRGB(0, 0, 0);
  } else {
    pixelAtom = CRGB(255, 25, 0);
  }
  
  FastLED.show();
  delay(20);
}