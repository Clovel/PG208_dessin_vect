// Camille Magnan & Clovis Durand
// Dessin vectoriel

#ifndef POINT_H
#define POINT_H

#include <string>
#include <cmath>
#include "Coord.h"

class Point
{
public :

//Constructeur
	Point(Coord c1, std::string const couleur, unsigned int const transparence)

//Afficheurs
	void print_info_point(void) const;

// Accesseurs
	Coord getCoord(void) const;
	std::string getCouleur(void) const;
	unsigned int getTransparence(void) const;

// Mutateurs
	void setCoord(Coord const &c1);
	void setCouleur(std::string const &couleur);
	void setTransparence(unsigned int const &transparence);

private :
	
	Coord m_c1;
	string m_couleur;
	unsigned int m_transparence;


}