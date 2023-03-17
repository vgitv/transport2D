#ifndef TRANSPORT2D_H
#define TRANSPORT2D_H

#include <string>

#include "Mesh.h"

class Transport2D
{
    public :
        /*
         * Constructeur, destructeur.
         */
        Transport2D(std::string fichier, double (*u0) (double, double));
        ~Transport2D();

        /*
         * Initialisation condition initiale.
         */
        void init();

        /*
         * Changer de flux.
         */
        void setFlux(void (*f) (double, double, double, double[2]));

        /*
         * Affichage informations sur l'objet.
         */
        void aff();

        /*
         * Enregistrement dans fichier pour gnuplot.
         */
        void plot3D(std::string fichier);

        /*
         * Flux numérique Lax Friedrichs.
         */
        double fluxLaxFriedrichs(double x, double y, double uk, double ul, double nkl[2]);



    private :
        // maillage
        Mesh m_grille;

        // condition initiale
        double (*m_u0) (double, double);

        // solution
        double **m_u;

        // flux du problème
        void (*m_f) (double, double, double, double[2]);
};

#endif
