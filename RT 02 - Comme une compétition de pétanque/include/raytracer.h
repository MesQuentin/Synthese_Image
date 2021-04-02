#ifndef RAYTRACING_H
#define RAYTRACING_H
#include "geometry.h"
#include "colors

typedef struct Ray {
    Point3D pos;
    Vector3D vec;
} Ray;

typedef struct Intersection {
    Point3D pos;
    ColorRGB col;
} Intersection;


// Construit le rayon (pos, vec)
Ray createRay(Point3D pos, Vector3D pos);

// Test si le rayon intersecte une sphère
int intersectsSphere(Ray r, Sphere s,
 Intersection* intersection, float* t);