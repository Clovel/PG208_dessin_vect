// Clovis Durand & Camille Magnan
// ENSEIRB-Matmeca, E2
// 2017

// PG208 - Projet Dessin Vectoriel

// Rectangle_v2.h
// Rectangle_v2 class header file. 

#ifndef RECTANGLE_V2_H
#define RECTANGLE_V2_H

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


#endif // RECTANGLE_V2_H