#include "MathFunctions.h"

#ifdef USE_MYMATH
#include "my_sqrt.h"
#else
#include <cmath>
#endif

#include <iostream>

namespace mathfunctions
{
	double sqrt(double x)
	{
#ifdef USE_MYMATH
		return my_sqrt(x);
#else
		printf("system's sqrt\n");
		return std::sqrt(x);
#endif
	}
};
