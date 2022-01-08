#define FASTLED_INTERNAL
#include <FastLED.h>
#include <SD.h>
#include <TMRpcm.h>

//LED variables
#define LED_PIN     6
#define NUM_LEDS    12
#define BRIGHTNESS  25

CRGB leds[NUM_LEDS];

//CS Pin
#define SD_ChipSelectPin 10

//Speaker Object
TMRpcm tmrpcm; 

File root;

void setup() {
  
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);

  if (!SD.begin(SD_ChipSelectPin)) {
    return;
  }
  
  tmrpcm.speakerPin = 9;
  root = SD.open("/");
  
  //0-7 Volume Level 
  tmrpcm.setVolume(5);
  tmrpcm.quality(1);
  
  tmrpcm.play("xmas.wav");
  tmrpcm.loop(1);
}

void loop() {

  //Blinking WS2812B LEDs
  leds[0] = CRGB::Red;
  leds[3] = CRGB::Red;
  leds[6] = CRGB::Red;
  leds[9] = CRGB::Red;
  FastLED.show();
  delay(1000);
  leds[0] = CRGB::Black;
  leds[3] = CRGB::Black;
  leds[6] = CRGB::Black;
  leds[9] = CRGB::Black;
  FastLED.show();
  delay(1000);
  leds[1] = CRGB::Green;
  leds[4] = CRGB::Green;
  leds[7] = CRGB::Green;
  leds[10] = CRGB::Green;
  FastLED.show();
  delay(1000);
  leds[1] = CRGB::Black;
  leds[4] = CRGB::Black;
  leds[7] = CRGB::Black;
  leds[10] = CRGB::Black;
  FastLED.show();
  delay(1000);
  leds[2] = CRGB::Blue;
  leds[5] = CRGB::Blue;
  leds[8] = CRGB::Blue;
  leds[11] = CRGB::Blue;
  FastLED.show();
  delay(1000);
  leds[2] = CRGB::Black;
  leds[5] = CRGB::Black;
  leds[8] = CRGB::Black;
  leds[11] = CRGB::Black;
  FastLED.show();
  delay(1000);
}
