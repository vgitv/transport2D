#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

#include "Transport2D.h"
#include "math.h"

Transport2D::Transport2D(std::string fichier, double (*u0) (double, double)) : m_grille(fichier), m_u0(u0)
{
    m_u = new double*[m_grille.m_nx];
    for (int i = 0; i < m_grille.m_nx; ++i)
    {
        m_u[i] = new double[m_grille.m_ny];
    }
}

Transport2D::~Transport2D()
{
    for (int i = 0; i < m_grille.m_nx; ++i)
    {
        delete[] m_u[i];
    }

    delete m_u;
}

void Transport2D::init()
{
    for (int i = 0; i < m_grille.m_nx; ++i)
    {
        for (int j = 0; j < m_grille.m_ny; ++j)
        {
            m_u[i][j] = m_u0(m_grille.m_x[i], m_grille.m_y[j]);
        }
    }
}

void Transport2D::setFlux(void (*f) (double, double, double, double[2]))
{
    m_f = f;
}

void Transport2D::aff()
{
    // infos sur le maillage
    m_grille.aff();

    // Si la matrice est de taille "raisonnable", on l'affiche.
    if ((m_grille.m_ny <= 10) && (m_grille.m_nx <= 20))
    {
        math::affMat(m_grille.m_nx, m_grille.m_ny, m_u);
    }
}

void Transport2D::plot3D(std::string fichier)
{
    std::ofstream flux(fichier.c_str());
    int n = std::numeric_limits<double>::digits10 + 1;

    if (flux)
    {
        for (int i = 0; i < m_grille.m_nx; ++i)
        {
            for (int j = 0; j < m_grille.m_ny; ++j)
            {
                flux << std::setw(22) << std::setprecision(n) << m_grille.m_x[i]
                    << std::setw(22) << std::setprecision(n) << m_grille.m_y[j]
                    << std::setw(22) << std::setprecision(n) << m_u[i][j] << std::endl;
            }
        }
    }
    else
    {
        std::cerr << "ERROR fc Transport2D::plot3D" << std::endl;
    }
}

double Transport2D::fluxLaxFriedrichs(double x, double y, double uk, double ul, double nkl[2])
{
    double lambda = 1;
    double fuk[2], ful[2];

    // calcul des flux
    m_f(x, y, uk, fuk);
    m_f(x, y, ul, ful);

    return math::dotProd(2, fuk, nkl) + math::dotProd(2, ful, nkl) + (ul - uk) / 2 * lambda;
}
