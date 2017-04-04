// Camille Magnan & Clovis Durand
// Dessin vectoriel

#include "../../HEADERS/Formes/Carre.h"

Carre::Carre(Coord c1, 
  	unsigned int cote, 
  	std::string const couleur, 
  	unsigned int const transparence) :
  	Rectangle(c1, cote, cote, couleur, transparence)
{

}