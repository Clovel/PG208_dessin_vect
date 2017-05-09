// Camille Magnan & Clovis Durand
// Dessin vectoriel

#include "../../HEADERS/Formes/Cercle.h"

// Con/Destructeurs
Cercle::Cercle(): m_rayon(1)
{
    // Valeur par defaut a définir, 1 pour le moment
}

Cercle::Cercle(Coord const c, 
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
unsigned int Cercle::getRayon(void) const
{
    return m_rayon;
}

// Mutateurs
void Cercle::setRayon(unsigned int const &rayon)
{
    m_rayon = rayon;
}

// Draw
void Cercle::draw(CImage *img) const
{
    float seg;

    int x = getCoord1().getAbscisse();
    int y = getCoord1().getOrdonnee();

    RGB_t RGB_temp;

    for(int i = MAX(x - getRayon(), 0); i < MIN(x + getRayon() + 1, img->size()); i++)
    {
        for (int j = MAX(y - getRayon(),0); j < MIN(y + getRayon() + 1, img->size()); j++)
        {
            seg = sqrt(pow(x - i, 2) + pow(y - j, 2));

            if ((seg < (getRayon() + 1)) & (seg > (getRayon() - 1))) // 1 étant un epsilon
            {
                RGB_temp = applyTransparency(i, j);
                img->drawPixel(i, j, RGB_temp.r, RGB_temp.g, RGB_temp.b);
            }
        }
    }
}

/*NOUS AVONS FAIT UNE CLASSE FINALEMENT
void Cercle::drawfull(CImage *img) const
{
    float seg;

    int x = getCoord1().getAbscisse();
    int y = getCoord1().getOrdonnee();

    RGB_t RGB_temp;

    for(int i = MAX(x - getRayon(), 0); i < MIN(x + getRayon() + 1, img->size()); i++)
    {
        for (int j = MAX(y - getRayon(), 0); j < MIN(y + getRayon() + 1, img->size()); j++)
        {
            seg = sqrt(pow(x - i, 2) + pow(y - j, 2));

            if (seg < getRayon()) // .5 étant un epsilon
            {
                RGB_temp = applyTransparency(i, j);
                img->drawPixel(i, j, RGB_temp.r, RGB_temp.g, RGB_temp.b);
            }
        }
    }
}
*/

// Méthodes publiques Diverses

// Attributs/Variables membres

// Méthodes privées diverses 