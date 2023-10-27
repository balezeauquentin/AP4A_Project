#ifndef SERVER_HPP
#define SERVER_HPP

#include <string>
#include "Sensor.hpp"

using namespace std;

class Server {

struct SensorData {
    string data;
    string fileName;
    string sensorName;
};

private:
    // add any private member functions or variables here
    string name;
    bool logActivation = true;
    bool consoleActivation = true;
public:
    Server(); // default constructor
    Server(string name); // constructor
    Server(const Server& other); // copy constructor
    Server& operator=(const Server& other); // copy assignment operator
    void operator<<(string data);
    void operator<<(SensorData dataStruct);
    ~Server(); // destructor
    void consoleWrite(string mess);
    void fileWrite(SensorData dataStruct);
    string getName();
    void setConsoleActivation(bool consoleActivation);
    void setLogActivation(bool logActivation);
    template <typename T>
    void dataRcv(T sensorData, std::string fileName){
        SensorData dataSent;

        string sensorDataString = to_string(sensorData);
        dataSent.data = sensorDataString;
        dataSent.fileName = fileName;
        dataSent.sensorName = fileName;
        dataSent.sensorName.erase(dataSent.sensorName.end()-4, dataSent.sensorName.end());
        if(logActivation){
            (*this) << dataSent;
        }
        if (consoleActivation){
            (*this) << dataSent.sensorName + ", "+ sensorDataString;
    }

}
};

#endif // SERVER_HPP