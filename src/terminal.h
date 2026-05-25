#pragma once

#include <string>
#include <vector>

class Terminal
{
    public:
        std::string inputBuffer;
        void HandleInput();
        void Draw(const std::vector<std::string>& lines);
        bool submitPressed();
};