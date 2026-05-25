#include "world.h"
#include <algorithm>
#include "commands.h"
#include "utils.h"

void World::AddEdge(std::string u, std::string v)
{
    u = str_tolower(u);
    v = str_tolower(v);
    rooms[u].push_back(v);
    rooms[v].push_back(u);
}

bool World::CanMove(std::string from, std::string to)
{
    for (std::string room : rooms[from])
    {
        if (room == to)
        {
            return true;
        }
    }
    return false;
}