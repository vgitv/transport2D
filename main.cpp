#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <iomanip>

#include "math.h"
#include "vf.h"
#include "donnees.h"

using namespace std;

int main()
{
    // ------------------------------------------------------------------------------------------------------
    // déclaration de variables
    // ------------------------------------------------------------------------------------------------------
    // espace : \Omega = [a, b]**2     temps : [0, tf]
    double a, b, tf;
    // nombre de points de subdivision espace et temps
    int n, m;


    // subdivisions et intervalles
    double *x, *y, *t;
    double dx, dy;

    // solution
    double **u;

    // fichiers de sortie
    string fichier = "sorties/u.dat";



    // ------------------------------------------------------------------------------------------------------
    // partie principale
    // ------------------------------------------------------------------------------------------------------
    cout << "test" << endl;
    // lecture des constantes
    math::read("entrees/constantes", "#a", a);
    math::read("entrees/constantes", "#b", b);
    math::read("entrees/constantes", "#n", n);

    math::read("entrees/constantes", "#tf", tf);
    math::read("entrees/constantes", "#m", m);

    x = new double[n];
    y = new double[n];
    t = new double[m];



    // subdivisions espace (2 dimensions) et temps
    math::linspace(a, b, n, x);
    math::linspace(a, b, n, y);
    math::linspace(0, tf, m, t);

    dx = x[1] - x[0];
    dy = y[1] - y[0];



    cout << "[a, b]**2  = [" << a << ", " << b  << "]**2" << "   n = " << n << endl;
    cout << "[0, tf]    = [" << 0 << ", " << tf << "]" << "      m = " << m << endl;


    math::affVec(n, x);
    math::affVec(n, y);
    math::affVec(m, t);

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            u[i][j] = x[i] + y[j];
        }
    }

    std::ofstream flux(fichier.c_str());

    if (flux)
    {
        //flux << std::setprecision(std::numeric_limits<double>::digits10 + 1) << std::setw(50);
        //flux << std::setw(50);

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                flux << setw(20) << x[j] << setw(20) << y[i] << setw(20) << u[j][i] << std::endl;
            }
        }
    }





    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    delete[] x;
    delete[] y;
    delete[] t;

    return 0;
}
