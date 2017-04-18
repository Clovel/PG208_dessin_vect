// Camille Magnan & Clovis Durand
// ENSEIRB-Matmeca, E2
// 2017

// PG208 - Projet Dessin Vectoriel

// Ligne.cpp
// Definition des méthodes relatives a 

#include "../../HEADERS/Formes/Ligne.h"
using namespace std;

// Con/Destructeur

Ligne::Ligne(): m_couleur("UNKNOWN"), m_transparence(0)
{
	// Par defaut
}

Ligne::Ligne(Coord const c1, Coord const c2, 
	string const couleur, 
	unsigned int const transparence): 	m_c1(c1), m_c2(c2), 
										m_couleur(couleur), 
										m_transparence(transparence)
{

}

// Afficheurs

void Ligne::printInfoLigne(ostream &flux) const
{
	flux << getCoord1() << " to " << getCoord2();
}

// Accesseurs
Coord Ligne::getCoord1(void) const
{
	return m_c1;
}

Coord Ligne::getCoord2(void) const
{
	return m_c2;
}

string Ligne::getCouleur(void) const
{
	return m_couleur;
}

unsigned int Ligne::getTransparence(void) const
{
	return m_transparence;
}

unsigned int Ligne::getLongueur(void) const
// Calcule et retourne la longueur de la ligne
// Si le repere de coordonnees est entier, alors le resultat est un uInt
{
	return (unsigned int)sqrt((double)pow(m_c2.getAbscisse() - m_c1.getAbscisse(), 2) 
		+ (double)pow(m_c2.getOrdonnee() - m_c1.getOrdonnee(), 2));
}

// DRAW
void swap(int a, int b)
{
	a=a+b;
	b=a-b;
	a=a-b;
}

void Ligne::draw(CImage *img)
// Algorithme général optimisé de trace de segment de Bresenham
{
	int dx, dy; // Distances

	// Coordonnées 
	int x0(getCoord1().getAbscisse());
	int y0(getCoord1().getOrdonnee());
	int x1(getCoord2().getAbscisse());
	int y1(getCoord2().getOrdonnee());

	// RGB / Couleur
	unsigned int r(getCouleur().getRed());
	unsigned int g(getCouleur().getGreen());
	unsigned int b(getCouleur().getBlue());

	/* 
		On remplace WindowDrawPoint par img->drawPixel
	*/

	if ((dx = x1 - x0) != 0)
	{
		if(dx > 0) // Vers la droite
		{
			if((dy = y1 - y0) != 0)
			{
				if(dy > 0) // vers le haut
				{
					// Vecteur oblique dans le premier quandran
					if(dx >= dy)
					{
						// Vecteur diagonal oblique proche de l'horizontale dans le 1er octant
						int e = dx;
						dx *= 2; // e est positif
						dy *= 2;
						while(true) // deplacements horizontaux
						{
							img->drawPixel(x0, y0, r, g, b); // Primitive poit le dessin du point
							if((++x0) == x1)
								break;
							if((e -= dy) < 0)
							{
								y0++; // deplacement diagonal
								e += dx;
							}
						}
					}
					else
					{
						// Vecteur oblique proche de la verticale, dans le 2nd octant
						int e = dy; // e est positif
						dy *= 2;
						dx *= 2;
						while(true) // Deplacements verticaux
						{
							img->drawPixel(x0, y0, r, g, b);
							if((++y0) == y1)
								break;
							if((e -= dx) < 0)
							{
								x0++; // deplacement diagonal
								e += dy;
							}
						}
					}
				}
				else // dy < 0 (et dx > 0)
				{
					// Vecteur oblique dans le 4e quadran
					if (dx >= -dy)
					{
						// Vecteur diagonal ou oblique proche de l'horizontale, dans le 8e octant
						int e = dx; // e est positif
						dx *= 2;
						dy *= 2;
						while(true) // deplacements horizontaux
						{
							img->drawPixel(x0, y0, r, g, b);
							
							if((++x0) == x1)
								break;
							if((e += dy) < 0)
							{
								y0--; // deplacement diagonal
								e += dx;
							}
						}
					}
					else
					{
						// Vecteur oblique proche de la verticale, dans le 7e octant
						int e = dy; // e est negatif
						dy *= 2;
						dx *= 2;
						while(true) //deplacements verticaux
						{
							img->drawPixel(x0, y0, r, g, b);
							if((--y0) == y1)
								break;
							if((e += dx) > 0)
							{
								x0++; // deplacement diagonal
								e += dy;
							}
						}
					}
				}
			}
			else // dy = 0 (et dx > 0)
			{
				do
				{
					img->drawPixel(x0, y0, r, g, b);
				}while((++x0) != x1);
			}
		}
		else // dx < 0
		{
			if((dy = y1 - y0) != 0)
			{
				if(dy > 0) // Vecteur oblique dans le 2nd quadran
				{
					if(-dx >= dy) // Vecteur diag ou oblique proche de l'horizontale, dans le 4eme octant
					{
						int e = dx;
						dx *= 2;
						dy *= 2;
						while(true) // deplacements horizontalaux
						{
							img->drawPixel(x0, y0, r, g, b);
							if((--x0) == x1)
								break;
							if ((e += dy) >= 0)
							{
								y0++; // deplacement diagonal
								e += dx;
							}
						}
					}
					else // vecteur oblique proche de la verticale, dans le 3e octant
					{
						int e = dy; // e est positif
						dy *= 2;
						dx *= 2;
						while(true) // deplacements verticaux
						{
							img->drawPixel(x0, y0, r, g, b);
							if((++y0) == y1)
								break;
							if ((e += dx) <= 0)
							{
								x0--; // deplacement diagonal
								e += dy;
							}
						}
					}
				}
				else // dy < 0 (et dx < 0)
					// vecteur oblique dans le 3e cadran
				{
					if(dx <= dy) // Vecteur diagonal ou oblique proche de l'horizontal, dans le 5e octant
					{
						int e = dx; // e est negatif
						dx *= 2;
						dy *= 2;
						while(true) // deplacements horizontaux
						{
							img->drawPixel(x0, y0, r, g, b);
							if((--x0) == x1)
								break;
							if((e -= dy) >= 0)
							{
								y0--; // deplacement diagonal
								e += dx;
							}
						}
					}
					else // vecteur oblique proche de la verticale, dans le 6e octant
					{
						int e = dy; // e est negatif
						dy *= 2;
						dx *= 2;
						while(true) // deplacements verticaux
						{
							img->drawPixel(x0, y0, r, g, b);
							if(--y0 == y1)
								break;
							if((e -= dx) >= 0)
							{
								x0--; // deplacement diagonal
								e += dy;
							}
						}
					}
				}
			}
			else // dy = 0 (et dx < 0)
				// Vecteur horizontal vers la gauche
			{
				do
				{
					img->drawPixel(x0, y0, r, g, b);
				}while(--x0 != x1);
			}
		}
	}
	else // dx = 0
	{
		if((dy = y1 - y0) != 0)
		{
			if(dy > 0) // Vecteur vertical croissant
			{
				do
				{
					img->drawPixel(x0, y0, r, g, b);
				}while(++y0 != y1);
			}
			else // dy < 0 (et dx = 0)
				// Vecteur vertical décroissant
			{
				do
				{
					img->drawPixel(x0, y0, r, g, b);
				}while(--y0 != y1);
			}
		}
		else	// c'est un point, donc un simple pixel
			img->drawPixel(x0, y0, r, g, b);
	}
}


/* // OLD VERSION
void Ligne::draw(CImage *img)
{
	int i;
	Coord c1(getCoord1()), c2(getCoord2());
	int a1(getCoord1().getAbscisse()), a2(getCoord2().getAbscisse());
	int o1(getCoord1().getOrdonnee()), o2(getCoord2().getOrdonnee());
	if(a1 == a2)
	// ligne verticale
	{
		if(o1 > o2)
			swap(o1, o2);

		// Verifier si ligne est dans le cadre

		for (i = o1; i < o2; i++)
		{
			CPixel *p = img->getPixel(a1, i);
			p->RGB(getCouleur().getRed(), getCouleur().getGreen(), getCouleur().getBlue());
		}
	}
	else if(o1 == o2)
	// ligne horizontale
	{
		if(a1 > a2)
			swap(a1, a2);

		// Verifier si ligne est dans le cadre

		for (i = a1; i < a2; i++)
		{
			CPixel *p = img->getPixel(i, o1);
			p->RGB(getCouleur().getRed(), getCouleur().getGreen(), getCouleur().getBlue());
		}
	}
	else if (abs(o2 - o1) == abs(a2 - a1))
	{
		int distance = abs(o2 - o1);
		// Verifier si ligne est dans le cadre

		// Point de depart de la ligne
		for (i = 0; i < distance; i++)
		{
			CPixel *p = img->getPixel(i, i);
		}
	}
	else // cas ligne inclinee
	{

	}
}*/ // OLD VERSION



// Opérateurs
ostream &operator<<(ostream &flux, Ligne const &l)
{
    l.printInfoLigne(flux);
    return flux;
}

// Fonction diverses
