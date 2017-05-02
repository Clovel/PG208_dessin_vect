// Camille Magnan & Clovis Durand
// Dessin vectoriel

#include <string>
#include <cmath>
#include <iostream>
#include "../image/CImage.h"
#include "../Others/Coord.h" 	
#include "Forme.h"
#include "Cercle_2.h"

Cercle_2::Cercle_2(Coord c, int rayon, std::string couleur, int transparence)
{

	m_transparence = transparence;
	m_c1 = c;
	m_rayon = rayon;
	setRGBcouleur(couleur);
	m_couleur = couleur;

}

Cercle_2::Cercle()
{	
}

//CERCLE VIDE

Cercle_2::dessinerFull(CImage *img)
{

	for(int i=max(x - rayon, 0); i<min(x + rayon, img->size()); i++)
	{
		for(int j=max(y-rayon,0); j<min(y + rayon, img->size()); j++)
		{
			if (sqrt(pow(x - i, 2) + pow(y - j, 2)) < rayon)
			{
				img->drawPixel(i, j, getRed(), getGreen(), getBlue());


			}
		}
	}

}

//CERCLE VIDE

Cercle_2::dessiner(CImage *img)
{

    for(int i=max(x-rayon,0); i<min(x+rayon+1,img->size()); i++){
            for (int j=max(y-rayon,0); j<min(y+rayon+1,img->size()); j++)
            {

                float seg = sqrt(pow(x-i,2) + pow(y-j,2));

                if ( (seg<(rayon+2)) & (seg > (rayon-2))  ) // 2 étant un epsilon
                    {
                        img->drawPixel(i, j, getRed(), getGreen(), getBlue());
                    }
            }
    }



}