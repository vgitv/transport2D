#ifndef MESH_H
#define MESH_H

#include <string>

class Mesh
{
    public :
        /*
         * constructeur et destructeur
         */
        Mesh(std::string fichier);
        ~Mesh();

        /*
         * Lis les variables d'entrée dans un fichier.
         */
        void readVar(std::string fichier);

        /*
         * Afficher informations sur objet.
         */
        void aff();



    private :
        /* 3 subdivision : 2 en espace et une en temps. Pour chaque subdivision :
         * - début subdivision
         * - fin subdivision
         * - nombre de valeurs
         * - intervalle (déduit des précédents)
         * - subdivision
         */

        // subdivision en x
        double m_xmin;
        double m_xmax;
        int m_nx;
        double m_dx;
        double *m_x;

        // subdivision en y
        double m_ymin;
        double m_ymax;
        int m_ny;
        double m_dy;
        double *m_y;

        // subdivision en temps
        double m_tmax;
        int m_nt;
        double m_dt;
        double *m_t;
};

#endif
