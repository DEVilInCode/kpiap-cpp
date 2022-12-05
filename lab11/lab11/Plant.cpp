#include <iostream>
#include <vector>
#include "Plant.h"

Green::Plant::Plant(std::string name):name(name){}
std::string Green::Plant::getName() { return this->name; }