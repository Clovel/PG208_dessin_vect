// Camille Magnan & Clovis Durand
// Dessin vectoriel

#include "Rectangle.h"
using namespace std;

// Con/Destructeur
Rectangle::Rectangle(Coord const c1, 
	unsigned int const longueur, 
	unsigned int const hauteur,  
	string const couleur, 
	unsigned int const transparence)
{
	setC1( c1 );
	setLongueur( longueur );
	setHauteur( hauteur );
	setCouleur( couleur );
	setTransparence( transparence );
	calcul_lignes(m_c1)
}

// Afficheurs

// Accesseurs

Coord Rectangle::getC1(){

	return m_c1;
}

int Rectangle::getLongueur(){

	return m_longueur;
}

int Rectangle::getHauteur(){

	return m_hauteur;
}

string Rectangle::getCouleur(){

	return m_couleur;
}

unsigned int Rectangle::getTransparence(){

	return m_transparence;
}

// Mutateurs

void Rectangle::setC1(Coord c1)
{

	m_c1 = c1;
}

void Rectangle::setLongueur(unsigned int longueur)
{

	m_longueur = longueur;
}

void Rectangle::setHauteur(unsigned hauteur)
{

	m_hauteur = hauteur
}

void Rectangle::setCouleur(string couleur)
{

	m_couleur = couleur;
}

void Rectangle::setTransparence(unsigned int transparence)
{

	m_transparence = transparence;
}

// Méthodes publiques diverses

// Méthodes privées diverses
void Rectangle::calcul_lignes(Coord const &c1)
{
	Coord c2(c1.getAbscisse(), c1.getOrdonnee() + hauteur);
	Coord c3(c1.getAbscisse() + longueur, c1.getOrdonnee() + hauteur);
	Coord c4(c1.getAbscisse() + longueur, c1.getOrdonnee());
	Ligne l1(c1, c2, getCouleur(), getTransparence());
	Ligne l2(c2, c3, getCouleur(), getTransparence());
	Ligne l3(c3, c4, getCouleur(), getTransparence());
	Ligne l4(c4, c1, getCouleur(), getTransparence());
	m_l1 = l1;
	m_l2 = l2;
	m_l3 = l3;
	m_l4 = l4;
}


// Opérateurs

// Fonctions exterieures a la classe
