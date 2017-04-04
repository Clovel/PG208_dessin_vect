// Camille Magnan & Clovis Durand
// PG208 - Projet Dessin Vectoriel

#ifndef LIGNE_H // Pour ne pas l'inclure plusieurs fois
#define LIGNE_H

#include <string>
#include <cmath>
#include <iostream>
#include "../Coord.h" // Point mathématique

class Ligne
{
public:
	// Con/Destructeurs
	/*Ligne(int const x1, 
		int const y1, 
		int const x2, 
		int const y2, 
		std::string const couleur, 
		unsigned int const transparence);*/
	Ligne(Coord const c1, 
		  Coord const c2, 
		  std::string const couleur,
		  unsigned int transparence);

	// Afficheurs
	void printInfoLigne(ostream &flux) const;

	// Accesseurs
	Coord getCoord(void) const;
	std::string getCouleur(void) const;
	unsigned int getTransparence(void) const;
	double getLongueur(void) const;

	// Mutateurs
	void setCoord(Coord const &c1, Coord const &c2);
	void setCouleur (std::string const &couleur);
	void setTransparence(unsigned int const &transparence);

	// Méthodes publiques Diverses

private:
	// Attributs/Variables membres
	Point p1, p2;
	std::string m_couleur;
	unsigned int m_transparence;

	// Méthodes privée diverses 
	double longueur(void) const; // Retourne la longueur de la ligne
};


// Passage par reference (avec &) pour eviter 
	// de recopier les variables pour rien


#endif // LIGNE_H