#include "Mesh.h"
#include "math.h"



Mesh::Mesh(std::string fichier)
{
    readVar(fichier);

    m_x = new double[m_nx];
    m_y = new double[m_ny];
    m_t = new double[m_nt];

    math::linspace(m_xmin, m_xmax, m_nx, m_x);
    math::linspace(m_ymin, m_ymax, m_ny, m_y);
    math::linspace(0.0, m_tmax, m_nt, m_t);

    m_dx = m_x[1] - m_x[0];
    m_dy = m_y[1] - m_y[0];
    m_dt = m_t[1] - m_t[0];
}

Mesh::~Mesh()
{
    delete[] m_x;
    delete[] m_y;
    delete[] m_t;
}

void Mesh::readVar(std::string fichier)
{
    math::read(fichier, "#xmin", m_xmin);
    math::read(fichier, "#xmax", m_xmax);
    math::read(fichier, "#nx", m_nx);

    math::read(fichier, "#ymin", m_ymin);
    math::read(fichier, "#ymax", m_ymax);
    math::read(fichier, "#ny", m_ny);

    math::read(fichier, "#tmax", m_tmax);
    math::read(fichier, "#nt", m_nt);
}

void Mesh::aff()
{
    std::cout << "m_x : [" << m_xmin << ", " << m_xmax << "]   m_nx = " << m_nx << std::endl;
    std::cout << "m_y : [" << m_ymin << ", " << m_ymax << "]   m_ny = " << m_ny << std::endl;
    std::cout << "m_t : [" << 0.0    << ", " << m_tmax << "]   m_nt = " << m_nt << std::endl;
}

int Mesh::getNx()
{
    return m_nx;
}

int Mesh::getNy()
{
    return m_ny;
}
