#include "Server.hpp"
#include "Sensor.hpp"
#include "Scheduler.hpp"
#include <thread> // Include the thread library for thread management
#include <chrono> // Include the chrono library for time management

#define TEMP_TIMER 1000 // Define the temperature sensor timer interval
#define LIGHT_TIMER 2000 // Define the light sensor timer interval
#define HUMI_TIMER 1500 // Define the humidity sensor timer interval
#define SOUND_TIMER 2500 // Define the sound sensor timer interval

/**
 * @brief Starts the data collection process.
 * 
 * @param logActivation A boolean flag indicating whether to activate logging.
 * @param consoleActivation A boolean flag indicating whether to activate console output.
 */
void Scheduler::StartDataCollection(bool logActivation, bool consoleActivation) {
    server.setLogActivation(logActivation); // Set the logging activation flag
    server.setConsoleActivation(consoleActivation); // Set the console output activation flag
    StartTimer(tempSensor, TEMP_TIMER);  // Start the temperature sensor timer
    StartTimer(lightSensor, LIGHT_TIMER); // Start the light sensor timer
    StartTimer(humiSensor, HUMI_TIMER);  // Start the humidity sensor timer
    StartTimer(soundSensor, SOUND_TIMER); // Start the sound sensor timer
}

/**
 * @brief Starts a timer for a given sensor.
 * 
 * @tparam Sensor The type of sensor to start the timer for.
 * @param sensor The sensor to start the timer for.
 * @param interval The interval at which to collect data.
 */
template <typename Sensor>
void Scheduler::StartTimer(Sensor& sensor, int interval) {
    std::thread([this, &sensor, interval]() {
        while (true) {
            
            genSensorVal(sensor); // Generate a value for the sensor
            DataCollector(sensor); // Collect data from the sensor

            // Pause for the specified interval
            std::this_thread::sleep_for(std::chrono::milliseconds(interval));
        }
    }).detach();
}

/**
 * @brief Generates a random value for a given sensor.
 * 
 * @tparam Sensor The type of sensor to generate a value for.
 * @param sensor The sensor to generate a value for.
 */
template <typename Sensor>
void Scheduler::genSensorVal(Sensor& sensor){
    sensor.aleaGenVal(); // Generate a random value for the sensor
}

/**
 * @brief Collects data from a given sensor.
 * 
 * @tparam Sensor The type of sensor to collect data from.
 * @param sensor The sensor to collect data from.
 */
template <typename Sensor>
void Scheduler::DataCollector(Sensor& sensor) {
    server.dataRcv(sensor.getValue(), sensor.getFileName()); // Send the sensor data to the server
}