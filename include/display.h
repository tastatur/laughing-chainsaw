#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

void displayEnvData(float* temperature, float* humidity, Adafruit_SSD1306& display);
void displayRpms(int* rpms, Adafruit_SSD1306& display);
void displayString(const String& text, Adafruit_SSD1306& display);
