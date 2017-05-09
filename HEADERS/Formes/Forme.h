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
#include "../image/CImage.h"	// Pour dessiner (sert pour les descendants de class Forme)

#define MIN( X, Y ) ((X < Y) ? X : Y)
#define MAX( X, Y ) ((X > Y) ? X : Y)

//#define DEBUG

// Sert a retourner 3 uInt en sortie d'une f°
typedef struct RGB
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

	// Accesseurs
	Coord getCoord1(void) const;
	std::string getCouleur(void) const;
	unsigned int getTransparence(void) const;
	RGB_t getRGB(void) const; // Traduction string -> RGB

	// Mutateurs
	void setCoord1(Coord const &c1);
	void setCouleur(std::string const &couleur);
	void setTransparence(unsigned int const &transparence);

	// rajouter transparence
	void RGB_t applyTransparency(int const x, int const y);

private:
	Coord m_c1;
	std::string m_couleur;
    unsigned int m_transparence;

	// Méthodes privées diverses
    
};



#endif //FORME_H

// Template [A SUPPRIMER AVANT LA FIN DU PROJET]
/*
	// Con/Destructeurs

	// Afficheurs

	// Accesseurs

	// Mutateurs

	// Draw

	// Méthodes publiques Diverses

	// Attributs/Variables membres

	// Méthodes privées diverses 
*/