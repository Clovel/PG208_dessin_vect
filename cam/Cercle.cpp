// Camille Magnan & Clovis Durand
// Dessin vectoriel

#include "Cercle.h"
using namespace std;

//Constructeur/Destructeur

Cercle::Cercle(Coord c,
	unsigned int rayon,
	std::string const couleur, 
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

int Cercle::getRayon(){

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

	m_transparence = transparence;
}

void Cercle::setCouleur(string couleur){

	m_couleur = couleur ;
}

void Cercle::setTransparence(unsigned int transparence){

	m_transparence = transparence;
}




