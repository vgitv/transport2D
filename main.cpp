#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <iomanip>

#include "math.h"
#include "Mesh.h"
#include "Transport2D.h"
#include "vf.h"
#include "donnees.h"

using namespace std;

int main()
{
    // ------------------------------------------------------------------------------------------------------
    // déclaration de variables
    // ------------------------------------------------------------------------------------------------------
    string constantes = "entrees/constantes";
    Transport2D equation(constantes, &u0);



    // ------------------------------------------------------------------------------------------------------
    // partie principale
    // ------------------------------------------------------------------------------------------------------
    equation.init();
    equation.aff();


    /* ATTENTION : dans Transport2D, m_u est-il de taille m_grille.m_nx * m_grille.m_ny ? Ce ne serait pas
     * plutôt (m_grille.m_nx - 1) * (m_grille.m_ny - 1) ?
     *
     * En effet, on donne une fonction en escalier, donc on veut une valeur par cellule et non une valeur
     * par noeud.
     *
     * À revérifier.
     */






    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    return 0;
}
