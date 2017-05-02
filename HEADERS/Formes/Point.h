// Camille Magnan & Clovis Durand
// Dessin vectoriel

#ifndef POINT.H
#define POINT.H


#include <string>
#include <cmath>
#include <iostream>
#include "../image/CImage.h"
#include "../Others/Coord.h" 
#include "Forme.h"

class Point : public Forme
{
public :

// Constructeur
	Point();
	Point(Coord c, std::string couleur, int transparence);
	dessiner(CImage* Image);

};