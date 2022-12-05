#include "Tree.h"

Green::Tree::Tree(std::string name, int age, int rootDepth, int sticksCount, std::string leaveShape, int food, int eggs, std::string bird) :
    yo(age),
    roots(rootDepth),
    sticks(leaveShape, sticksCount),
    fruit(food),
    nest(eggs, bird),
    Plant(name)
{}

int Green::Tree::getEggs() { return this->nest.getEggs(); }
