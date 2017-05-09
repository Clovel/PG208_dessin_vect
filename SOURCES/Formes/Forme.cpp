// Clovis Durand & Camille Magnan
// ENSEIRB-Matmeca, E2
// 2017

// PG208 - Projet Dessin Vectoriel

// Forme.cpp
// Forme class source file. 

#include "../../HEADERS/Formes/Forme.h"
#include <string.h>
using namespace std;


// Con/Destructeurs -------------------------------------------------
Forme::Forme()
{
    setCouleur("BLANC");
	setTransparence(0);
}

Forme::Forme(Coord const c1, 
	string const couleur,
	unsigned int const transparence)
{
	setCoord1(c1);
	setCouleur(couleur);
	setTransparence(transparence);
}

// Accesseurs -------------------------------------------------------
Coord Forme::getCoord1(void) const
{
	return m_c1;
}

string Forme::getCouleur(void) const
{
    return m_couleur;
}

unsigned int Forme::getTransparence(void) const
{
	return m_transparence;
}

RGB_t Forme::getRGB(void) const
{
    RGB_t rgb_buff;
    string const couleur = getCouleur();

    if (couleur == "ROUGE")
    {
        rgb_buff.r = 255;
        rgb_buff.g = 0;
        rgb_buff.b = 0;
    }
    else if (couleur == "BLEU")
    {
        rgb_buff.r = 0;
        rgb_buff.g = 0;
        rgb_buff.b = 255;
    }
    else if (couleur == "VERT")
    {
        rgb_buff.r = 0;
        rgb_buff.g = 255;
        rgb_buff.b = 0;
    }
    else if (couleur == "JAUNE")
    {
        rgb_buff.r = 255;
        rgb_buff.g = 255;
        rgb_buff.b = 0;
    }
    else if (couleur == "MARRON")
    {
        rgb_buff.r = 167;
        rgb_buff.g = 85;
        rgb_buff.b = 2;
    }
    else if (couleur == "BLANC")
    {
        rgb_buff.r = 255;
        rgb_buff.g = 255;
        rgb_buff.b = 255;
    }
    else if (couleur == "ROSE")
    {
        rgb_buff.r = 253;
        rgb_buff.g = 108;
        rgb_buff.b = 158;
    }
    else
    {
        rgb_buff.r = 255;
        rgb_buff.g = 255;
        rgb_buff.b = 255;
    }

    return rgb_buff;
}


RGB_t Forme::applyTransparency(CImage *img, int const x, int const y)
{
    CPixel *p = img->getPixel(x, y);
    int const r_old = p->Red();
    int const g_old = p->Green();
    int const b_old = p->Blue();

    RGB_t color = getRGB();
    unsigned int rtemp, gtemp, btemp;

    rtemp = color.r;
    gtemp = color.g;
    btemp = color.b;

    rtemp = (int)(100 - getTransparence() * r_old + getTransparence() * rtemp);
    gtemp = (int)(100 - getTransparence() * g_old + getTransparence() * gtemp);
    btemp = (int)(100 - getTransparence() * b_old + getTransparence() * btemp);

    color.r = rtemp;
    color.g = gtemp;
    color.b = btemp;

    return color;
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

// Méthodes privées diverses ----------------------------------------
