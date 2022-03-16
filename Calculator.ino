#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define joyX A0
#define joyY A1
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int xMap, yMap, xValue, yValue, x;

void setup() {
  // put your setup code here, to run once:
  pinMode(2, INPUT);
  Serial.begin(115200);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  delay(2000);
  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 32);
  // Display static text
  display.println("Hello, world!");
  display.display(); 
  int cx = 0;
  int cy = 0;
}

void loop() {
  int x;
  bool sci = false;
  xValue = analogRead(joyX);
  yValue = analogRead(joyY);
  Serial.print(xValue);

  //Draw routines
  display.clearDisplay();
  if (sci == false) {
    display.drawLine(0, 32, 128, 32, WHITE);
    display.drawLine(64, 0, 64, 64, WHITE);
    for (int x = -64; x < 64; x++) {
      float equation = 0.1 * (pow(x, 2) -19);
      display.drawPixel(x + 64, (equation * (-1)) + 32, WHITE);
    }
  } else {
    float equation = (54 + 102);
    display.setCursor(0, 32);
    display.setTextColor(WHITE);
    display.setTextSize(1);
    display.println(equation);
  }
  display.display();

}
