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



    // ------------------------------------------------------------------------------------------------------
    // produit scalaire
    // ------------------------------------------------------------------------------------------------------
    double dotProd(int n, double u[], double v[])
    {
        double cumul = 0;

        for (int i = 0; i < n; ++i)
        {
            cumul += u[i] * v[i];
        }

        return cumul;
    }
}
