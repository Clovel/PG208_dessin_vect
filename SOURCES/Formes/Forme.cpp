// Clovis Durand & Camille Magnan
// ENSEIRB-Matmeca, E2
// 2017

// PG208 - Projet Dessin Vectoriel

// Forme.cpp
// Forme class source file. 

#include "../../HEADERS/Formes/Forme.h"
using namespace std;


// Con/Destructeurs
Forme::Forme()
{
	setTransparence(0);
}

Forme::Forme(Coord const c1, 
	Couleur const couleur,
	unsigned int const transparence)
{
	setCoord1(c1);
	setCouleur(couleur);
	setTransparence(transparence);
}

// Accesseurs
Coord Forme::getCoord1(void) const
{
	return m_c1;
}

Couleur Forme::getCouleur(void) const
{
	return m_couleur;
}

unsigned int Forme::getTransparence(void) const
{
	return m_transparence;
}

// Mutateurs
void Forme::setCoord1(Coord const &c1)
{
	m_c1 = c1;
}

void Forme::setCouleur (Couleur const &couleur)
{
	m_couleur = couleur;
}

void Forme::setTransparence(unsigned int const &transparence)
{
	m_transparence = transparence;
}