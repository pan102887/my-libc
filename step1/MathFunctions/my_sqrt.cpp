#include "my_sqrt.h"

#include <iostream>
#include <cmath>

namespace mathfunctions
{
    double my_sqrt(double x)
    {
        printf("my sqrt\n");
        return std::sqrt(x);
    }
};
