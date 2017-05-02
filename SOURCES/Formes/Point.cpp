// Clovis Durand & Camille Magnan
// ENSEIRB-Matmeca, E2
// 2017

// PG208 - Projet Dessin Vectoriel

// Point.cpp
// Point class source file. 

#include "../../HEADERS/Formes/Point.h"
using namespace std;

// Con/Destructeurs
Point::Point()
{	
	setCouleur("BLANC");
	setTransparence(0);
}

Point::Point(Coord const c, 
	string const couleur, 
	unsigned int const transparence)
{
	setCoord1(c);
	setTransparence(transparence);
	setCouleur(couleur);
}

// Afficheurs

// Accesseurs

// Mutateurs

// Draw
void Point::draw(CImage *img) const
{
	img->drawPixel(getCoord1().getAbscisse(), 
		getCoord1().getOrdonnee(), 
		getRGB().r, getRGB().g, getRGB().b);
}

// Méthodes publiques Diverses

// Attributs/Variables membres

// Méthodes privées diverses