#include <Adafruit_NeoPixel.h>

#define LED_COUNT 360
#define LIT_COUNT 360
#define BRIGHTNESS 50
#define DEBUG true

Adafruit_NeoPixel strips[] = {
  Adafruit_NeoPixel(LED_COUNT, 2, NEO_GRB + NEO_KHZ800),
  Adafruit_NeoPixel(LED_COUNT, 3, NEO_GRB + NEO_KHZ800),
  Adafruit_NeoPixel(LED_COUNT, 4, NEO_GRB + NEO_KHZ800),
  Adafruit_NeoPixel(LED_COUNT, 5, NEO_GRB + NEO_KHZ800),
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
}

void loop() {
  turnOn();
  if (DEBUG) Serial.println("Turn on!");
  delay(2000);
  turnOff();
  if (DEBUG) Serial.println("Turn off!");
  delay(2000);
}

void turnOn(){
  for (int i = 0; i < NUMSTRIPS; i++) {
    for (int j = 0; j < LIT_COUNT; j++) {
      strips[i].setPixelColor(j, strips[i].Color(255, 0, 0));
    }
    strips[i].show();
  }
}


void turnOff(){
  for (int i = 0; i < NUMSTRIPS; i++) {
    for (int j = 0; j < LIT_COUNT; j++) {
      strips[i].setPixelColor(j, strips[i].Color(0, 0, 255));
    }
    strips[i].show();
  }
}
