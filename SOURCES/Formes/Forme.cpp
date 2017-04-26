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
	string const couleur,
	unsigned int const transparence)
{
	setCoord1(c1);
	setRGBcouleur(couleur);
	setTransparence(transparence);
}

// Accesseurs
Coord Forme::getCoord1(void) const
{
	return m_c1;
}

int Forme::getRed(void) const
{
	return m_R;
}

int Forme::getGreen(void) const
{
    return m_G;
}

int Forme::getBlue(void) const
{
    return m_B;
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

void Forme::setTransparence(unsigned int const &transparence)
{
	m_transparence = transparence;
}

void Forme::setRGBcouleur(string const couleur)
{
    if (coulor=="rouge")
    {
        m_R = 255;
        m_G = 0;
        m_B = 0; }
    if (couleur=="bleu")
    {
        m_R = 0;
        m_G = 0;
        m_B = 255; }
    if (couleur=="vert")
    {
        m_R = 0;
        m_G = 255;
        m_B = 0; }
    if (couleur=="jaune")
    {
        m_R = 255;
        m_G = 255;
        m_B = 0; }
    if (couleur=="marron")
    {
        m_R = 167;
        m_G =85;
        m_B = 2; }
    if (couleur=="blanc")
    {
        m_R = 255;
        m_G =255;
        m_B = 255; }
    if (couleur=="rose")
    {
        m_R = 253;
        m_G =108;
        m_B = 158; }
}

void Forme::setRGBcouleur(int R, int G, int B)
{
    m_R = R;
    m_G = G;
    m_B = B;
}

// rajouter transparence