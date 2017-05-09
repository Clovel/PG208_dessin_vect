// Clovis Durand & Camille Magnan
// ENSEIRB-Matmeca, E2
// 2017

// PG208 - Projet Dessin Vectoriel

// Cercle_p.h
// Cercle_p class source file. 

#include "../../HEADERS/Formes/Cercle_p.h"

// Con/Destructeurs
Cercle_p::Cercle_p()
{
    setRayon(1); // Valeur par defaut a définir, 1 pour le moment
}

Cercle_p::Cercle_p(Coord const c, 
    unsigned int const rayon, 
    std::string const couleur, 
    unsigned int const transparence)
{
	setCoord1(c);
    setRayon(rayon);
    setCouleur(couleur);
    setTransparence(transparence);
}

// Afficheurs

// Accesseurs

// Mutateurs

// Draw
void Cercle_p::draw(CImage *img) const
{
    float seg;

    int x = getCoord1().getAbscisse();
    int y = getCoord1().getOrdonnee();

    for(int i = MAX(x - getRayon(), 0); i < MIN(x + getRayon() + 1, img->size()); i++)
    {
        for (int j = MAX(y - getRayon(), 0); j < MIN(y + getRayon() + 1, img->size()); j++)
        {
            seg = sqrt(pow(x - i, 2) + pow(y - j, 2));

            if (seg < getRayon()) // .5 étant un epsilon
                img->drawPixel(i, j, getRGB().r, getRGB().g, getRGB().b);
        }
    }
}

// Méthodes publiques Diverses

// Attributs/Variables membres

// Méthodes privées diverses 