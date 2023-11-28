#include "project_config.h"
#include "MathFunctions.h"


#include <iostream>


int main(int argc, char *argv[])
{
    printf("Hello, CMake!\n");
    printf("version: %d.%d.%d\n", PROJECT_VERSION_MAJOR, PROJECT_VERSION_MINOR, PROJECT_VERSION_PATCH);    
    const double inputValue = std::stod(argv[1]);
    const double outputValue = mathfunctions::sqrt(inputValue);
    printf("the sqrt of %g is %g\n", inputValue, outputValue);
    return 0;
}