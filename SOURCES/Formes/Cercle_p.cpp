// Clovis Durand & Camille Magnan
// ENSEIRB-Matmeca, E2
// 2017

// PG208 - Projet Dessin Vectoriel

// Cercle_p.h
// Cercle_p class source file. 

#include "../../HEADERS/Formes/Cercle_p.h"

// Con/Destructeurs

// Afficheurs

// Accesseurs

// Mutateurs

// Draw
Cercle::draw(CImage *img)
{
	for(int i = max(x - rayon, 0); i < min(x + rayon, img->size()); i++)
	{
		for(int j = max(y - rayon,0); j < min(y + rayon, img->size()); j++)
		{
			if (sqrt(pow(x - i, 2) + pow(y - j, 2)) < rayon)
			{
				img->drawPixel(i, j, getRed(), getGreen(), getBlue());
			}
		}
	}
}

// Méthodes publiques Diverses

// Attributs/Variables membres

// Méthodes privées diverses 