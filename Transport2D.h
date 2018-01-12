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
         *
         */
        void aff();



    private :
        // maillage
        Mesh m_grille;

        // condition initiale
        double (*m_u0) (double, double);

        // solution
        double **m_u;
};

#endif
