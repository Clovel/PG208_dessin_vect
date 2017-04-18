// Camille Magnan & Clovis Durand
// Dessin vectoriel

#ifndef CERCLE_H
#define CERCLE_H


#include <string>
#include <cmath>
#include "../Coord.h"
#include "Forme.h"

class Cercle : public Forme
{
public :

//Constructeur
	Cercle(Coord c,
		   unsigned int rayon,
		   Couleur const couleur, 
		   unsigned int const transparence);

//Afficheurs

//Accesseurs
	Coord getC(void);
	unsigned int getRayon(void);
	Couleur getCouleur(void);
	unsigned int getTransparence(void);

// Mutateurs
	void setC(Coord const &c);
	void setRayon(unsigned int &rayon)	
	void setCouleur(Couleur const &couleur);
	void setTransparence(unsigned int &transparence);

//Méthodes publiques diverses

private :
// Variables membres aussi appelées attribus
	Coord m_c;
	Couleur m_couleur;
	unsigned int m_rayon;
	unsigned int m_transparence;	

}