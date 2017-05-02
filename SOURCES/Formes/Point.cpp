// Clovis Durand & Camille Magnan
// ENSEIRB-Matmeca, E2
// 2017

// PG208 - Projet Dessin Vectoriel

// Point.cpp
// Point class source file. 

#include "../../HEADER/Formes/Point.h"
using namespace std;

// Con/Destructeurs
Point::Point()
{	
	setCouleur("BLANC")
	setTransparence(0);
}

Point::Point(Coord c, 
	string couleur, 
	unsigned int transparence)
{
	setCoord1(c);
	setTransparence(transparence);
	setCouleur(couleur);
}

// Afficheurs

// Accesseurs

// Mutateurs

// Draw
Point::draw(CImage *img)
{
	RGB_t rgb = getRGB();
	img->drawPixel(getCoord1().getAbscisse(), getCoord1().getOrdonnee(), rgb.r, rgb.g, rgb.b);
}

// Méthodes publiques Diverses

// Attributs/Variables membres

// Méthodes privées diverses