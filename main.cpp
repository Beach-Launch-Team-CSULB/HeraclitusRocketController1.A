// Pseudocode for the 'Main' section of the rocket event-handling system
#include <iostream>
#include <array>
#include <unordered_map>
#include "Rocket.h"

class Main {
    EventManager eventManager;
    Rocket rocket; 

    void processCommand() {
        // If a command is valid and no other command is currently executing
        if (commandIsValid() && !isExecuting()) {
            // Execute the command
            executeCommand();
            // Confirm update status
            confirmUpdateStatus();
        }
    }

    void handleSensorData() {
        // Check if flag for new sensor data is set
        if (isNewSensorDataAvailable()) {
            // Execute sensor data collection
            Event sensorDataEvent = collectSensorData();
            // Return sensor data
            returnSensorData(sensorDataEvent);
        }
    }

    void monitorPressure() {
        // Poll the LOX pressure
        int loxPressure = pollLoxPressure();
        // If LOX pressure is too high
        if (loxPressureTooHigh(loxPressure)) {
            // Execute vent command
            executeVentCommand();
            // Confirm update status
            confirmUpdateStatus();
        }
    }

    // Helper methods
    bool commandIsValid(int idx) {
        if (validCommandTable[rocket.curState][idx] == 1)
            return true;
        else {
            return false;
        }
    }

    bool isExecuting() {
        // Implementation depends on how execution status is tracked
        if (rocket.flag == 0){
            return true;
        }
        else { 
            return false;
        } 
    }

    Event collectSensorData() {
        int sensorReading = rocket.sensorRead();
        Event sensorDataEvent(sensorReading); 
        return sensorDataEvent;
    }

    void returnSensorData(Event& event) {
        // Implementation depends on how sensor data is returned
    }

    int pollLoxPressure() {
        const int loxPressureSensorId = /* appropriate sensor ID */;
        int loxPressure = rocket.sensorRead(loxPressureSensorId);
        return loxPressure;
    }

    bool loxPressureTooHigh(int loxPressure) {
        const int pressureThreshold = /* define your threshold */;
        return pressure > pressureThreshold;
    }

    void executeVentCommand() {
        // Implementation depends on how the vent command is executed
        rocket.toggleValve(ventID, true);
    }

    void confirmUpdateStatus() {
        // if message is received from rocket, then we give thumbs up
    }

};

// Main program loop
int main() {
    Main mainSystem;

    static std::unordered_map<std::string, std::array<int, 12>> validCommandTable;
    validCommandTable["Passive"] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    // Fill out Command Table for final implementation

    while (true) {
        // Process incoming commands
        mainSystem.processCommand();

        // Handle sensor data if available
        mainSystem.handleSensorData();

        // Monitor and control LOX pressure
        mainSystem.monitorPressure();

    }
}