// Camille Magnan & Clovis Durand
// Dessin vectoriel

#ifndef CERCLE_2.H
#define CERCLE_2.H


#include <string>
#include <cmath>
#include <iostream>
#include "../image/CImage.h"
#include "../Others/Coord.h" 
#include "Forme.h"

class Cercle : public Forme
{
public :

// Constructeur
	Cercle(Coord c, int rayon, std::string couleur, int transparence);
	dessinerFull(CImage* Image);
	dessiner(CImage* Image);

// attribus
unsigned int m_rayon;

}