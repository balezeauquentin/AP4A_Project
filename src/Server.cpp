#include "Server.hpp"
#include "Sensor.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
using namespace std;

Server::Server() {
    
}

Server::Server(string name) {
    this->name = name;
}

Server::Server(const Server& other) {
    // copy constructor implementation
}

Server& Server::operator=(const Server& other) {
    if (this != &other) {
        // copy assignment operator implementation
    }
    return *this;
}

Server::~Server() {
    // destructor implementation
}

void Server::consoleWrite(string data) {
    std::cout << "Console out: " << data << std::endl;
}

void Server::fileWrite(SensorData dataStruct) {
    string programPath = std::filesystem::current_path().string(); // Get the current path of the program
    programPath.erase(programPath.end()-4, programPath.end()); // Remove /src from the path
    string filePath = programPath + "\\output\\"; // Define the file path
    ofstream file; // Create a file stream

    // Open the file in append mode
    file.open(filePath + dataStruct.fileName, std::ios::app);
    if (file.is_open()) { // If the file is open
        // Write the sensor name and data to the file
        file << dataStruct.sensorName << ", " << dataStruct.data << std::endl;
        file.close(); // Close the file
    }
}

void Server::operator<<(SensorData dataStruct) {
    fileWrite(dataStruct);	
}

// overload the << operator for SensorData
void Server::operator<<(string data) {
    consoleWrite(data);
}

void Server::setLogActivation(bool logActivation) {
    this->logActivation = logActivation;
}

void Server::setConsoleActivation(bool consoleActivation) {
    this->consoleActivation = consoleActivation;
}
