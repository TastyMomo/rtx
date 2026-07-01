#ifndef FUNCTION_H
#define FUNCTION_H

#include <cmath>
#include <random>
#include <cstdlib>
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
inline double degree_to_radian(double degrees) {
    return degrees * pi / 180.0;
}

//Random real in [0,1)
inline double random_double() {
    thread_local std::uniform_real_distribution<double> distribution(0.0, 1.0);
    thread_local std::mt19937 generator;
    return distribution(generator);
}

//Random real in [min, max)
inline double random_double(double min, double max) {
    return min + (max-min)*random_double();
}

//Headers
#include "color.h"
#include "interval.h"
#include "ray.h"
#include "vec3.h"

#endif