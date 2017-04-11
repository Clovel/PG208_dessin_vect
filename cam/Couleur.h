// Camille Magnan & Clovis Durand
// Dessin vectoriel


#ifndef COULEUR_H
#define COULEUR_H

class Couleur
{
private:
	int red;
	int green;
	int blue;

	void trad_couleur(std::string couleur);
	
public:
	Couleur(int r, int g, int b);
	Couleur(std::string c);
	
	void setRed(int r);
	void setGreen(int g);
	void setBlue(int b);
	void setCouleur(std::string c);

	int getRed();
	int getGreen();
	int getBlue();
	std::string Couleur();
	
	
};

#endif /*CPIXEL_H_*/
