// Camille Magnan & Clovis Durand
// Dessin vectoriel

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <string>
#include <cmath>
#include "../Others/Coord.h"
#include "../Others/Couleur.h"
#include "Forme.h"
#include "Ligne.h"

class Rectangle : public Forme
{
public :

	//Constructeur
	Rectangle(Coord c1, 
		unsigned int longueur, 
		unsigned int hauteur,  
		Couleur const couleur, 
		unsigned int const transparence);

	// Afficheurs

	// Accesseurs

	// Mutateurs

	// Draw
	void draw(CImage *img);

	// Méthodes publiques diverses


private :

	// le premier point est en bas à gauche, ensuite j'évolue dans le sens des aiguilles d'une montre



	// Variables membres aussi appelées attribus
	Ligne m_l1;
	Ligne m_l2;
	Ligne m_l3;
	Ligne m_l4;

	// Méthodes privées diverses
	void calcul_lignes(unsigned int const &longueur, unsigned int const &hauteur);
};

// Opérateurs

// Fonctions exterieures a la classe


#endif // RECTANGLE_H