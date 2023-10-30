#include "Server.hpp"
#include "Sensor.hpp"
#include "scheduler.hpp"
#include <iostream>
#include <string>
#include <thread> // Include the thread library for thread management
#include <chrono> // Include the chrono library for time management

using namespace std; // Use the standard namespace

/**
 * @brief The main function of the program.
 * 
 * @param argc The number of command line arguments.
 * @param argv The command line arguments.
 * @return int The exit code of the program.
 */
int main(int argc, char const *argv[]) {

    bool logActivation = false; // Initialize the log activation flag to false
    bool consoleActivation = false; // Initialize the console activation flag to false
    
    for (int i = 1; i < argc; i++) { // Loop through the command line arguments
        string arg = argv[i]; // Get the current argument
        if (arg == "-l" || arg == "--log") { // Check if the argument is for logging
            logActivation = true; // Activate logging
        } else if (arg == "-c" || arg == "--console") { // Check if the argument is for console output
            consoleActivation = true; // Activate console output
        } else if(arg == "-v" || arg == "--version"){ // Check if the argument is for displaying the version number
            cout << "Version 1.21" << endl; // Display the version number
            return 0; // Exit the program
        } else if (arg == "-h" || arg == "--help") { // Check if the argument is for displaying the help message
            cout << "Utilisation : programme [option]\n\n"
                << "Options : -h, --help      Affiche ce message d'aide et quitte le programme.\n"
                << "          -v, --version   Affiche la version du programme et quitte le programme.\n"
                << "          -l, --log       Active l'affichage des messages dans les logs.\n"
                << "          -c, --console   Active l'affichage dans la console." << endl; // Display the help message
            return 0; // Exit the program
        }
    }

    srand(time(NULL)); // Initialize the random number generator
    Scheduler scheduler; // Create a schedule object
    scheduler.StartDataCollection(logActivation, consoleActivation); // Start the data collection

    while (true) {
        // Code to execute at each iteration of the loop
        // Display a message to the console
        std::cout << "Appuie sur Entree pour sortir..." << std::endl;
        
        // Check if the user has pressed Enter
        if (std::cin.get() == '\n') {
            break;  // Quit the loop if Enter is pressed
        }
    }
    return 0; // Exit the program
}