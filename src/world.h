#pragma once

#include <string>
#include <vector>
#include <unordered_map>

struct World
{
    std::unordered_map<std::string,std::vector<std::string>> rooms;
    void AddEdge(std::string u, std::string v);
    bool CanMove(std::string from, std::string to);
};