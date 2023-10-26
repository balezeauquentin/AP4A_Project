#include "Server.hpp"
#include "Sensor.hpp"
#include "schedule.hpp"
#include <iostream>
#include <string>
#include <thread> // Include the thread library for thread management
#include <chrono> // Include the chrono library for time management

using namespace std; // Use the standard namespace

int main(int argc, char const *argv[]) {
    srand(time(NULL)); // Initialize the random number generator
    Schedule schedule; // Create a schedule object
    schedule.StartDataCollection(); // Start the data collection
    while (true) {
        // Wait for the user to press enter
        string input;
        getline(cin, input);
        if (input == "exit") {
            break;
        }
    }
}