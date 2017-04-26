// Clovis Durand & Camille Magnan
// ENSEIRB-Matmeca, E2
// 2017

// PG208 - Projet Dessin Vectoriel

// Ractangle.h
// Rectangle class header file. 

#ifndef CARRE_H
#define CARRE_H

#include "Ligne.h"

class Rectangle : public Forme
{
public :

	//Constructeur
	Rectangle(Coord const c1, 
		unsigned int const cote, 
		std::string const couleur, 
		unsigned int const transparence);

	Rectangle(Ligne const l1, 
		int const dist, 
		std::string const couleur, 
		unsigned int const transparence);


	// Afficheurs

	// Accesseurs
	Ligne getLigne1(void);

	// Mutateurs
	void setLigne1(Ligne const &l);

	// Draw
	void draw(CImage *img);

	// Méthodes publiques diverses


private :
	// Variables membres/attributs
	// ATTENTION, PAS D'ORDRE PARTICULIER POUR LES LIGNES
	Ligne m_l1;
	Ligne m_l2;
	Ligne m_l3;
	Ligne m_l4;
	std::string m_couleur;

	// Méthodes privées diverses
	void calcul_lignes(unsigned int const &cote);
	void calcul_lignes(int const &dist);
};

// Opérateurs

// Fonctions exterieures a la classe


#endif // RECTANGLE_H

