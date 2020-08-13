#include "display.h"

void displayString(const String& text, Adafruit_SSD1306& display) {
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(1);
    display.setCursor(0, 0);
    display.cp437();

    display.print(text);

    delay(500);
    display.display();
}

void displayRpms(int* rpms, Adafruit_SSD1306& display) {
    String rpmStr(*rpms);
    rpmStr += " rpm";
    displayString(rpmStr, display);
}

void displayEnvData(float* temperature, float* humidity, Adafruit_SSD1306& display) {
    String envString(*temperature);
    envString += " C\n";
    envString += String(*humidity) + " %";
    displayString(envString, display);
}