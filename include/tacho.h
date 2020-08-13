#include <Arduino.h>

//How much hall trigger eventss accamulate before calculating RPM
//Or how much time shall past from last calculation - which comes first
#define HALL_EVENTS_MAX 100
#define HALL_EVENTS_DELTA_MS 2000

//Radius of the wheel in cm (up to the magnet mount point)
#define WHEEL_MAGNET_RADIUS 40.0

void updateRpm(int* rpm, unsigned long* rpmTime, volatile byte* hallEventsCounts);
byte getSpeedInMS(int* rpm);