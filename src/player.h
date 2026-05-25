#pragma once

#include <string>

struct Limb
{
    std::string name;
    float hp = 100.0f;
    bool functional = true;
};

struct Player
{
    float reactorPower = 100.0f;
    float heat = 0.0f;
    Limb leftArm;
    Limb rightArm;
    Limb leftLeg;
    Limb rightLeg;
    Limb sensorModule;
    Limb reactorShield;
    std::string currRoom = "docking_bay";
};