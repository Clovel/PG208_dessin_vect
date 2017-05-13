// Clovis Durand & Camille Magnan
// ENSEIRB-Matmeca, E2
// 2017

// PG208 - Projet Dessin Vectoriel

// Dessin.h
// Dessin class header file. 

#ifndef DESSIN_H
#define DESSIN_H

#include "../Formes/Forme.h"
#include "../image/CImage.h"
#include <vector>

class Dessin
{
public:
	// Con/Destructeur
	Dessin();

	// Accesseurs
	Forme *getFormeFromIdx(unsigned int const &index) const;
	vector<Forme *> getFormes(void) const;

	// Mutateurs
	void setForme(Forme *f, unsigned int const &index);
	void addForme(Forme *f);

	// Fonctions publiques diverses
	void drawAll(CImage *img) const;

private:
	vector<Forme *> m_formes; // Va contenir toutes les formes
};

#endif // DESSIN_H

// On utlise des "Formes *" car Forme est une classe dite "Absraite" 