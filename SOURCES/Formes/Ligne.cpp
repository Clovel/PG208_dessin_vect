// Camille Magnan & Clovis Durand
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

// Méthodes privées diverses



// Opérateurs
ostream &operator<<(ostream &flux, Ligne const &l)
{
    l.printInfoLigne(flux);
    return flux;
}

// Fonction diverses
