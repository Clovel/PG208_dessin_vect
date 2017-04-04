// Camille Magnan & Clovis Durand
// Dessin vectoriel

#include "../../HEADERS/Formes/Cercle.h"
using namespace std;

//Constructeur/Destructeur

Cercle::Cercle(Coord const c,
	unsigned int const rayon,
	std::string const couleur, 
	unsigned int const transparence)
{
	setC(c);
	setRayon(rayon);
	setCouleur(couleur);
	setTransparence(transparence);
}

//Afficheurs

//Accesseurs

Coord Cercle::getC() const
{
	return m_c;
}

unsigned int Cercle::getRayon() const
{
	return m_rayon;
}

string Cercle::getCouleur() const
{
	return m_couleur;
}

unsigned int Cercle::getTransparence() const
{
	return m_transparence;
}

//Mutateurs

void Cercle::setC(Coord const &c)
{
	m_c = c;
}

void Cercle::setRayon(unsigned int const &rayon)
{
	m_rayon = rayon;
}

void Cercle::setCouleur(string const &couleur)
{
	m_couleur = couleur;
}

void Cercle::setTransparence(unsigned int const &transparence)
{
	m_transparence = transparence;
}




