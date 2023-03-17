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
    equation.setFlux(&f);
    equation.aff();


    equation.plot3D("sorties/u.dat");







    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    return 0;
}
