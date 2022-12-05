#include <iostream>
#include "Tree.h"

int main()
{
    Green::Tree tree("h", 11, 2, 3, "romb", 1, 2, "bird");

    std::cout << tree.getName() << " " <<  tree.getEggs() << std::endl;

    return 0;
}