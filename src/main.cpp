#include "Server.hpp"
#include "Sensor.hpp"
#include "scheduler.hpp"
#include <iostream>
#include <string>
#include <thread> // Include the thread library for thread management
#include <chrono> // Include the chrono library for time management

using namespace std; // Use the standard namespace

int main(int argc, char const *argv[]) {
    if(argc == 4){
        cout << "Server created" << endl;
    }
    srand(time(NULL)); // Initialize the random number generator
    Scheduler scheduler; // Create a schedule object
    scheduler.StartDataCollection(true, true); // Start the data collection

    while (true) {
        // Ton code à exécuter à chaque itération de la boucle

        std::cout << "Appuie sur Entree pour sortir..." << std::endl;

        // Vérifie si l'utilisateur a appuyé sur Entrée
        if (std::cin.get() == '\n') {
            break;  // Quitte la boucle si Entrée est pressée
        }
    }
}