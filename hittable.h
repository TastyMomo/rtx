#ifndef HITTABLE_H
#define HITTABLE_H

#include "ray.h"

class hit_record {
    public:
        point3 p;   //Cordinates
        vec3 normal;    //Direction
        double t;   //Distance

        //Checking if the surface is front-face
        bool front_face;
        void set_face_normal(const ray& r, const vec3& outward_normal) {
            front_face = dot(r.direction(), outward_normal) < 0;
            normal = front_face ? outward_normal : -outward_normal;
        }
};

class hittable {
    public:

        virtual ~hittable() = default;  //Cleans memory about hittable objects, prevents memory leak

        virtual bool hit(const ray& r, double ray_tmin, double ray_tmax, hit_record& rec) const = 0;    //Pure virtual function
};

#endif