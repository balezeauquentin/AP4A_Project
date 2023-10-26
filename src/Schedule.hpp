#ifndef SCHEDULE_HPP
#define SCHEDULE_HPP

#include "Server.hpp"
#include "Sensor.hpp"

class Schedule {
public:
    void StartDataCollection();

private:
    template <typename Sensor>
    void StartTimer(Sensor& sensor, int interval);
    
    template <typename Sensor>
    void genSensorVal(Sensor& sensor);
    
    template <typename Sensor>
    void DataCollector(Sensor& sensor);

    TemperatureSensor tempSensor;
    LightSensor lightSensor;
    HumiditySensor humiSensor;
    SoundSensor soundSensor;

    Server server;
};

#endif // SCHEDULE_HPP
