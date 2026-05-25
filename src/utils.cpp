#include "utils.h"

#include <algorithm>
#include <cctype>

std::string str_tolower(std::string s)
{
    std::transform(
        s.begin(),
        s.end(),
        s.begin(),
        [](unsigned char c)
        {
            return std::tolower(c);
        }
    );

    return s;
}