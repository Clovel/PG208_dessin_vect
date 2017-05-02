// Clovis Durand & Camille Magnan
// ENSEIRB-Matmeca, E2
// 2017

// PG208 - Projet Dessin Vectoriel

// Rectangle.cpp
// Rectangle class source file. 

#include "../../HEADERS/Formes/Rectangle.h"
using namespace std;

// Con/Destructeur
Rectangle::Rectangle(Coord const c1, 
	unsigned int const longueur, 
	unsigned int const hauteur,  
	string const couleur, 
	unsigned int const transparence)
{
	// Droit
	setCoord1(c1);
	setRGBcouleur(couleur);
	setTransparence(transparence);
	setCouleur(couleur);
	calcul_lignes(longueur, hauteur);
}

Rectangle::Rectangle(Ligne const l1, 
	int const dist, 
	string const couleur, 
	unsigned int const transparence)
{
	// De biais
	setLigne1(l1);
	setCoord1(l1.getCoord1());
	setRGBcouleur(couleur);
	setCouleur(couleur);
	setTransparence(transparence);
	calcul_lignes(dist);
}

// Afficheurs

// Accesseurs
Ligne Rectangle::getLigne1(void)
{
	return m_l1;
}

// Mutateurs
void Rectangle::setLigne1(Ligne const &l)
{
	m_l1 = l;
}

// Draw
void Rectangle::draw(CImage *img)
{
	m_l1.draw(img);
	m_l2.draw(img);
	m_l3.draw(img);
	m_l4.draw(img);
}

// Méthodes publiques diverses

// Méthodes privées diverses
void Rectangle::calcul_lignes(unsigned int const &longueur, unsigned int const &hauteur)
{
	Coord c1 = getCoord1();
	Coord c2(c1.getAbscisse(), c1.getOrdonnee() + hauteur);
	Coord c3(c1.getAbscisse() + longueur, c1.getOrdonnee() + hauteur);
	Coord c4(c1.getAbscisse() + longueur, c1.getOrdonnee());

	m_l1 = Ligne(c1, c2, getCouleur(), getTransparence());
	m_l2 = Ligne(c2, c3, getCouleur(), getTransparence());
	m_l3 = Ligne(c3, c4, getCouleur(), getTransparence());
	m_l4 = Ligne(c4, c1, getCouleur(), getTransparence());
}

void Rectangle::calcul_lignes(int const &dist)
// Pour rectangle de biais (avec angle)
{
	int opp 		= getLigne1().getCoord2().getOrdonnee() - getLigne1().getCoord1().getOrdonnee();
	int adj 		= getLigne1().getCoord2().getAbscisse() - getLigne1().getCoord1().getAbscisse();
	double angle 	= asin((double(opp))/(double(adj)));

	int y 			= int(getLigne1().getCoord1().getOrdonnee() + cos(angle) * dist);
	int x 			= int(getLigne1().getCoord1().getAbscisse() - sin(angle) * dist);
	Coord c2 		= Coord(x, y);

	m_l2 			= Ligne(getLigne1().getCoord1(), c2, getCouleur(), getTransparence());

	y 				= int(getLigne1().getCoord2().getOrdonnee() + cos(angle) * dist);
	x 				= int(getLigne1().getCoord2().getAbscisse() - sin(angle) * dist);
	Coord c3		= Coord(x, y);

	m_l3 			= Ligne(getLigne1().getCoord2(), c3, getCouleur(), getTransparence());

	m_l4 			= Ligne(c2, c3, getCouleur(), getTransparence());
}

// Opérateurs

// Fonctions exterieures a la classe
