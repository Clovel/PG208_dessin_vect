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

typedef RGB
{
	unsigned int r; 
	unsigned int g; 
	unsigned int b;
}RGB_t;

class Forme
{
public:
	// Con/Destructeurs
	Forme();
	Forme(Coord const c1, 
		  std::string const couleur,
		  unsigned int const transparence);
	Forme(Coord const c1, 
	    unsigned int const R = 255,
	    unsigned int const G = 255,
	    unsigned int const B = 255,
	    unsigned int const transparence);

	// Accesseurs
	Coord getCoord1(void) const;
	unsigned int getRed(void) const;
	unsigned int getGreen(void) const;
	unsigned int getBlue(void) const;
	unsigned int getTransparence(void) const;

	// Mutateurs
	void setCoord1(Coord const &c1);
	void setCouleur(std::string const &couleur);
	void setCouleur(unsigned int &R, unsigned int &G, unsigned int &B);
	void setTransparence(unsigned int const &transparence);

	// rajouter transparence


private:
	Coord m_c1;
	std::string m_couleur;
    unsigned int m_R, m_G, m_B;
    unsigned int m_transparence;

	// Méthodes privées diverses
    RGB_t Forme::getRGB(void) const; // Traduction string -> RGB
};



#endif //FORME_H