// Clovis Durand & Camille Magnan
// ENSEIRB-Matmeca, E2
// 2017

// PG208 - Projet Dessin Vectoriel

// Forme.cpp
// Forme class source file. 

#include "../../HEADERS/Formes/Forme.h"
using namespace std;


// Con/Destructeurs -------------------------------------------------
Forme::Forme()
{
	setTransparence(0);
    setCouleur(255, 255, 255);
}

Forme::Forme(Coord const c1, 
	string const couleur,
	unsigned int const transparence)
{
	setCoord1(c1);
	setCouleur(couleur);
	setTransparence(transparence);
}

Forme::Forme(Coord const c1, 
    unsigned int const R,
    unsigned int const G,
    unsigned int const B,
    unsigned int const transparence)
{
    setCoord1(c1);
    setCouleur(R, G, B);
    setTransparence(transparence);
}

// Accesseurs -------------------------------------------------------
Coord Forme::getCoord1(void) const
{
	return m_c1;
}

unsigned int Forme::getRed(void) const
{
	return m_R;
}

unsigned int Forme::getGreen(void) const
{
    return m_G;
}

unsigned int Forme::getBlue(void) const
{
    return m_B;
}


unsigned int Forme::getTransparence(void) const
{
	return m_transparence;
}

// Mutateurs --------------------------------------------------------
void Forme::setCoord1(Coord const &c1)
{
	m_c1 = c1;
}

void Forme::setTransparence(unsigned int const &transparence)
{
	m_transparence = (transparence < 100) ? transparence : 100;
}

void Forme::setCouleur(string const &couleur)
{
    m_couleur = couleur;
}

/*void Forme::setCouleur(unsigned int &R, unsigned int &G, unsigned int &B)
{
    m_R = (R < 255) ? R : 255;
    m_G = (G < 255) ? G : 255;
    m_B = (B < 255) ? B : 255;
}*/

// rajouter transparence

// Méthodes privées diverses ----------------------------------------
RGB_t Forme::getRGB(void) const
{
    RGB_t rgb_buff;
    couleur = getCouleur();

    if (couleur == "ROUGE")
    {
        rgb_buff.r = 255;
        rgb_buff.g = 0;
        rgb_buff.b = 0;
    }
    if (couleur == "BLEU")
    {
        rgb_buff.r = 0;
        rgb_buff.g = 0;
        rgb_buff.b = 255;
    }
    if (couleur == "VERT")
    {
        rgb_buff.r = 0;
        rgb_buff.g = 255;
        rgb_buff.b = 0;
    }
    if (couleur == "JAUNE")
    {
        rgb_buff.r = 255;
        rgb_buff.g = 255;
        rgb_buff.b = 0;
    }
    if (couleur == "MARRON")
    {
        rgb_buff.r = 167;
        rgb_buff.g = 85;
        rgb_buff.b = 2;
    }
    if (couleur == "BLANC")
    {
        rgb_buff.r = 255;
        rgb_buff.g = 255;
        rgb_buff.b = 255;
    }
    if (couleur == "ROSE")
    {
        rgb_buff.r = 253;
        rgb_buff.g = 108;
        rgb_buff.b = 158;
    }

    return rgb_buff;
}