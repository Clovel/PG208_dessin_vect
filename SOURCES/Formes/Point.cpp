// Camille Magnan & Clovis Durand
// Dessin vectoriel

#include <string>
#include <cmath>
#include <iostream>
#include "../image/CImage.h"
#include "../Others/Coord.h" 	
#include "Forme.h"
#include "Point.h"

Point::Point(Coord c, std::string couleur, int transparence)
{

	m_transparence = transparence;
	m_c1 = c;
	m_rayon = rayon;
	setRGBcouleur(couleur);
	m_couleur = couleur;

}

Point::Point()
{	
}

//CERCLE VIDE

Point::dessiner(CImage *img)
{
	img->drawPixel(getCoord1().getAbscisse(), getCoord1().getOrdonnee(), getRed(), getGreen(), getBlue());
}