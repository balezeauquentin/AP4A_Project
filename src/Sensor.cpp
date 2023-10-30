#include <iostream>
#include <random>
#include "Sensor.hpp"

using namespace std;

/**
 * @brief Generates a random temperature value between 0.0 and 50.0.
 */
void TemperatureSensor::aleaGenVal(){
        random_device rd; // Create a random device to seed the generator
        mt19937 gen(rd()); // Create a Mersenne Twister engine with the random device as the seed
        uniform_real_distribution<float> dis(0.0, 50.0); // Create a uniform distribution between 0.0 and 50.0
        value = dis(gen); // Generate a random value using the distribution and store it in the value member variable
}

/**
 * @brief Generates a random light value of either 0 or 1.
 */
void LightSensor::aleaGenVal(){
        random_device rd; // Create a random device to seed the generator
        mt19937 gen(rd()); // Create a Mersenne Twister engine with the random device as the seed
        uniform_int_distribution<int> dis(0, 1); // Create a uniform distribution between 0 and 1
        value = dis(gen); // Generate a random value using the distribution and store it in the value member variable
}

/**
 * @brief Generates a random humidity value between 0.0 and 100.0.
 */
void HumiditySensor::aleaGenVal(){
        random_device rd; // Create a random device to seed the generator
        mt19937 gen(rd()); // Create a Mersenne Twister engine with the random device as the seed
        uniform_real_distribution<float> dis(0.0, 100.0); // Create a uniform distribution between 0.0 and 100.0
        value = dis(gen); // Generate a random value using the distribution and store it in the value member variable
}

/**
 * @brief Generates a random sound value between 1 and 100.
 */
void SoundSensor::aleaGenVal(){
        random_device rd; // Create a random device to seed the generator
        mt19937 gen(rd()); // Create a Mersenne Twister engine with the random device as the seed
        uniform_int_distribution<int> dis(1, 100); // Create a uniform distribution between 1 and 100
        value = dis(gen); // Generate a random value using the distribution and store it in the value member variable
}