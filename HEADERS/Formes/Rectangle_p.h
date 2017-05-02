/*// Clovis Durand & Camille Magnan
// ENSEIRB-Matmeca, E2
// 2017

// PG208 - Projet Dessin Vectoriel

// Ractangle.h
// Rectangle class header file. 

#ifndef RECTANGLE_P_H
#define RECTANGLE_P_H

#include "Forme.h"

class Rectangle_P : public Forme
{
public :

	//Constructeur
	Rectangle_p(Coord const c1, 
		unsigned int const longueur, 
		unsigned int const hauteur,  
		std::string const couleur, 
		unsigned int const transparence);

	Rectangle_p(Ligne const l1, 
		int const dist, 
		std::string const couleur, 
		unsigned int const transparence);



	// Afficheurs

	// Accesseurs
	Ligne getLigne1(void);

	// Mutateurs
	void setLigne1(Ligne const &l);

	// Coordonnés

	// Draw
	void color(CImage *img);


	// Méthodes publiques diverses


private :
	unsigned int const longueur;
	unsigned int const hauteur;
// Méthodes privées diverses


// Opérateurs

// Fonctions exterieures a la classe


#endif 
*/

	// Clovis Durand & Camille Magnan
// ENSEIRB-Matmeca, E2
// 2017

// PG208 - Projet Dessin Vectoriel

// Rectangle_p.h
// Rectangle_p class header file. 

#include "Rectangle_p.h"


class Rectangle_p : public Rectangle
{
public:
	// Con/Destructeurs

	Rectangle_p(Coord const c1, 
	unsigned int const longueur, 
	unsigned int const hauteur,  
	std::string const couleur, 
	unsigned int const transparence);


	// Afficheurs

	// Accesseurs

	// Mutateurs

	// Draw
	draw(CImage* Image);

	// Méthodes publiques Diverses

//private:
	// Attributs/Variables membres

	// Méthodes privées diverses 
}