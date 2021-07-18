#include <Adafruit_NeoPixel.h>

#define LED_PIN     6
#define LED_COUNT   384
#define BRIGHTNESS  92
#define WAIT        1

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRBW + NEO_KHZ800);

void setup() {
  strip.begin(); 
  strip.show();
  strip.setBrightness(BRIGHTNESS);
}

void loop() {
  colorWipe(strip.Color(  255,  0,    0,    0),   WAIT);
  colorWipe(strip.Color(  0,    255,  0,    0),   WAIT);
  colorWipe(strip.Color(  0,    0,    255,  0),   WAIT);
  colorWipe(strip.Color(  255,  255,  255,  0),   WAIT);
  colorWipe(strip.Color(  255,  0,    0,    0),   WAIT);
  colorWipe(strip.Color(  0,    255,  0,    0),   WAIT);
  colorWipe(strip.Color(  0,    0,    255,  0),   WAIT);
  colorWipe(strip.Color(  0,    0,    0,    255), WAIT);
}

void colorWipe(uint32_t color, int wait) {
  for(int i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, color);
    strip.show(); 
    delay(wait);
  }
}

void rainbowFade(int wait, int rainbowLoops, int whiteLoops) {
  int fadeVal=0, fadeMax=100;
  for(uint32_t firstPixelHue = 0; firstPixelHue < rainbowLoops*65536;
    firstPixelHue += 256) {

    for(int i=0; i<strip.numPixels(); i++) {
      uint32_t pixelHue = firstPixelHue + (i * 65536L / strip.numPixels());
      strip.setPixelColor(i, strip.gamma32(strip.ColorHSV(pixelHue, 255,
        255 * fadeVal / fadeMax)));
    }

    strip.show();
    delay(wait);

    if(firstPixelHue < 65536) {                              // First loop,
      if(fadeVal < fadeMax) fadeVal++;                       // fade in
    } else if(firstPixelHue >= ((rainbowLoops-1) * 65536)) { // Last loop,
      if(fadeVal > 0) fadeVal--;                             // fade out
    } else {
      fadeVal = fadeMax; // Interim loop, make sure fade is at max
    }
  }

  delay(500);
}
