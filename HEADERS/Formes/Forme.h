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
		  std::string const couleur,
		  unsigned int const transparence);

	// Accesseurs
	Coord getCoord1(void) const;
	std::string getCouleur(void) const;
	int getRed(void);
	int getGreen(void);
	int getBlue(void);
	unsigned int getTransparence(void) const;

	// Mutateurs
	void setCoord1(Coord const &c1);
	void setRGBcouleur (std::string const &couleur);
	void setTransparence(unsigned int const &transparence);
	void setCouleur(std::string const &couleur)

	// rajouter transparence


private:
	Coord m_c1;
	unsigned int m_transparence;
	string m_couleur;
    int m_R,m_G,m_B;
};

#endif //FORME_H