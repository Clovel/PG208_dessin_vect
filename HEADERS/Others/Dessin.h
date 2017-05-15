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
#include "Coord.h" 		// Coordonnées
#include <vector>
#include <string> 		// Pour : stoi
#include <fstream>

//Includes des classes de formes
#include "../Formes/Ligne.h"
#include "../Formes/Rectangle.h"
#include "../Formes/Rectangle_p.h"
#include "../Formes/Triangle.h"
#include "../Formes/Cercle.h"
#include "../Formes/Cercle_p.h"
#include "../Formes/Carre.h"
#include "../Formes/Carre_p.h"
#include "../Formes/Point.h"

#define DEBUG

class Dessin
{
public:
	// Con/Destructeur
	Dessin();
	~Dessin();

	// Accesseurs
	Forme *getFormeFromIdx(unsigned int const &index) const;
	vector<Forme *> getFormes(void) const;
	vector<unsigned int> getH(void) const;
	vector<unsigned int> getL(void) const;

	// Mutateurs
	void setForme(Forme *f, unsigned int const &index);
	void addForme(Forme *f);
	void addH(unsigned int const &a);
	void addL(unsigned int const &a);

	// Fonction Load depuis un fichier .vec
	bool loadVec(string const &filename);

	// Fonctions publiques diverses
	void drawAll(CImage *img) const;
	void printVector(vector<unsigned int> a) const;

private:
	vector<Forme *> m_formes; // Va contenir toutes les formes

	// Définition de la taille de l'image
	// Pour la hauteur
	vector<unsigned int> m_h;

	// Pour la largeur
	vector<unsigned int> m_l;


	// Fonctions privées diverses
	Forme *loadForme(string ligne);
	void bubbleSort(vector<unsigned int>& a);
};

#endif // DESSIN_H

// On utlise des "Formes *" car Forme est une classe dite "Absraite" 