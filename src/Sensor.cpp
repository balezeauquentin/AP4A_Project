#include <iostream>
#include <random>
#include "Sensor.hpp"

using namespace std;


void TemperatureSensor::aleaGenVal(){
    float random = rand() % (7000 - 2000)/100.0;
    value = random;
}


void LightSensor::aleaGenVal(){
    bool random = rand() % 2;
    value = random;
}


void HumiditySensor::aleaGenVal(){
    float random = rand() % (10000 - 100)/100.0;
    value = random;
}


void SoundSensor::aleaGenVal(){
    int random = rand() % 100 + 1; 
    value = random;
}




