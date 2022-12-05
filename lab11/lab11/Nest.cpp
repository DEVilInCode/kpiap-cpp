#include <iostream>
#include "Nest.h"

Green::Nest::Nest(int eggs, std::string bird) : eggs(eggs), birdType(bird){}
int Green::Nest::getEggs() { return this->eggs; }