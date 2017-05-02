// Camille Magnan & Clovis Durand
// Dessin vectoriel

#ifndef CERCLE_2.H
#define CERCLE_2.H

#include "Forme.h"

class Cercle : public Forme
{
public :

	// Constructeur
	Cercle();
	Cercle(Coord c, int rayon, std::string couleur, int transparence);

	// Afficheurs

	// Accesseurs

	// Mutateurs

	// Draw
	draw(CImage* Image);

	// Méthodes publiques Diverses

private:
	// Attributs/Variables membres
	unsigned int m_rayon;

	// Méthodes privées diverses 

};