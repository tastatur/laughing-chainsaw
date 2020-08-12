#include "tacho.h"

void updateRpm(int* rpm, unsigned long* rpmTime, byte* hallEventsCounts) {
    unsigned long timeDiff = (millis() - *rpmTime);
    if (timeDiff >= HALL_EVENTS_DELTA_MS || *hallEventsCounts >= HALL_EVENTS_MAX) {
        double newRpm = ((double)*hallEventsCounts * 1000.0 * 60.0) / (double)timeDiff;
        *rpmTime = millis();
        *hallEventsCounts = 0;
        
        *rpm = round(newRpm);
    } 
}