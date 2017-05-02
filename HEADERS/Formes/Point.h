// Clovis Durand & Camille Magnan
// ENSEIRB-Matmeca, E2
// 2017

// PG208 - Projet Dessin Vectoriel

// Point.h
// Point class header file. 

#ifndef POINT.H
#define POINT.H

#include "Forme.h"

class Point : public Forme
{
public :
	// Con/Destructeurs
	Point();
	Point(Coord c, std::string couleur, int transparence);
	// Afficheurs

	// Accesseurs

	// Mutateurs

	// Draw
	draw(CImage* Image);

	// Méthodes publiques Diverses

//private:
	// Attributs/Variables membres

	// Méthodes privées diverses 
};