#ifndef SENSOR_HPP
#define SENSOR_HPP

#include <string>
#include <iostream>

using namespace std;

template <typename T>
class Sensor
{
protected:
    string filename;
    T value;
public:
    Sensor() : filename(""), value(0) {}

    Sensor(const Sensor& other) : filename(other.filename), value(other.value) {}

    ~Sensor() {
        filename = "";
        value = 0;
    }
    T getValue(){
        return value;
    }  
    string getFileName(){
        return filename;
    }
    virtual void aleaGenVal() = 0;
};

class TemperatureSensor : public Sensor<float>
{
    public :
        TemperatureSensor(){
            filename = "TemperatureSensor.txt";
            value = 0;
        }
        void aleaGenVal();
};

class LightSensor : public Sensor<bool>
{
    public :
        LightSensor(){
            filename = "LightSensor.txt";
            value = 0;
        };

        void aleaGenVal();
};

class HumiditySensor : public Sensor<float>
{
    public :
        HumiditySensor(){
            filename ="HumiditySensor.txt";
            value = 0;
        }
        void aleaGenVal();
};

class SoundSensor : public Sensor<int>
{
    public :
        SoundSensor(){
            filename = "SoundSensor.txt";
            value = 0;
        }
        void aleaGenVal();
};

#endif