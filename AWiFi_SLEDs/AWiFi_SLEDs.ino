#include <Adafruit_NeoPixel.h>
#define NUMSLEDs  2
#define PINSLEDs  10
Adafruit_NeoPixel SLEDs = Adafruit_NeoPixel(NUMSLEDs,PINSLEDs, NEO_RGB + NEO_KHZ800);
void setup() {
  SLEDs.begin(); // This initializes the NeoPixel library.
  SLEDs.show(); // Initialize all SLEDs to 'off'
}
void loop() {
  int val = map(analogRead(A0),0,1023,0,255);
  SLEDs.setPixelColor(0, SLEDs.Color(val, 0, 0)); //Adjust brightness, Color red 
  SLEDs.setPixelColor(1, SLEDs.Color(0, 0, val)); //Adjust brightness, Color blue
  SLEDs.show();
}
