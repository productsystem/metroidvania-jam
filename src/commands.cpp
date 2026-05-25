#include "commands.h"

#include <sstream>
#include <algorithm>
#include <cctype>
#include "utils.h"

std::vector<std::string> Tokenize(const std::string& str)
{
    std::stringstream ss(str);
    std::string word;
    std::vector<std::string> tokens;
    while (ss >> word)
    {
        tokens.push_back(word);
    }
    return tokens;
}

void CommandSystem::RegisterCommands()
{
    commands["help"] = [](const std::vector<std::string>& args, GameState& game)
    {
        game.terminalLines.push_back("AVAILABLE COMMANDS:");
        game.terminalLines.push_back("help");
        game.terminalLines.push_back("scan");
        game.terminalLines.push_back("scale");
    };

    commands["scan"] = [](const std::vector<std::string>& args, GameState& game)
    {
        game.terminalLines.push_back("SCANNING...");
        game.terminalLines.push_back("CURRENT ROOM: " + game.currRoom);
    };

    commands["scale"] = [](const std::vector<std::string>& args, GameState& game)
    {
        if (args.size() < 2)
        {
            game.terminalLines.push_back("SPECIFY SCALE MODE.");
            return;
        }
        std::string s = args[1];
        if(s.compare("standard") == 0 || s.compare("small") == 0 || s.compare("massive") == 0)
        {
            game.scaleMode = args[1];
            game.terminalLines.push_back("SCALE MODE SET TO: " + args[1]);
        }
    };

    commands["move"] = [](const std::vector<std::string>& args, GameState& game)
    {
        if (args.size() < 2)
        {
            game.terminalLines.push_back("SPECIFY MOVEMENT TARGET.");
            return;
        }
        std::string target = args[1];
        if (game.world.CanMove(game.currRoom, target))
        {
            game.currRoom = target;
            game.terminalLines.push_back("MOVED TO: " + target);
        }
        else
        {
            game.terminalLines.push_back("CANNOT MOVE THERE.");
        }
    };
}

void CommandSystem::Execute(const std::string& input, GameState& gameState)
{
    gameState.terminalLines.push_back("> " + input);
    std::string lowerCaseInput = str_tolower(input);
    auto tokens = Tokenize(lowerCaseInput);
    if (tokens.empty())
    {
        return;
    }
    auto it = commands.find(tokens[0]);
    if (it != commands.end())
    {
        it->second(tokens, gameState);
    }
    else
    {
        gameState.terminalLines.push_back("UNKNOWN COMMAND.");
    }
}