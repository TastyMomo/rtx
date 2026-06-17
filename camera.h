#ifndef CAMERA_H
#define CAMERA_H

#include "function.h"
#include "hittable.h"
#include "sphere.h"

class camera {
    public:
        double aspect_ratio = 1.0;  //Image ratio
        int image_width = 100;
        int samples_per_pixel = 10;

        void render(const hittable& world) {
            initialize();

            // Render
            std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

            for (int j=0; j<image_height; j++){
                std::clog << "Scanlines Remaining: " << (image_height - j) << '\n' << std::flush;
                for (int i=0; i<image_width; i++){
                    //Shooting random rays
                    color pixel_color(0,0,0);
                    for (int sample = 0; sample < samples_per_pixel; sample++) {
                        ray r = get_ray(i, j);
                        pixel_color += ray_color(r, world);
                    }
                    write_color(std::cout, pixel_samples_scale * pixel_color);
                }
            }

            std::clog << "\rDone   \n";
        }

    private:
        int image_height;
        double pixel_samples_scale;
        point3 center;
        point3 pixel00_loc;
        vec3 pixel_delta_u;
        vec3 pixel_delta_v;

        void initialize() {
            //Image height, and ensuring it's at least 1
            image_height = int(image_width / aspect_ratio);
            image_height = (image_height < 1) ? 1 : image_height;

            pixel_samples_scale = 1.0 / samples_per_pixel;

            center = point3(0, 0, 0);

            //Viewpoint dimenstions
            auto focal_length = 1.0;
            auto viewport_height = 2.0;
            auto viewport_width = viewport_height * (double(image_width)/image_height);

            //Vectors across viewport edges
            auto viewport_u = vec3(viewport_width, 0, 0);
            auto viewport_v = vec3(0, -viewport_height, 0);

            //Delta vectors from pixel to pixel
            pixel_delta_u = viewport_u / image_width;
            pixel_delta_v = viewport_v / image_height;

            //Location of upper left pixel
            auto viewport_upper_left = center - vec3(0, 0, focal_length) - viewport_u/2 - viewport_v/2;
            pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);

        }

        //Random camera ray from origin to (i, j)
        ray get_ray(int i, int j) const {
            auto offset = sample_square();
            auto pixel_sample = pixel00_loc + ((i + offset.x()) * pixel_delta_u) + ((j + offset.y()) * pixel_delta_v);
            auto ray_origin = center;
            auto ray_direction = pixel_sample - ray_origin;

            return ray(ray_origin, ray_direction);
        }

        //Returns vector to random point in pixel
        vec3 sample_square() const {
            return vec3(random_double() - 0.5, random_double() - 0.5, 0);   //Range: [-0.5, -0.5] to [+0.5, +0.5]
        }

        color ray_color(const ray& r, const hittable& world) const {
            hit_record rec;

            if (world.hit(r, interval(0, infinity), rec)) {
                return 0.5 * (rec.normal + color(1,1,1));
            }

            vec3 unit_direction = unit_vector(r.direction());
            auto a = 0.5 * (unit_direction.y() + 1.0);
            return (1.0-a) * color(1.0, 1.0, 1.0) + a * color(0.5, 0.7, 1.0);
        }
};

#endif