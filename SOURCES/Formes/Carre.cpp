// Clovis Durand & Camille Magnan
// ENSEIRB-Matmeca, E2
// 2017

// PG208 - Projet Dessin Vectoriel

// Carre.cpp
// Carre class header file. 

#include "../../HEADERS/Formes/Carre.h"
using namespace std;

Carre::Carre(Coord const c1, 
	unsigned int const c, 
	string const couleur, 
	unsigned int transparence) : Rectangle(c1, c, c, couleur, transparence)
{

}