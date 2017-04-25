// Clovis Durand & Camille Magnan
// ENSEIRB-Matmeca, E2
// 2017

// PG208 - Projet Dessin Vectoriel

// Forme.cpp
// Forme class source file. 

#include "../../HEADERS/Formes/Forme.h"
using namespace std;


// Con/Destructeurs
Forme::Forme()
{
	setTransparence(0);
}

Forme::Forme(Coord const c1, 
	Couleur const couleur,
	unsigned int const transparence)
{
	setCoord1(c1);
	setCouleur(couleur);
	setTransparence(transparence);
}

// Accesseurs
Coord Forme::getCoord1(void) const
{
	return m_c1;
}

Couleur Forme::getCouleur(void) const
{
	return m_couleur;
}

unsigned int Forme::getTransparence(void) const
{
	return m_transparence;
}

// Mutateurs
void Forme::setCoord1(Coord const &c1)
{
	m_c1 = c1;
}

void Forme::setCouleur (Couleur const &couleur)
{
	m_couleur = couleur;
}

void Forme::setTransparence(unsigned int const &transparence)
{
	m_transparence = transparence;
}

void getRGBcolor()
{
    if (color=="rouge")
    {
        R = 255;
        G = 0;
        B = 0; }
    if (color=="bleu")
    {
        R = 0;
        G = 0;
        B = 255; }
    if (color=="vert")
    {
        R = 0;
        G = 255;
        B = 0; }
    if (color=="jaune")
    {
        R = 255;
        G = 255;
        B = 0; }
    if (color=="marron")
    {
        R = 167;
        G =85;
        B = 2; }
    if (color=="blanc")
    {
        R = 255;
        G =255;
        B = 255; }
    if (color=="rose")
    {
        R = 253;
        G =108;
        B = 158; }
}

// rajouter transparence