#include <cmath>

#include "donnees.h"

double u0(double x, double y)
{
    return cos(3 * x) * sin(3 * y);
}

void f(double x, double y, double u, double out[2])
{
    out[1] = 2 * u;
    out[2] = -1 * u;
}
