#include "Server.hpp"
#include "Sensor.hpp"
#include "Scheduler.hpp"
#include <thread>
#include <chrono>

#define TEMP_TIMER 1000
#define LIGHT_TIMER 2000
#define HUMI_TIMER 1500
#define SOUND_TIMER 2500

void Scheduler::StartDataCollection(bool logActivation, bool consoleActivation) {
    server.setLogActivation(logActivation);
    server.setConsoleActivation(consoleActivation);
    // Utilisez des valeurs adaptées à vos besoins
    StartTimer(tempSensor, TEMP_TIMER);  // Toutes les 1000 ms
    StartTimer(lightSensor, LIGHT_TIMER); // Toutes les 2000 ms
    StartTimer(humiSensor, HUMI_TIMER);  // Toutes les 3000 ms
    StartTimer(soundSensor, SOUND_TIMER); // Toutes les 5000 ms

}

template <typename Sensor>
void Scheduler::StartTimer(Sensor& sensor, int interval) {
    std::thread([this, &sensor, interval]() {
        while (true) {
            genSensorVal(sensor);
            // Collecte de données
            DataCollector(sensor);

            // Pause pour l'intervalle spécifié
            std::this_thread::sleep_for(std::chrono::milliseconds(interval));
        }
    }).detach();
}

template <typename Sensor>
void Scheduler::genSensorVal(Sensor& sensor){
    sensor.aleaGenVal();
}

template <typename Sensor>
void Scheduler::DataCollector(Sensor& sensor) {
    // Génération de la valeur
    server.dataRcv(sensor.getValue(), sensor.getFileName());
}


    