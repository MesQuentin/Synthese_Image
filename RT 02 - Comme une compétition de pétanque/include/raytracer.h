#ifndef RAYTRACING_H
#define RAYTRACING_H
#include "geometry.h"
#include "colors.h"

typedef struct Ray {
    Point3D pos;
    Vector3D vec;
} Ray;

typedef struct Intersection {
    Point3D pos;
    ColorRGB col;
} Intersection;

// Construit le rayon (pos, vec)
Ray createRay(Point3D pos, Vector3D vec);

