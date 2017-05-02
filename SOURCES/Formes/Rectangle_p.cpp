// Clovis Durand & Camille Magnan
// ENSEIRB-Matmeca, E2
// 2017

// PG208 - Projet Dessin Vectoriel

// Rectangle_p.cpp

#include "../../HEADERS/Formes/Rectangle_p.h"

// Con/Destructeurs

// Afficheurs

// Accesseurs

// Mutateurs

// Draw
void Rectangle_p::draw(CImage *img) const
{
	int origine_y = getCoord1().getOrdonnee();
	int origine_x = getCoord1().getAbscisse();
	int longueur  = getLigne2().getCoord1().getOrdonnee() - origine_y;
	int hauteur   = getLigne3().getCoord1().getAbscisse() - origine_x;

	for(int i = origine_x; i >= longueur; i++)
	{
		for(int j = origine_y; j >= hauteur; j++)
		{
			img->drawPixel(i, j, getRGB().r, getRGB().g, getRGB().b);
		}
	}
}

// Méthodes publiques Diverses

// Attributs/Variables membres

// Méthodes privées diverses 