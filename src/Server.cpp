#include "Server.hpp"
#include "Sensor.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
using namespace std;

/**
 * @brief Default constructor for the Server class.
 */
Server::Server() {
    this->name = "Server";
}

/**
 * @brief Constructor for the Server class.
 * @param name The name of the server.
 */
Server::Server(string name) {
    this->name = name;
}

/**
 * @brief Copy constructor for the Server class.
 * @param other The Server object to copy.
 */
Server::Server(const Server& other) {
    this->name = other.name;
    this->logActivation = other.logActivation;
    this->consoleActivation = other.consoleActivation;
}

/**
 * @brief Copy assignment operator for the Server class.
 * @param other The Server object to copy.
 * @return A reference to the copied Server object.
 */
Server& Server::operator=(const Server& other) {
    if (this != &other) {
        this->name = other.name;
        this->logActivation = other.logActivation;
        this->consoleActivation = other.consoleActivation;
    }
    return *this;
}

/**
 * @brief Destructor for the Server class.
 */
Server::~Server() {
    this->name = "";
    this->logActivation = false;
    this->consoleActivation = false;
}

/**
 * @brief Writes a message to the console.
 * @param data The message to write to the console.
 */
void Server::consoleWrite(string data) {
    std::cout << "Console out: " << data << std::endl;
}

/**
 * @brief Writes sensor data to a file.
 * @param dataStruct The SensorData object containing the sensor data to write.
 */
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

/**
 * @brief Overloads the << operator for SensorData objects.
 * @param dataStruct The SensorData object to write to a file.
 */
void Server::operator<<(SensorData dataStruct) {
    fileWrite(dataStruct);	
}

/**
 * @brief Overloads the << operator for string objects.
 * @param data The string to write to the console.
 */
void Server::operator<<(string data) {
    consoleWrite(data);
}

/**
 * @brief Sets the activation status of the log.
 * @param logActivation The activation status of the log.
 */
void Server::setLogActivation(bool logActivation) {
    this->logActivation = logActivation;
}

/**
 * @brief Sets the activation status of the console.
 * @param consoleActivation The activation status of the console.
 */
void Server::setConsoleActivation(bool consoleActivation) {
    this->consoleActivation = consoleActivation;
}