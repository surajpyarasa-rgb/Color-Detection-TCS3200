// This code works with GY-31 TCS3200 TCS230 color sensor module
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// OLED setup
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
#define OLED_RESET    -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// TCS3200 pins
#define s0 8
#define s1 9
#define s2 10
#define s3 11
#define out 12

int Red = 0, Blue = 0, Green = 0;

void setup() {
  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);
  pinMode(out, INPUT);

  Serial.begin(9600);

  // Frequency scaling 100% for accurate readings
  digitalWrite(s0, HIGH);
  digitalWrite(s1, HIGH);

  // Initialize OLED
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  display.clearDisplay();
  display.setTextSize(2);      // Larger text
  display.setTextColor(SSD1306_WHITE);
}

void loop() {
  GetColors();  // Read RGB values

  String colorName = "Unknown";

  if (Red <= 15 && Green <= 15 && Blue <= 15)
    colorName = "White";
  else if (Red < Blue && Red <= Green && Red < 23)
    colorName = "Red";
  else if (Blue < Green && Blue < Red && Blue < 20)
    colorName = "Blue";
  else if (Green < Red && Green - Blue <= 8)
    colorName = "Green";

  // Print only detected color to Serial
  Serial.println(colorName);

  // Display only detected color on OLED
  display.clearDisplay();
  display.setCursor(0, 8);  // adjust vertical position for larger text
  display.println(colorName);
  display.display();

  delay(2000);  // 2s delay
}

void GetColors() {
  // Select RED photodiodes
  digitalWrite(s2, LOW);
  digitalWrite(s3, LOW);
  Red = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
  delay(20);

  // Select BLUE photodiodes
  digitalWrite(s3, HIGH);
  Blue = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
  delay(20);

  // Select GREEN photodiodes
  digitalWrite(s2, HIGH);
  Green = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
  delay(20);
}
