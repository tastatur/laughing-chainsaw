#include <Arduino.h>

//How much hall trigger eventss accamulate before calculating RPM
//Or how much time shall past from last calculation - which comes first
#define HALL_EVENTS_MAX 100
#define HALL_EVENTS_DELTA_MS 2000

void updateRpm(int* rpm, unsigned long* rpmTime, byte* hallEventsCounts);