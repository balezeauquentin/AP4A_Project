#ifndef SCHEDULE_HPP
#define SCHEDULE_HPP

#include "Server.hpp"
#include "Sensor.hpp"

/**
 * @brief The Scheduler class manages the data collection process.
 */
class Scheduler {
public:
    /**
     * @brief Starts the data collection process.
     * 
     * @param logActivation A boolean flag indicating whether to activate logging.
     * @param consoleActivation A boolean flag indicating whether to activate console output.
     */
    void StartDataCollection(bool logActivation, bool consoleActivation);

private:
    /**
     * @brief Starts a timer for a given sensor.
     * 
     * @tparam Sensor The type of sensor to start the timer for.
     * @param sensor The sensor to start the timer for.
     * @param interval The interval at which to collect data.
     */
    template <typename Sensor>
    void StartTimer(Sensor& sensor, int interval);
    
    /**
     * @brief Generates a random value for a given sensor.
     * 
     * @tparam Sensor The type of sensor to generate a value for.
     * @param sensor The sensor to generate a value for.
     */
    template <typename Sensor>
    void genSensorVal(Sensor& sensor);
    
    /**
     * @brief Collects data from a given sensor.
     * 
     * @tparam Sensor The type of sensor to collect data from.
     * @param sensor The sensor to collect data from.
     */
    template <typename Sensor>
    void DataCollector(Sensor& sensor);

    TemperatureSensor tempSensor; // The temperature sensor object
    LightSensor lightSensor; // The light sensor object
    HumiditySensor humiSensor; // The humidity sensor object
    SoundSensor soundSensor; // The sound sensor object
    
    Server server; // The server object
};

#endif // SCHEDULE_HPP