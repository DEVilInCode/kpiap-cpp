#pragma once
#include <string>

namespace Green
{
    class Plant
    {
    public:
        Plant(std::string name);
        std::string getName();
    private:
        std::string name;
    };

    
}