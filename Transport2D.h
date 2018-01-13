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
         * Affichage informations sur l'objet.
         */
        void aff();

        /*
         * Enregistrement dans fichier pour gnuplot.
         */
        void plot3D(std::string fichier);



    private :
        // maillage
        Mesh m_grille;

        // condition initiale
        double (*m_u0) (double, double);

        // solution
        double **m_u;
};

#endif
