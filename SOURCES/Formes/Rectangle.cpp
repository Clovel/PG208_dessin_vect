// Camille Magnan & Clovis Durand
// Dessin vectoriel

#include "../../HEADERS/Formes/Rectangle.h"
using namespace std;

// Con/Destructeur
Rectangle::Rectangle(Coord const c1, 
	unsigned int const longueur, 
	unsigned int const hauteur,  
	string const couleur, 
	unsigned int const transparence)
{
	setC1(c1);
	setCouleur(couleur);
	setTransparence(transparence);
	calcul_lignes(m_c1, longueur, hauteur);
}

// Afficheurs

// Accesseurs

Coord Rectangle::getC1() const
{
	return m_c1;
}

string Rectangle::getCouleur() const
{
	return m_couleur;
}

unsigned int Rectangle::getTransparence() const
{
	return m_transparence;
}

// Mutateurs

void Rectangle::setC1(Coord const &c1)
{
	m_c1 = c1;
}

void Rectangle::setCouleur(string const &couleur)
{
	m_couleur = couleur;
}

void Rectangle::setTransparence(unsigned int const &transparence)
{
	m_transparence = transparence;
}

// Méthodes publiques diverses

// Méthodes privées diverses
void Rectangle::calcul_lignes(Coord const &c1, 
	unsigned int const &longueur, 
	unsigned int const &hauteur)
{
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
