#ifndef SERVER_HPP
#define SERVER_HPP

#include <string>
#include "Sensor.hpp"

using namespace std;

/**
 * @class Server
 * @brief This class represents a server that can receive and process sensor data.
 */
class Server {

/**
 * @struct SensorData
 * @brief This structure represents the data received from a sensor.
 */
struct SensorData {
    string data; ///< The actual data from the sensor.
    string fileName; ///< The name of the file where the data is stored.
    string sensorName; ///< The name of the sensor.
};

private:
    string name; ///< The name of the server.
    bool logActivation = true; ///< Flag to indicate if logging is activated.
    bool consoleActivation = true; ///< Flag to indicate if console output is activated.

public:
    Server(); ///< Default constructor.
    Server(string name); ///< Constructor that sets the server name.
    Server(const Server& other); ///< Copy constructor.

    Server& operator=(const Server& other); ///< Copy assignment operator.

    void operator<<(string data); ///< Overloaded operator to process string data.
    void operator<<(SensorData dataStruct); ///< Overloaded operator to process SensorData.

    ~Server(); ///< Destructor.

    void consoleWrite(string mess); ///< Function to write a message to the console.
    void fileWrite(SensorData dataStruct); ///< Function to write SensorData to a file.
    
    string getName(); ///< Getter for the server name.
    
    void setConsoleActivation(bool consoleActivation); ///< Setter for the consoleActivation flag.
    void setLogActivation(bool logActivation); ///< Setter for the logActivation flag.

    /**
     * @brief Function to receive data from a sensor.
     * @tparam T The type of the sensor data.
     * @param sensorData The actual sensor data.
     * @param fileName The name of the file where the data is stored.
     */
    template <typename T>
    void dataRcv(T sensorData, std::string fileName){
        // Create a new SensorData structure
        SensorData dataSent;

        // Convert the sensor data to a string
        string sensorDataString = to_string(sensorData);

        // Store the sensor data string in the SensorData structure
        dataSent.data = sensorDataString;

        // Store the file name in the SensorData structure
        dataSent.fileName = fileName;

        // Store the sensor name in the SensorData structure
        dataSent.sensorName = fileName;

        // Remove the last 4 characters from the sensor name (presumably the file extension)
        dataSent.sensorName.erase(dataSent.sensorName.end()-10, dataSent.sensorName.end());

        // If logging is activated, send the SensorData structure to the server for processing
        if(logActivation){
            (*this) << dataSent;
        }

        // If console output is activated, send a string containing the sensor name and data to the server for output
        if (consoleActivation){
            if (dataSent.sensorName == "Temperature"){
                (*this) << "[" + dataSent.sensorName + "] " + dataSent.data + " Celsius";
            } else if (dataSent.sensorName == "Humidity"){
                (*this) << "[" + dataSent.sensorName + "] " + dataSent.data + " %";
            } else if (dataSent.sensorName == "Light"){
                (*this) << "[" + dataSent.sensorName + "] " + dataSent.data + " db";
            } else if (dataSent.sensorName == "Sound"){
                (*this) << "[" + dataSent.sensorName + "] " + dataSent.data + " lux";
            }
        }
}};
#endif // SERVER_HPP