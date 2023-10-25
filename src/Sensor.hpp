#ifndef SENSOR_HPP
#define SENSOR_HPP

#include <string>

using namespace std;
class Sensor
{
private:

public:
    Sensor();
    Sensor(const Sensor& other);
    virtual ~Sensor();
    template <typename T> 
    T sendData(){
        return 0;
    }
    template <typename T>
    T aleaGenVal(){
        return 0;
    }
    virtual std::string getFileName();
};

class TemperatureSensor : protected Sensor
{
    private :
        std::string filename = "TempSensor.txt";

    public :
        float sendData();
        float aleaGenVal();
        std::string getFileName();
};

class LightSensor : protected Sensor
{
    private :
        std::string filename = "LightSensor.txt";
    public :
        bool sendData();
        bool aleaGenVal();
        std::string getFileName();
};

class HumiditySensor : private Sensor
{
    private :
        std::string filename = "HumiditySensor.txt";
    public :
        float sendData();
        float aleaGenVal();
        std::string getFileName();
};

class SoundSensor : private Sensor
{
    private :
        std::string filename = "SoundSensor.txt";
    public :
        int sendData();
        int aleaGenVal();
        std::string getFileName();
};

#endif