#ifndef SENSOR_HPP
#define SENSOR_HPP

#include <string>

using namespace std;

template <typename T>
class Sensor
{
public:
    string filename;
    T value;
public:
    Sensor() : filename(""), value(0) {}

    Sensor(const Sensor& other) : filename(other.filename), value(other.value) {}

    ~Sensor() {
        filename = "";
        value = 0;
    }
    T sendData(){
        return value;
    }  
    string getFileName(){
        return filename;
    }
    virtual void aleaGenVal() = 0;
};

class TemperatureSensor : public Sensor<float>
{
    private :

    public :
        TemperatureSensor(){
            filename = "TemperatureSensor.txt";
            value = 0;
        }
        void aleaGenVal();
};

class LightSensor : public Sensor<bool>
{
    private :

    public :
        LightSensor(){
            filename = "LifhtSensor.txt";
            value = 0;
        };

        void aleaGenVal();
};

class HumiditySensor : public Sensor<float>
{
    private :


    public :
        HumiditySensor(){
            filename ="HumiditySensor.txt";
            value = 0;
        }
        void aleaGenVal();
};

class SoundSensor : public Sensor<int>
{
    private :

    public :
        SoundSensor(){
            filename = "SoundSensor.txt";
            value = 0;
        }
        void aleaGenVal();
};

#endif