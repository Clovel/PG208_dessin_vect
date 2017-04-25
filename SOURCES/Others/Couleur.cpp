// Camille Magnan & Clovis Durand
// Dessin vectoriel


#include "../../HEADERS/Others/Couleur.h"
using namespace std;


// Con/Destructeurs

Couleur::Couleur()
{
	setRed(0);
	setGreen(0);
	setBlue(0);
}

Couleur::Couleur(unsigned int r, unsigned int g, unsigned int b)
{
	setRed(r);
	setGreen(g);
	setBlue(b);
}

Couleur::Couleur(string c)
{
	trad_couleur(c);
}

// Afficheurs

// Accesseurs
unsigned int Couleur::getRed(void)
{
	return m_red;
}
unsigned int Couleur::getGreen(void)
{
	return m_green;
}

unsigned int Couleur::getBlue(void)
{
	return m_blue;
}

// Mutateurs
void Couleur::setRed(unsigned int r)
{
	m_red = r;
}

void Couleur::setGreen(unsigned int g)
{
	m_green = g;
}
void Couleur::setBlue(unsigned int b)
{
	m_blue = b;
}
	

void Couleur::trad_couleur(string c)
{
	if(c == "rouge")
	{
		setRed(255);// = m_red = 255;
		setGreen(0);
		setBlue(0);
	}
	else if(c == "vert")
	{
		setRed(0); // = m_red = 0;
		setGreen(255);
		setBlue(0);
	}	
	else if(c == "bleu")
	{
		setRed(0);
		setGreen(0);
		setBlue(255);
	}
	else if(c == "blanc")
	{
		setRed(255);
		setGreen(255);
		setBlue(255);
	}

}

void Couleur::trad_couleur(unsigned int r, unsigned int g, unsigned int b)
{

	setRed(r);
	setBlue(b);
	setGreen(g);

}


