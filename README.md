# IoT Ecosystem Simulator for Air Quality Monitoring

## Description

This project provides a simulator dedicated to modeling an IoT ecosystem focused on air quality monitoring. It consists of several essential classes, including the Server, Sensor, and Scheduler classes.

## Operation

The ecosystem operates smoothly following these steps:

1. **Multiple Sensors:** Various sensors, such as those dedicated to light, temperature, humidity, and sound, are integrated into the simulator.

2. **Scheduler:** The Scheduler class plays a central role in gathering data from these sensors. It coordinates the entire process by preparing information for later transmission.

3. **Smart Server:** Equipped with an integrated algorithm, the server supports the orchestration of sensor data transmission. It optimizes communication by organizing data at diverse time intervals, providing increased efficiency.

## Main Classes

### 1. Server

The Server class represents the system's brain, coordinating the reception and transmission of data. Its integrated algorithm ensures intelligent information management for efficient resource utilization.

### 2. Sensor

The Sensor class encapsulates the various types of sensors present in the ecosystem. Each sensor specializes in collecting data related to a specific dimension of air quality.

### 3. Scheduler

The Scheduler class acts as a central scheduler, organizing the collection and preparation of sensor data before transmitting it to the server. It optimizes the process for smooth and efficient communication.

## How to Use

1. **Program Parameters:** To use the project, you have two parameter options.

   ```bash
   program_name true true
   ```
   The first parameter manages writing to log files, and the second manages display in the console.

## How to Compile and Implement the Project
### Compilation on Windows with g++

1. **Prerequisites:** Ensure you have g++ (the C++ compiler) installed on your system.

2. **Download Source Code:** Clone the GitHub repository in your terminal.

   ```bash
   git clone https://github.com/your-username/iot-simulator
   ```

3. **Navigate to Directory:** Go to the project directory.

   ```bash
   cd iot-simulator
   ```

4. **Compilation:** Use g++ to compile the source code.

   ```bash
   g++ -o simulator main.cpp Sensor.cpp Scheduler.cpp Server.cpp
   ```

5. **Execution:** Run the generated program.

   ```bash
   simulator
   ```

### Compilation on Linux with g++

1. **Prerequisites:** Ensure you have g++ installed on your system.

2. **Download Source Code:** Clone the GitHub repository in your terminal.

   ```bash
   git clone https://github.com/your-username/iot-simulator
   ```

3. **Navigate to Directory:** Go to the project directory.

   ```bash
   cd iot-simulator
   ```

4. **Compilation:** Use g++ to compile the source code.

   ```bash
   g++ -o simulator main.cpp Sensor.cpp Scheduler.cpp Server.cpp
   ```

5. **Execution:** Run the generated program.

   ```bash
   ./simulator
   ```

These instructions assume that your source files are named main.cpp, Sensor.cpp, Scheduler.cpp, and Server.cpp. If your file names are different, make sure to adjust them during compilation. Explore the C++ IoT simulator and test its features on your preferred platform!
