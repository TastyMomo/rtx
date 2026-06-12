cmake_minimum_required(VERSION 3.1.0...4.0.0)

project(RayTracer CXX)

set(CMAKE_CXX_STANDARD 11)

add_executable(raytracer main.cc vec3.h color.h)
