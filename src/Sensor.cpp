#include <iostream>
#include <random>
#include "Sensor.hpp"

using namespace std;


void TemperatureSensor::aleaGenVal(){
        random_device rd;
        mt19937 gen(rd());
        uniform_real_distribution<float> dis(0.0, 50.0);
        value = dis(gen);
}


void LightSensor::aleaGenVal(){
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> dis(0, 1);
        value = dis(gen);
}


void HumiditySensor::aleaGenVal(){
        random_device rd;
        mt19937 gen(rd());
        uniform_real_distribution<float> dis(0.0, 100.0);
        value = dis(gen);
}


void SoundSensor::aleaGenVal(){
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> dis(1, 100);
        value = dis(gen);
}




