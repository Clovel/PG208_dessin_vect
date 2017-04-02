// Camille Magnan & Clovis Durand
// PG208 - Projet Dessin Vectoriel

// Ligne.cpp
// Definition des méthodes relatives a 

#include "../../HEADERS/Formes/Ligne.h"

// Con/Destructeur

Ligne::Ligne(int const x1, 
	int const y1, 
	int const x2, 
	int const y2, 
	string const couleur, 
	unsigned int const transparence): m_x1(x1), m_y1(y1), m_x2(x2), m_y2(y2),
										m_couleur(couleur), m_transparence(transparence)
{

}

// Afficheurs

void printInfoLigne(void) const
{

}

// Accesseurs

void getCoord(void) const
{
	vector<int> coord(4) = {m_x1, m_y1, m_x2, m_y2};
	return coord;
}

void getCouleur(void) const
{
	return m_couleur;
}

void getTransparence(void) const
{
	return m_transparence;
}

void getLongueur(void) const
{

}

// Méthodes pirvées diverses

double longueur(void) const
{
	return sqrt((double)pow(m_x2 - m_x1, 2) + (double)pow(m_y2 - m_y1, 2));
}