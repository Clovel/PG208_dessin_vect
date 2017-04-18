// Camille Magnan & Clovis Durand
// PG208 - Projet Dessin Vectoriel

#ifndef LIGNE_H // Pour ne pas l'inclure plusieurs fois
#define LIGNE_H

#include <string>
#include <cmath>
#include <iostream>
#include "../image/CImage.h"
#include "../Others/Coord.h" 	// Point mathématique
#include "../Others/Couleur.h"	// Couleur
//#include "Forme.h"				// Pour heritage

// ATTENTION, heritage pas encore implemente

class Ligne //: public Forme
{
public:
	// Con/Destructeurs
	Ligne();
	Ligne(Coord const c1, 
		  Coord const c2, 
		  std::string const couleur,
		  unsigned int const transparence);

	// Afficheurs
	void printInfoLigne(std::ostream &flux) const;

	// Accesseurs
	Coord getCoord1(void) const;
	Coord getCoord2(void) const;
	Couleur getCouleur(void) const;
	unsigned int getTransparence(void) const;
	unsigned int getLongueur(void) const;

	// Mutateurs
	void setCoord(Coord const &c1, Coord const &c2);
	void setCouleur (std::string const &couleur);
	void setTransparence(unsigned int const &transparence);

	// Méthodes publiques Diverses
	void swap(int a, int b);
	void draw(CImage *img);

private:
	// Attributs/Variables membres
	Coord m_c1, m_c2;
	Couleur m_couleur;
	unsigned int m_transparence;

	// Méthodes privée diverses 
};

// Opérateurs
std::ostream &operator<<(std::ostream &flux, Ligne const &l);

// Passage par reference (avec &) pour eviter 
	// de recopier les variables pour rien


#endif // LIGNE_H