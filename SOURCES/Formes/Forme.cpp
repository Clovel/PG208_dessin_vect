// Clovis Durand & Camille Magnan
// ENSEIRB-Matmeca, E2
// 2017

// PG208 - Projet Dessin Vectoriel

// Forme.cpp
// Forme class source file. 

#include "../../HEADERS/Formes/Forme.h"
using namespace std;






// Accesseurs
Coord Forme::getCoord1(void) const
{
	return m_c1;
}

Couleur Forme::getCouleur(void) const
{
	return m_couleur;
}

unsigned int Forme::getTransparence(void) const
{
	return m_transparence;
}