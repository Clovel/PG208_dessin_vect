// Clovis Durand & Camille Magnan
// ENSEIRB-Matmeca, E2
// 2017

// PG208 - Projet Dessin Vectoriel

// Forme.h
// Forme class header file. 

#ifndef FORME_H // Pour ne pas l'inclure plusieurs fois
#define FORME_H

#include <string>
#include <cmath>
#include <iostream>
#include "../Others/Coord.h" 	// Point mathématique
#include "../Others/Couleur.h" 	// Couleur

class Forme
{
public:
	// Con/Destructeurs
	Forme();
	Forme(Coord const c1, 
		  Couleur const couleur,
		  unsigned int const transparence);

	// Accesseurs
	Coord getCoord1(void) const;
	Couleur getCouleur(void) const;
	unsigned int getTransparence(void) const;

	// Mutateurs
	void setCoord1(Coord const &c1);
	void setCouleur (Couleur const &couleur);
	void setTransparence(unsigned int const &transparence);


	// Méthode
	void getRGBcolor();
	// rajouter transparence


private:
	Coord m_c1;
	Couleur m_couleur;
	unsigned int m_transparence;
	int R,G,B;
};

#endif //FORME_H