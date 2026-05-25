#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <functional>

#include "game.h"

using CommandFunction = std::function<void( const std::vector<std::string>&, GameState& )>;

class CommandSystem
{
public:

    std::unordered_map<std::string, CommandFunction> commands;
    void RegisterCommands();
    void Execute( const std::string& input, GameState& gameState);
};