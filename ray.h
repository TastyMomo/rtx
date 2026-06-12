#ifndef RAY_H
#define RAY_H

#include "vec3.h"

class ray {
    public:

        //Constructor
        ray() {}    //Default constructor
        ray(const point3& origin, const vec3& direction) : orig(origin), dir(direction) {}  //Parameterized constructor

        //Accessors because actual data is private
        const point3& origin() const { return orig; }
        const vec3& direction() const { return dir; }

        //P(t)=A+tb
        point3 at (double t) const{
            return orig + t*dir;
        }

    //Prevent overwrite
    private:
        point3 orig;
        vec3 dir;
};

#endif