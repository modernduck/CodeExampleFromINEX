#include "DHT.h"                    //Include DHT library
#include <Wire.h>                   // Include library
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define OLED_RESET -1
Adafruit_SSD1306 OLED(OLED_RESET);  // New object OLED

#define DHTTYPE DHT11
#define DHTPIN  D4
DHT dht (DHTPIN, DHTTYPE, 15);
void setup()   {
  Serial.begin(9600);
  OLED.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  // initialize with the I2C addr 0x3C (for the 128x64)
}
void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  } else {
    OLED.clearDisplay();               //Clear display
    OLED.setTextColor(WHITE);          //Set text color
    OLED.setCursor(0, 0);              //Set display start position
    OLED.setTextSize(2);               //Set text size x2
    OLED.println("H: " + String(h, 0) + " %"); // Show result value
    OLED.setCursor(0, 30);            //Set display postion
    OLED.print("T: " + String(t, 0) + " ");
    OLED.write(247);
    OLED.print("C");
    OLED.display();                    //Enable display
  }

}

