// Camille Magnan & Clovis Durand
// Dessin vectoriel


#ifndef COULEUR_H
#define COULEUR_H

#include <string>

class Couleur
{
public:
	// Con/Destructeurs
	Couleur();
	Couleur(unsigned int r, unsigned int g, unsigned int b);
	Couleur(std::string c); // même nom mais ne fait pas la même chose
	
	// Afficheurs

	// Accesseurs
	unsigned int getRed(void);
	unsigned int getGreen(void);
	unsigned int getBlue(void);

	// Mutateurs
	void setRed(unsigned int r);
	void setGreen(unsigned int g);
	void setBlue(unsigned int b);
//	void setCouleur(std::string c);
	

	
private:
	// Attributs/Variables membres
	unsigned int m_red;
	unsigned int m_green;
	unsigned int m_blue;

	void trad_couleur(std::string couleur);
		
};

#endif /*CPIXEL_H_*/
