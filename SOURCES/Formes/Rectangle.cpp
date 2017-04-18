// Camille Magnan & Clovis Durand
// Dessin vectoriel

#include "../../HEADERS/Formes/Rectangle.h"
using namespace std;

// Con/Destructeur
Rectangle::Rectangle(Coord const c1, 
	unsigned int const longueur, 
	unsigned int const hauteur,  
	Couleur const couleur, 
	unsigned int const transparence)
{
	setCoord1(c1);
	setCouleur(couleur);
	setTransparence(transparence);
	calcul_lignes(longueur, hauteur);
}

// Afficheurs

// Accesseurs

// Mutateurs

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


// Opérateurs

// Fonctions exterieures a la classe
