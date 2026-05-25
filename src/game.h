#pragma once

#include <string>
#include <vector>
#include "world.h"

struct GameState 
{
    std::vector<std::string> terminalLines;
    std::string currRoom = "docking_bay";
    std::string scaleMode = "standard";
    World world;
};