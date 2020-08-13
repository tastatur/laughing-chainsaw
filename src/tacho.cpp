#include "tacho.h"

void updateRpm(int* rpm, unsigned long* rpmTime, volatile byte* hallEventsCounts) {
    unsigned long timeDiff = (millis() - *rpmTime);
    if (timeDiff >= HALL_EVENTS_DELTA_MS || *hallEventsCounts >= HALL_EVENTS_MAX) {
        double newRpm = ((double)*hallEventsCounts * 1000.0 * 60.0) / (double)timeDiff;
        *rpmTime = millis();
        *hallEventsCounts = 0;
        
        *rpm = round(newRpm);
    } 
}

byte getSpeedInMS(int* rpm) {
    return round((2*PI/60.0) * WHEEL_MAGNET_RADIUS * 0.01 * *rpm);
}