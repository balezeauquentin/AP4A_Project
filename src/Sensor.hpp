#ifndef SENSOR_HPP
#define SENSOR_HPP

#include <string>
#include <iostream>

using namespace std;

/**
 * @brief A generic sensor class template.
 * 
 * @tparam T The type of value that the sensor generates.
 */
template <typename T>
class Sensor
{
protected:
    string filename; /**< The name of the file where the sensor data is stored. */
    T value; /**< The current value of the sensor. */
public:
    /**
     * @brief Default constructor for the Sensor class.
     */
    Sensor() : filename(""), value(0) {}

    /**
     * @brief Copy constructor for the Sensor class.
     * 
     * @param other The Sensor object to copy.
     */
    Sensor(const Sensor& other) : filename(other.filename), value(other.value) {}

    /**
     * @brief Destructor for the Sensor class.
     */
    ~Sensor() {
        filename = "";
        value = 0;
    }

    /**
     * @brief Gets the current value of the sensor.
     * 
     * @return The current value of the sensor.
     */
    T getValue(){
        return value;
    }  

    /**
     * @brief Gets the name of the file where the sensor data is stored.
     * 
     * @return The name of the file where the sensor data is stored.
     */
    string getFileName(){
        return filename;
    }

    /**
     * @brief Generates a random value for the sensor.
     * 
     * This is a pure virtual function that must be implemented by derived classes.
     */
    virtual void aleaGenVal() = 0;
};

/**
 * @brief A temperature sensor class that generates float values.
 */
class TemperatureSensor : public Sensor<float>
{
    public :
        /**
         * @brief Default constructor for the TemperatureSensor class.
         */
        TemperatureSensor(){
            filename = "TemperatureSensor.txt";
            value = 0;
        }

        /**
         * @brief Generates a random temperature value between 0.0 and 50.0.
         */
        void aleaGenVal();
};

/**
 * @brief A light sensor class that generates boolean values.
 */
class LightSensor : public Sensor<bool>
{
    public :
        /**
         * @brief Default constructor for the LightSensor class.
         */
        LightSensor(){
            filename = "LightSensor.txt";
            value = 0;
        };

        /**
         * @brief Generates a random light value of either 0 or 1.
         */
        void aleaGenVal();
};

/**
 * @brief A humidity sensor class that generates float values.
 */
class HumiditySensor : public Sensor<float>
{
    public :
        /**
         * @brief Default constructor for the HumiditySensor class.
         */
        HumiditySensor(){
            filename ="HumiditySensor.txt";
            value = 0;
        }

        /**
         * @brief Generates a random humidity value between 0.0 and 100.0.
         */
        void aleaGenVal();
};

/**
 * @brief A sound sensor class that generates integer values.
 */
class SoundSensor : public Sensor<int>
{
    public :
        /**
         * @brief Default constructor for the SoundSensor class.
         */
        SoundSensor(){
            filename = "SoundSensor.txt";
            value = 0;
        }

        /**
         * @brief Generates a random sound value between 1 and 100.
         */
        void aleaGenVal();
};

#endif