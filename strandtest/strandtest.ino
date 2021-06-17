#include <Adafruit_NeoPixel.h>

#define LED_COUNT 370
#define LIT_COUNT 370
#define BRIGHTNESS 192
#define LOOP_COUNT 8
#define LOOP_WAIT 500
#define DEBUG false

Adafruit_NeoPixel strips[] = {
  Adafruit_NeoPixel(LED_COUNT, 6, NEO_GRB + NEO_KHZ800),
  //Adafruit_NeoPixel(LED_COUNT, 7, NEO_GRB + NEO_KHZ800),
  //Adafruit_NeoPixel(LED_COUNT, 8, NEO_GRB + NEO_KHZ800),
  //Adafruit_NeoPixel(LED_COUNT, 9, NEO_GRB + NEO_KHZ800),
};

#define NUMSTRIPS (sizeof(strips)/sizeof(strips[0]))

void setup() {
  if (DEBUG) Serial.begin(9600);
  for (int i = 0; i < NUMSTRIPS; i++) {
    strips[i].begin();
    strips[i].clear();
    strips[i].show();
    strips[i].setBrightness(BRIGHTNESS);
  }
  for (int i = 0; i < LOOP_COUNT; i++){
    setStripColor(255,0,0);
    delay(LOOP_WAIT);
    setStripColor(0,255,0);
    delay(LOOP_WAIT);  
    setStripColor(0,0,255);
    delay(LOOP_WAIT);  
    setStripColor(255,255,255);
    delay(LOOP_WAIT);  
  }
}

void loop() {
  rainbow(10);
}

void setStripColor(int r, int g, int b) {
  for (int i = 0; i < NUMSTRIPS; i++) {
    //Adafruit_NeoPixel strip = strips[i];
    for (int j = 0; j < LIT_COUNT; j++) {
      strips[i].setPixelColor(j, strips[i].Color(r, g, b));
    }
    strips[i].show();
  }
}

void rainbow(int wait) {
  for (int i = 0; i < NUMSTRIPS; i++) {
    //Adafruit_NeoPixel strip = strips[i];
    for (long firstPixelHue = 0; firstPixelHue < 5 * 65536; firstPixelHue += 256) {
      for (int j = 0; j < strips[i].numPixels(); j++) {
        int pixelHue = firstPixelHue + (j * 65536L / strips[i].numPixels());
        strips[i].setPixelColor(j, strips[i].gamma32(strips[i].ColorHSV(pixelHue)));
      }
      strips[i].show();
      delay(wait);
    }
  }
}
