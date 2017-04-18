// Camille Magnan & Clovis Durand
// Dessin vectoriel

#include "../../HEADERS/Formes/Cercle.h"
using namespace std;

//Constructeur/Destructeur
Cercle::Cerle(): m_rayon(0)
{
	//Par défaut
}

Cercle::Cercle(Coord c,
	unsigned int rayon,
	Couleur const couleur, 
	unsigned int const transparence);
{
	setC(c);
	setRayon(rayon);
	setCouleur(couleur);
	setTransparence(transparence);
}

//Afficheurs

//Accesseurs

Coord Cercle::getC(){

	return m_c;
}

unsigned int Cercle::getRayon(){

	return m_rayon;
}

string Cercle::getCouleur(){

	return m_couleur;
}

unsigned int Cercle::getTransparence(){

	return m_transparence;
}

//Mutateurs

void Cercle::setC(Coord c){

	m_c = c;
}

void Cercle::setRayon(unsigned int rayon){

	m_rayon = rayon;
}

void Cercle::setCouleur(string couleur){

	m_couleur = couleur ;
}

void Cercle::setTransparence(unsigned int transparence){

	m_transparence = transparence;
}

// DRAW


void Cercle::draw(CImage *img)

{
	int dx; // Distance

	// Coordonnées 
	int x(getCoord().getAbscisse());
	int y(getCoord().getOrdonnee());
	int xmin;
	int ymin;
	int xmax;
	int ymax;

	if ((x - rayon) < 0){
		xmin = 0;
	}
	else {
		xmin = x - rayon;
	}
	if ((x + rayon) > 1024){
		xmax = 1024;
	}
	else {
		xmax = x + rayon;
	}
	
	if ((y - rayon) < 0){
		ymin = 0;
	}
	else{
		ymin = y - rayon;
	}
	if ((y + rayon >))

	#ifdef DEBUG
		cout << "x = " << x << endl;
		cout << "y = " << y << endl;
		cout << "xmin = " << xmax << endl;
		cout << "ymin = " << ymax << endl;
	#endif //DEBUG

	int x0 = 0;
	int y0 = rayon;
	int d = r -1;

	while(y >= x0){

		img->drawPixel(x + x0, y+ y0, r, g, b);
		img->drawPixel(x + y0, y+ x0, r, g, b);
		img->drawPixel(x - x0, y+ y0, r, g, b);
		img->drawPixel(x - y0, y+ y0, r, g, b);
		img->drawPixel(x + x0, y- y0, r, g, b);
		img->drawPixel(x + y0, y- x0, r, g, b);
		img->drawPixel(x - x0, y- y0, r, g, b);
		img->drawPixel(x - y0, y- x0, r, g, b);

		if (d >= 2 * x0){
			d -= 2 * x0 + 1;
			x++;
		}
		else if (d < 2 * (rayon - y0)){
			d += 2 * y - 1;
			y--;
		}
		else{
			d += 2 * (y - x - 1);
			y--;
			x++;
		}
	}
}
