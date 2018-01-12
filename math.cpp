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
    // écriture fonction R**2 -> R pour plot 3D
    // ------------------------------------------------------------------------------------------------------
    void plot3D(int nx, double x[], int ny, double y[], double **z, std::string fichier)
    {
        std::ofstream flux(fichier.c_str());

        if (flux)
        {
            //flux << std::setprecision(std::numeric_limits<double>::digits10 + 1) << std::setw(50);
            flux << std::setw(50);

            for (int i = 0; i < ny; ++i)
            {
                for (int j = 0; j < nx; ++j)
                {
                    flux << x[j] << y[i] << z[j][i] << std::endl;
                }
            }
        }
        else
        {
            std::cerr << "ERROR fc Laplacien1D::write" << std::endl;
        }
    }
}
