/*// Clovis Durand & Camille Magnan
// ENSEIRB-Matmeca, E2
// 2017

// PG208 - Projet Dessin Vectoriel

// Rectangle_p.cpp
// Rectangle class source file. 

#include "../../HEADERS/Formes/Rectangle_p.h"

//Con/Des
Rectangle_p::Rectangle(Coord const c1, 
	unsigned int const longueur, 
	unsigned int const hauteur,  
	std::string couleur, 
	unsigned int const transparence)
{
	m_c1 = c1;
	m_transparence = transparence;
	unsigned int const longueur;
	unsigned int const hauteur;
	setRGBcouleur(couleur);

}


// Rajouter le rectangle de travers


// Afficheurs
// Accesseurs
Coord Rectangle_p::getCoord1(void);

// Mutateurs
void Rectangle_p::setCoord1(Coord const &Coord1);

// Colorier
void Rectangle_p::color(CImage *img)
{
	setRGBcolor()
int i, j;

for(i = Coord1.getAbscisse(); i >= longueur; i++)
{
	for(j = Coord1.getOrdonee(); j>= hauteur; j++)
	{
		CPixel *p = Image->getPixel(i, j);
		p -> RGB(p->Red(),p->Green(),p->Blue());
	}
}
}*/

// Clovis Durand & Camille Magnan
// ENSEIRB-Matmeca, E2
// 2017

// PG208 - Projet Dessin Vectoriel

// Rectangle_p.cpp

#include "../../HEADERS/Formes/Rectangle_p.h"

// Con/Destructeurs

// Afficheurs

// Accesseurs

// Mutateurs

// Draw
Rectangle_p::draw(CImage *img)
{
	setRGBcolor()
int i, j;
int origine_y = getCoord1().getOrdonee();
int origine_x = getCoord1().getAbscisse();
int longueur = getLigne2().getCoord1().getOrdonee() - origine_y ;
int hauteur = getLigne3().getCoord1().getAbscisse() - origine_x ;

for(i = origine_x; i >= longueur; i++)
{
	for(j = origine_y; j>= hauteur; j++)
	{
		CPixel *p = Image->getPixel(i, j);
		p -> RGB(p->Red(),p->Green(),p->Blue());
	}
}

// Méthodes publiques Diverses

// Attributs/Variables membres

// Méthodes privées diverses 