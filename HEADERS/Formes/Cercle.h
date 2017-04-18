// Camille Magnan & Clovis Durand
// Dessin vectoriel

#ifndef CERCLE_H
#define CERCLE_H


#include <string>
#include <cmath>
#include "../Others/Coord.h"

class Cercle
{
public :

//Constructeur
	Cercle(Coord const c,
		   unsigned int const rayon,
		   std::string const couleur, 
		   unsigned int const transparence);

//Afficheurs

//Accesseurs
	Coord getC(void) const;
	unsigned int getRayon(void) const;
	std::string getCouleur(void) const;
	unsigned int getTransparence(void) const;

// Mutateurs
	void setC(Coord const &c);
	void setRayon(unsigned int const &rayon);
	void setCouleur(std::string const &couleur);
	void setTransparence(unsigned int const &transparence);

//Méthodes publiques diverses

private :
// Variables membres aussi appelées attribus
	Coord m_c;
	std::string m_couleur;
	unsigned int m_rayon;
	unsigned int m_transparence;	

};

#endif //CERCLE_H