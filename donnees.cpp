#include <cmath>

#include "donnees.h"

double u0(double x, double y)
{
    return cos(3 * x) * sin(3 * y);
}

void f(double x, double y, double u, double out[2])
{
    out[0] = 2 * u;
    out[1] = -1 * u;
}

void truc(double tab[2])
{
    tab[0] = 8;
    tab[1] = 9;
}
