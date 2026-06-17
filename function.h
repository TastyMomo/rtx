#ifndef FUNCTION_H
#define FUNCTION_H

#include <cmath>
#include <iostream>
#include <limits>
#include <memory>

//Std
using std::make_shared;
using std::shared_ptr;

//Constants
const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

//Functions
inline double degrees_to_radian(double degrees) {
    return degrees * pi / 180.0;
}

//Headers
#include "color.h"
#include "interval.h"
#include "ray.h"
#include "vec3.h"

#endif