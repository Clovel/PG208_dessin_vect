// Camille Magnan & Clovis Durand
// Dessin vectoriel

#include <string>
#include <cmath>
#include <iostream>
#include "../image/CImage.h"
#include "../Others/Coord.h" 	
#include "Forme.h"
#include "Cercle_2.h"

Cercle_2::Cercle_2(Coord c; int rayon, std::string couleur, int transparence)
{

	m_couleur = couleur;
	m_transparence = transparence;
	m_c1 = c;
	m_rayon = rayon;

}

Cercle_2::Cercle()
{	
}

//CERCLE VIDE

Cercle_2::dessinerFull(CImage *Image)
{
	getRGBcolor();

	for(int i=max(x - rayon, 0); i<min(x + rayon, Image->size()); i++)
	{
		for(int j=max(y-rayon,0); j<min(y + rayon, Image->size()); j++)
		{
			if (sqrt(pow(x - i, 2) + pow(y - j, 2)) < rayon)
			{
				CPixel *p = Image->getPixel(i, j);
                p->RGB(p->Red(),p->Green(),p->Blue());

			}
		}
	}

}

//CERCLE VIDE

Cercle_2::dessiner(CImage *Image)
{
    getRGBcolor();

    for(int i=max(x-rayon,0); i<min(x+rayon+1,Image->size()); i++){
            for (int j=max(y-rayon,0); j<min(y+rayon+1,Image->size()); j++)
            {

                float seg = sqrt(pow(x-i,2) + pow(y-j,2));

                if ( (seg<(rayon+precision)) & (seg > (rayon-precision))  )
                    {
                        CPixel *p = Image->getPixel(i, j);
                        p->RGB(p->Red(),p->Green(),p->Blue());
                    }
            }
    }



}