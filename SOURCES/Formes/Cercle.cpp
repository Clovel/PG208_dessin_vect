// Camille Magnan & Clovis Durand
// Dessin vectoriel

#include "../../HEADERS/Formes/Cercle.h"

// Con/Destructeurs
Cercle::Cercle()
{	
	m_rayon(1); // Valeur par defaut a définir, 1 pour le moment
}

Cercle::Cercle(Coord c, int rayon, std::string couleur, int transparence)
{
	m_transparence = transparence;
	m_c1 = c;
	m_rayon = rayon;
	setRGBcouleur(couleur);
	m_couleur = couleur;
}

// Afficheurs

// Accesseurs

// Mutateurs

// Draw
Cercle::draw(CImage *img)
{

    for(int i = max(x - rayon, 0); i < min(x + rayon + 1, img->size()); i++)
    {
        for (int j = max(y - rayon,0); j < min(y + rayon + 1, img->size()); j++)
        {
            float seg = sqrt(pow(x - i, 2) + pow(y - j, 2));

            if ((seg < (rayon + 2)) & (seg > (rayon - 2))) // 2 étant un epsilon
            {
                img->drawPixel(i, j, getRed(), getGreen(), getBlue());
            }
        }
    }
}

// Méthodes publiques Diverses

// Attributs/Variables membres

// Méthodes privées diverses 


//CERCLE VIDE



//CERCLE VIDE
