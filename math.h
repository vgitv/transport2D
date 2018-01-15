/* FICHIER CONTENANT LES FONCTIONS :
 *
 * linspace
 * dotProd
 * read
 * affMat
 * affVec
 */


#ifndef MATH_H
#define MATH_H

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

namespace math
{
    // ======================================================================================================
    // PROTOTYPES
    // ======================================================================================================

    /*
     * Création vecteur entre a et b de taille n.
     */
    void linspace(double a, double b, int taille, double vecteur[]);





    // ======================================================================================================
    // TEMPLATES
    // ======================================================================================================

    /*
     * Produit scalaire.
     */
    template<typename T>
        T dotProd(int n, T u[], T v[])
        {
            T cumul = 0;

            for (int i = 0; i < n; ++i)
            {
                cumul += u[i] * v[i];
            }

            return cumul;
        }



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
                    std::cout << std::setw(8) << std::setprecision(5) << mat[i][j] << "  ";
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
