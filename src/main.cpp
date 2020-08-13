#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "tacho.h"
#include "temp.h"
#include "display.h"

/**
 * Pinout
 * D2 (INT0) -> HALL_INPUT (S)
 * D4 -> DHT11 (D)
 * SCL, SDA -> OLED (I2C address 0x3C)
 * D3 (INT1) -> Button
**/

#define HALL_PIN 2
#define BUTTON_PIN 3

volatile byte hallEventsCounts = 0;
int rpm = 0;
unsigned long rpmTime;

DHT dht(DHTPIN, DHTTYPE);
float temperature = 0;
float humidity = 0;

volatile byte displayState = 0;

//Display
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
#define OLED_RESET_PIN 4 
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET_PIN);

void hallTriggered() {
  hallEventsCounts++;
}

void buttonPressed() {
  if (++displayState > 2) {
    displayState = 0;
  }
}

void setup() {
  Serial.begin(9600);
  
  dht.begin();

  pinMode(HALL_PIN, INPUT_PULLUP);
  rpmTime = millis();
  attachInterrupt(digitalPinToInterrupt(HALL_PIN), hallTriggered, FALLING);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

  pinMode(BUTTON_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), buttonPressed, FALLING);
}

void loop() {
  updateRpm(&rpm, &rpmTime, &hallEventsCounts);
  updateTemp(&temperature, &humidity, dht);
  
  if (displayState == 0) {
    displayRpms(&rpm, display);
  } else if (displayState == 1) {
    displayEnvData(&temperature, &humidity, display);
  } else if (displayState == 2) {
    String speedStr(getSpeedInMS(&rpm));
    speedStr += " m/s";
    displayString(speedStr, display);
  }
}