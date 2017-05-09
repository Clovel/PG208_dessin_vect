// Clovis Durand & Camille Magnan
// ENSEIRB-Matmeca, E2
// 2017

// PG208 - Projet Dessin Vectoriel

// Dessin.h
// Dessin class header file. 

#ifndef DESSIN_H
#define DESSIN_H

#include "../Formes/Forme.h"
#include <vector>

class Dessin
{
public:
	// Con/Destructeur
	Dessin();

	// Accesseurs
	Forme getForme(unsigned int const &index) const;
	vector<Forme> getVectorForme(void) const;

	// Mutateurs
	void setForme(Forme const &f, unsigned int const &index);
	void addForme(Forme const &f);

private:
	vector<Forme> m_formes; // Va contenir toutes les formes
};

#endif // DESSIN_H