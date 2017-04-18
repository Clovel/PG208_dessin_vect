// Camille Magnan & Clovis Durand
// Dessin vectoriel


#include "Couleur.h"


// Condestructeurs

Couleur::Couleur()
{
	red   = 0;
	green = 0;
	blue  = 0;
}

Couleur::Couleur(unsigned int r, unsigned int g, unsigned int b)
{
	red   = r;
	green = g;
	blue  = b;
}

Couleur::Couleur(std:string c)
{
	trad_couleur(c);
}	
	// Afficheurs

	// Accesseurs
	unsigned int Couleur::getRed(){
		return m_red;
	}
	unsigned int Couleur::getGreen(){
		return m_green;
	}

	unsigned int Couleur::getBlue(){
		return m_blue;
	}

	// Mutateurs
	void Couleur::setRed(unsigned int r){
		m_red = red;
	}

	void Couleur::setGreen(unsigned int g){
		m_green = green;
	}
	void Couleur::setBlue(unsigned int b){
		m_blue = blue;
	}
	

void trad_couleur(std::string couleur){
	if(c = "rouge")
	{
		setRed(255);// = m_red = 255;
		setGreen(0);
		setBlue(0);
	}
	else if(c = "vert")
	{
		setRed(0); // = m_red = 0;
		setGreen(255);
		setBlue(0);
	}	
	else if(c = "bleu")
	{
		setRed(0);
		setGreen(0);
		setBlue(255);
	}

}



