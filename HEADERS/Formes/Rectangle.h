// Camille Magnan & Clovis Durand
// Dessin vectoriel

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <string>
#include <cmath>
#include "../Coord.h"
#include "Ligne.h"

class Rectangle
{
public :

//Constructeur
	Rectangle(Coord c1, 
		unsigned int longueur, 
		unsigned int hauteur,  
		std::string const couleur, 
		unsigned int const transparence);

//Afficheurs
	//void print_info_rectangle(void) const;

// Accesseurs
	Coord getC1(void) const;
	std::string getCouleur() const;
	unsigned int getTransparence() const;

// Mutateurs
	void setC1(Coord const &c1);
	void setCouleur(std::string const &couleur);
	void setTransparence(unsigned int const &transparence);

// Méthodes publiques diverses


private :

// le premier point est en bas à gauche, ensuite j'évolue dans le sens des aiguilles d'une montre



// Variables membres aussi appelées attribus 	
	Coord m_c1;
	Ligne m_l1;
	Ligne m_l2;
	Ligne m_l3;
	Ligne m_l4;
	std::string m_couleur;
	unsigned int m_transparence;
	//unsigned int m_longueur;
	//unsigned int m_thauteur;

// Méthodes privées diverses
	void calcul_lignes(Coord const &c1, 
		unsigned int const &longueur, 
		unsigned int const &hauteur);
};

// Opérateurs

// Fonctions exterieures a la classe


#endif // RECTANGLE_H