#ifndef DONNEES_H
#define DONNEES_H

/*
 * Condition initiale.
 */
double u0(double x, double y);

/*
 * Flux du problème f = Au avec A dans R**2.
 */
void f(double x, double y, double u, double out[2]);

void truc(double tab[2]);

#endif
