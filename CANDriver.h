// 4/8/2024

#ifndef CANDRIVER_H
#define CANDRIVER_H

#include "Rocket.h"
#include <FlexCAN_T4.h>
#include <iostream>
#include <vector>
#include <cstdint>


class CANDriver 
{
    private:
        FlexCAN_T4<CAN2, RX_SIZE_16, TX_SIZE_16> Can0 = FlexCAN_T4<CAN2, RX_SIZE_16, TX_SIZE_16>();
        std::vector<uint8_t> commands;
        
    public:
        
        // If we are able to set up the .begin and all that here within the CANDriver.cpp - that would be cool.
        // Otherwise it would probably need to happen in main.
        CANDriver();
        uint32_t readMessage();
        //^ .push_back() into commands vector

        // Would be RocketState rocketState instead of uint8_t rocketState.
        void sendStateReport(int time, uint8_t rocketState, Rocket node, bool Prop);
        void sendSensorData(int sensorID, float sensorData1, float sensorData2, float SensorData3, float SensorData4);
        void sendTiming(uint32_t getTimeID);
        void sendSensorCalibration(bool isM, uint8_t sensorID, float sensorVal);

        void ping(bool prop);

        void sendOperatorMessage(char zero, char one, bool prop);
};

#endif