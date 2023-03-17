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

void Transport2D::aff()
{
    m_grille.aff();
    math::affMat(m_grille.m_nx, m_grille.m_ny, m_u);
}
