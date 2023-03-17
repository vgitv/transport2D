/* FICHIER CONTENANT LES FONCTIONS :
 *
 * read
 * linspace
 * affMat
 * affVec
 */


#ifndef MATH_H
#define MATH_H

#include <iostream>
#include <fstream>
#include <string>

namespace math
{
    // ======================================================================================================
    // PROTOTYPES
    // ======================================================================================================

    /*
     * Création vecteur entre a et b de taille n.
     */
    void linspace(double a, double b, int taille, double vecteur[]);

    /*
     * Produit scalaire.
     */
    double dotProd(int n, double u[], double v[]);





    // ======================================================================================================
    // TEMPLATES
    // ======================================================================================================

    // ------------------------------------------------------------------------------------------------------
    // lecture constantes dans un fichier
    // ------------------------------------------------------------------------------------------------------
    template<typename T>
        void read(std::string fichier, std::string balise, T &variableLue)
        {
            std::ifstream flux(fichier.c_str());
            std::string courant;

            if (flux)
            {
                flux >> courant;
                // on cherche la balise
                while (balise != courant)
                {
                    flux >> courant;
                }

                // on a trouvé la balise, ce qui suit est notre variable
                flux >> variableLue;
            }
            else
            {
                std::cout << "ERREUR lors de la lecture du fichier" << std::endl;
            }
        }



    // ------------------------------------------------------------------------------------------------------
    // affichage matrice en console
    // ------------------------------------------------------------------------------------------------------
    template<typename T>
        void affMat(int n, int m, T mat)
        {
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < m; ++j)
                {
                    std::cout << mat[i][j] << "  ";
                }
                std::cout << std::endl;
            }
        }




    // ------------------------------------------------------------------------------------------------------
    // affichage vecteur en console
    // ------------------------------------------------------------------------------------------------------
    template<typename T>
        void affVec(int n, T vec)
        {
            for (int i = 0; i < n; ++i)
            {
                std::cout << vec[i] << "  ";
            }
            std::cout << std::endl;
        }
}

#endif
