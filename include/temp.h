#include <Arduino.h>
#include <DHT.h>

#define DHTPIN 4

#define DHTTYPE DHT11

void updateTemp(float* temp, float* humidity, DHT& dht);