#pragma once

#include <string>
#include <vector>
#include "world.h"
#include "player.h"

struct GameState 
{
    std::vector<std::string> terminalLines;
    std::string scaleMode = "standard";
    World world;
    Player player;
};