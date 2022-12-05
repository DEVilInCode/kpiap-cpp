#pragma once
#include <string>

namespace Green
{
    class Nest
    {
    public:
        Nest(int eggs, std::string bird);

        int getEggs();
    private:
        int eggs;
        std::string birdType;
    };
}