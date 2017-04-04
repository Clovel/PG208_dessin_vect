// Camille Magnan & Clovis Durand
// PG208 - Projet Dessin Vectoriel

#include "../HEADERS/Coord.h"
using namespace std;

// Classe Coord permet de definir un point "mathemmatique"


//Con/Destructeurs
Coord::Coord(int const x, int const y): m_x(x), m_y(y)
{
	// Constructeur par defaut
}

// Afficheurs
void Coord::showCoord(void) const
{
	cout << "------------------" << endl;
	cout << "Abscisse : " << m_x << endl;
	cout << "Ordonnée : " << m_y << endl;
	cout << "------------------" << endl;
}

void Coord::printCoord(ostream &flux) const
{
	flux << "(" << m_x << ", " << m_y << ")";
}

// Accesseurs
int Coord::getAbscisse(void) const
{
	return m_x;
}

int Coord::getOrdonnee(void) const
{
	return m_y;
}

// Mutateurs
void Coord::setAbscisse(int const &x)
{
	m_x = x;
}

void Coord::setOrdonnee(int const &y)
{
	m_y = y;
}

// Operateurs
ostream& operator<<(ostream& flux, Coord const &c)
{
    c.printCoord(flux);
    return flux;
}