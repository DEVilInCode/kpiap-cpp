#pragma once
#include "Plant.h"
#include "Nest.h"
#include "Fruit.h"
#include "Root.h"
#include "Stick.h"

namespace Green {
    class Tree : public Plant
    {
    public:
        Tree(std::string name, int age, int rootDepth, int sticksCount, std::string leaveShape, int food, int eggs, std::string bird);

        int getEggs();

    private:
        int yo;
        Nest nest;
        Fruit fruit;
        Stick sticks;
        Root roots;
    };
}