#ifndef ROCKET_H
#define ROCKET_H 

#include <Arduino.h>
#include <VehicleState.h>
#include <IntervalTimer.h>

class Rocket{ 

    public:
        // Internal Variables 
        VehicleState state;
        bool executingCommand;

        // Output 
        int sensorRead(int);
        bool ignitionRead(int);
        bool valveRead(int);
        
        // Commands 
        bool setIgnitionOn(int);
        bool setValveOn(int);

        // Execution Check
        bool getExecuting();
    
    private:

        // Object creation 
        bool createValves(int);
        bool createIgniters(int);
        bool createSensors(int,int);
        
};

#endif
