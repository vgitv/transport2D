#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

#include "math.h"



namespace math
{

    // ------------------------------------------------------------------------------------------------------
    // création vecteur entre a et b de taille n
    // ------------------------------------------------------------------------------------------------------
    void linspace(double a, double b, int taille, double *vecteur)
    {
        double h((b - a) / (taille - 1));

        for (int i(0); i < taille - 1; ++i)
        {
            vecteur[i] = a + i * h;
        }

        vecteur[taille - 1] = b;
    }
}
