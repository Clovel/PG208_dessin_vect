// Clovis Durand & Camille Magnan
// ENSEIRB-Matmeca, E2
// 2017

// PG208 - Projet Dessin Vectoriel

// Carre_p.cpp
// Carre_p class source file. 

#include "../../HEADERS/Formes/Carre.h"
using namespace std;

Carre_p::Carre_p(Coord const c1, 
	unsigned int const c, 
	string const couleur, 
	unsigned int transparence) : Rectangle_p(c1, c, c, couleur, transparence)
{

}