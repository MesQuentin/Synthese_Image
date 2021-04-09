#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "../include/raytracer.h"
#include "../include/geometry.h"
#include "../include/colors.h"
#include "../include/shape.h"


Ray createRay(Point3D pos, Vector3D vec ) {

    // Construit le rayon (pos, vec)

    Ray RAY_MAN;

    RAY_MAN.pos = pos;
    RAY_MAN.vec = vec;

    return RAY_MAN;
}

int intersectsSphere(Ray r, Sphere s, Intersection* intersection, float* t) {

    // Test si le rayon intersecte la sphere. Crée l'Intersection si oui.

    Vector3D DISTANCE_TERRE_SOLEIL = createVectorFromPoints(r.pos, s.cent);
    Intersection J_AI_PAS_TOUCHE;
    Point3D CA_FAIT_CHBOUM_LA_DEDANS;
    float TOUCHE, COULE;

    float FIRST_ONE = dot(r.vec, r.vec);
    float SECOND_ONE = -2 * dot(r.vec, DISTANCE_TERRE_SOLEIL);
    float LAST_ONE = dot(DISTANCE_TERRE_SOLEIL, DISTANCE_TERRE_SOLEIL) - dot(s.ray, s.ray);

    float DETERMINANT_SOCIAL = SECOND_ONE * SECOND_ONE - 4 * FIRST_ONE * LAST_ONE;


    if (DETERMINANT_SOCIAL < 0) {
        return 0;
    }

    else {
        
        TOUCHE = (- SECOND_ONE + sqrt(DETERMINANT_SOCIAL)) / (2 * FIRST_ONE);
        COULE = (- SECOND_ONE - sqrt(DETERMINANT_SOCIAL)) / (2 * FIRST_ONE);

        if (TOUCHE * COULE < 0.) {
            t = max(TOUCHE, COULE)
        }

        else if (TOUCHE < 0.) {
            return 0;
        }

        else {
            t = min(TOUCHE, COULE);
        }

        CA_FAIT_CHBOUM_LA_DEDANS = pointPlusVector(r.pos, mltVector(r.vec, t));
        J_AI_PAS_TOUCHE.pos = CA_FAIT_CHBOUM_LA_DEDANS;
        J_AI_PAS_TOUCHE.col = s.col;
    }

    return 1;

}