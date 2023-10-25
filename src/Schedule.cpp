#include "Server.hpp"
#include "Sensor.hpp"
#include "Schedule.hpp"
#include <thread>
#include <chrono>

void Schedule::StartDataCollection() {
    // Utilisez des valeurs adaptées à vos besoins
    StartTimer(tempSensor, 1000);  // Toutes les 1000 ms
    StartTimer(lightSensor, 2000); // Toutes les 2000 ms
    StartTimer(humiSensor, 1500);  // Toutes les 3000 ms
    StartTimer(soundSensor, 2500); // Toutes les 5000 ms
}

template <typename Sensor>
void Schedule::StartTimer(Sensor& sensor, int interval) {
    std::thread([this, &sensor, interval]() {
        while (true) {
            // Collecte de données
            DataCollector(sensor);

            // Pause pour l'intervalle spécifié
            std::this_thread::sleep_for(std::chrono::milliseconds(interval));
        }
    }).detach();
}

template <typename Sensor>
void Schedule::DataCollector(Sensor& sensor) {
    server.dataRcv(sensor.sendData(), sensor.getFileName());
}


    