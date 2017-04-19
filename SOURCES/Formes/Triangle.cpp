// Clovis Durand & Camille Magnan
// ENSEIRB-Matmeca, E2
// 2017

// PG208 - Projet Dessin Vectoriel

// Triangle.cpp
// Triangle class source file. 

#include "../../HEADERS/Formes/Triangle.h"

// Constructeurs
Triangle::Triangle()
{
	Coord c;
	setCoord1(c);
	setCoord2(c);
	setCoord3(c);
	// Trois points confondus
}

Triangle::Triangle(Ligne const l, Coord const c, 
	Couleur const color, 
	unsigned int const transparence)
{
	setCoord1(l.getCoord1());
	setCoord2(l.getCoord2());
	setCoord3(c);
	setCouleur(color);
	setTransparence(transparence);
}

// Afficheurs

// Accesseurs
Coord Triangle::getCoord3(void) const
{
	return m_c3;
}

// Mutateurs
void Triangle::setCoord3(Coord const &c)
{
	m_c3 = c;
}

// Draw
void Triangle::draw(CImage *img) const
{
	Ligne l1(getCoord1(), getCoord2(), getCouleur(), getTransparence());
	Ligne l2(getCoord1(), getCoord3(), getCouleur(), getTransparence());
	Ligne l3(getCoord2(), getCoord3(), getCouleur(), getTransparence());

	l1.draw(img);
	l2.draw(img);
	l3.draw(img);
}

// Méthodes publiques diverses

// Méthodes privées diverses
