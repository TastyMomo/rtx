# raytracer
a simple raytracer written on C++. it uses parallel processing for faster results.

based on the book [ray tracing in one weekend](https://raytracing.github.io/books/RayTracingInOneWeekend.html). 

---
## prerequisites

* cmake (Version 3.10 or higher)
* OpenMP (for CPU multi-threading)

if cmake is not installed, use the following command:

```bash
sudo apt install cmake -y
```

CMakeList.txt should look like this:

```bash
cmake_minimum_required(VERSION 3.10)

project(RayTracer)

find_package(OpenMP REQUIRED)

add_executable(raytracer main.cc)

target_link_libraries(raytracer PRIVATE OpenMP::OpenMP_CXX)
```

---

## rendering

for rendering an image:

```bash
cmake -B build
cmake --build build
./build/raytracer > image.ppm
```

the output file will be called 'image.ppm' in the project directory.

---

## viewing
requires a ppm viewer, or can be converted into any image format and viewed accordingly.

below is a sample output of the raytracer:

<img src="https://github.com/TastyMomo/raytracer/blob/main/image.png">

---

## features
 * fully encapsulated 3D math library (vec3) to handle coordinates, colors, and directionality.
 * sub-pixel random sampling via the Mersenne Twister engine to smooth out jagged geometric edges.
 * defocus blur (depth of field) utilizing an adjustable aperture and focal distance to simulate real-world lenses.
 * lambertian reflectance for matte surfaces.

---
