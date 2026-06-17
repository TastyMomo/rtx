#ifndef SPHERE_H
#define SPHERE_H

#include "hittable.h"

class sphere : public hittable {
    public:
        sphere(const point3& center, double radius) : center(center), radius(std::fmax(0,radius)) {}

        //Quadratic Equations
        bool hit(const ray& r, interval ray_t, hit_record& rec) const override {
            vec3 oc = center - r.origin();
            auto a = r.direction().length_squared();
            auto h = dot(r.direction(), oc);
            auto c = oc.length_squared() - radius*radius;

            auto discriminant = h*h - a*c;
            if (discriminant < 0)
                return false;

            //Choosing the correct/nearest root
            auto sqrtd = std::sqrt(discriminant);
            auto root = (h - sqrtd) / a;    //Closer hit point (Front)
            if (!ray_t.surrounds(root)) {
                root = (h + sqrtd) / a;     //Further hit point (Back)
                if (!ray_t.surrounds(root))
                    return false;
            }

            //Filling hit_record
            rec.t = root;
            rec.p = r.at(rec.t);
            vec3 outward_normal = (rec.p - center) / radius;
            rec.set_face_normal(r, outward_normal);

            return true;
        }

        private:
            point3 center;
            double radius;
};

#endif