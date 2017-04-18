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
}



// Opérateurs
ostream &operator<<(ostream &flux, Ligne const &l)
{
    l.printInfoLigne(flux);
    return flux;
}

// Fonction diverses
