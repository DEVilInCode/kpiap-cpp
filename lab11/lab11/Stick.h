#pragma once
#include "Leaves.h"
#include <string>

namespace Green {
    class Stick
    {
    public:
        Stick(std::string leavesShape, int count);
    private:
        int count;
        Leaves leaves;
    };
}