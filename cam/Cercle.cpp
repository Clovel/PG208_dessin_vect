// Camille Magnan & Clovis Durand
// Dessin vectoriel

#include "Cercle.h"
using namespace std;

//Constructeur/Destructeur
Cercle::Cerle(): m_rayon(0)
{
	//Par défaut
}

Cercle::Cercle(Coord c,
	unsigned int rayon,
	Couleur const couleur, 
	unsigned int const transparence);
{
	setC(c);
	setRayon(rayon);
	setCouleur(couleur);
	setTransparence(transparence);
}

//Afficheurs

//Accesseurs

Coord Cercle::getC(){

	return m_c;
}

unsigned int Cercle::getRayon(){

	return m_rayon;
}

string Cercle::getCouleur(){

	return m_couleur;
}

unsigned int Cercle::getTransparence(){

	return m_transparence;
}

//Mutateurs

void Cercle::setC(Coord c){

	m_c = c;
}

void Cercle::setRayon(unsigned int rayon){

	m_rayon = rayon;
}

void Cercle::setCouleur(string couleur){

	m_couleur = couleur ;
}

void Cercle::setTransparence(unsigned int transparence){

	m_transparence = transparence;
}

// DRAW


void Cercle::draw(CImage *img)

{
	int dx; // Distance

	// Coordonnées 
	int x(getCoord().getAbscisse());
	int y(getCoord().getOrdonnee());
	int xmin;
	int ymin;
	int xmax;
	int ymax;

	if ((x - rayon) < 0){
		xmin = 0;
	}
	else {
		xmin = x - rayon;
	}
	if ((x + rayon) > 1024){
		xmax = 1024;
	}
	else {
		xmax = x + rayon;
	}
	
	if ((y - rayon) < 0){
		ymin = 0;
	}
	else
}
