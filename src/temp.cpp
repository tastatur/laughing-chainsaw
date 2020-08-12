#include "temp.h"

void updateTemp(float* temp, float* humidity, DHT& dht) {
  *humidity = dht.readHumidity();
  *temp = dht.readTemperature();
}