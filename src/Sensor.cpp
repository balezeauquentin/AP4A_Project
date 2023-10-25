#include <iostream>
#include <random>
#include "Sensor.hpp"

using namespace std;

Sensor::Sensor() {
    // default constructor implementation
}

Sensor::Sensor(const Sensor& other){
    // copy constructor implementation
}

Sensor::~Sensor() {
    // destructor implementation

}

std::string Sensor::getFileName(){
    return NULL;
}

float TemperatureSensor::sendData(){
    return aleaGenVal();
}

float TemperatureSensor::aleaGenVal(){
    float random = rand() % 70 - 20;
    return random;
}

std::string TemperatureSensor::getFileName(){
    return (*this).filename;
}

bool LightSensor::sendData(){
    return aleaGenVal();
}
bool LightSensor::aleaGenVal(){
    bool random = rand() % 2;
    return random;
}

std::string LightSensor::getFileName(){
    return (*this).filename;
}

float HumiditySensor::sendData(){
    return aleaGenVal();
}

float HumiditySensor::aleaGenVal(){
    float random = rand() % 100 + 1;
    return random;
}

std::string HumiditySensor::getFileName(){
    return (*this).filename;
}
int SoundSensor::sendData(){
    return aleaGenVal();
}

int SoundSensor::aleaGenVal(){
    int random = rand() % 100 + 1; 
    return random;
}

std::string SoundSensor::getFileName(){
    return (*this).filename;
}



