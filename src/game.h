#pragma once

#include <string>
#include <vector>

struct GameState 
{
    std::vector<std::string> terminalLines;
    std::string currRoom = "Docking Bay";
    std::string scaleMode = "standard";
};