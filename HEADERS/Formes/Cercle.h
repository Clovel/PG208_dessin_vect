// Camille Magnan & Clovis Durand
// Dessin vectoriel

#ifndef CERCLE_H
#define CERCLE_H

#include "Forme.h"

class Cercle : public Forme
{
public :

	// Constructeur
	Cercle();
	Cercle(Coord const c, 
		unsigned int const rayon, 
		std::string const couleur, 
		unsigned int const transparence);

	// Afficheurs

	// Accesseurs
	unsigned int getRayon(void) const;

	// Mutateurs
	void setRayon(unsigned int const &rayon);

	// Draw
	void draw(CImage *img);

	//void drawfull(CImage *Image);

	// Méthodes publiques Diverses

private:
	// Attributs/Variables membres
	unsigned int m_rayon;

	// Méthodes privées diverses 

};

#endif //CERCLE_H