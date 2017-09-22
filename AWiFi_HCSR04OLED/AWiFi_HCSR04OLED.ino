#include <Wire.h>                   // Include library
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define OLED_RESET -1
Adafruit_SSD1306 OLED(OLED_RESET);  // New object OLED
long distance = 0;
#define trigPin D5
#define echoPin D6
void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  OLED.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  // initialize with the I2C addr 0x3C (for the 128x64)
}

void loop()
{
  distance = read_hc_sr04();              // Read data from HC-SR04
  if (distance <= 200 && distance >= 0)   // Set distance display range
  {
    OLED.clearDisplay();               //Clear display
    OLED.setTextColor(WHITE);          //Set text color
    OLED.setCursor(15, 0);              //Set display start position
    OLED.setTextSize(2);               //Set text size x1
    OLED.println("HC-SR04");          //Type message
    OLED.setCursor(15, 35);            //Set display postion
    OLED.setTextSize(3);               //Set text size x2
    OLED.println(String(distance)+" Cm");  // Show result value
    OLED.display();                    //Enable display
  }
}
long  read_hc_sr04()                      // Read the distance value for HC-SR04
{
  long duration, distance;
  digitalWrite(trigPin, LOW);             // Trig signal sending
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);      // Echo signal receiving
  distance = (duration / 2) / 29.1;       // Calculate the distance result
  return  distance;                       // Return value
}

