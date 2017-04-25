// Camille Magnan & Clovis Durand
// Dessin vectoriel

#ifndef CERCLE_H
#define CERCLE_H


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
	Cercle(Coord _c, int rayon, std::string couleur, int transparence);
	dessinerFull(CImage* Image);
	dessiner(CImage* Image);

// attribus
int m_rayon;


}