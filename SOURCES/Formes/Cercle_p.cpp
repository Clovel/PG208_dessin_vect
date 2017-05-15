// Clovis Durand & Camille Magnan
// ENSEIRB-Matmeca, E2
// 2017

// PG208 - Projet Dessin Vectoriel

// Cercle_p.h
// Cercle_p class source file. 

#include "../../HEADERS/Formes/Cercle_p.h"
//#define DEBUG

// Con/Destructeurs
Cercle_p::Cercle_p()
{
    setRayon(1); // Valeur par defaut a définir, 1 pour le moment
}

Cercle_p::Cercle_p(Coord const c, 
    unsigned int const rayon, 
    std::string const couleur, 
    unsigned int const transparence)
{
	setCoord1(c);
    setRayon(rayon);
    setCouleur(couleur);
    setTransparence(transparence);
}

// Afficheurs

// Accesseurs

// Mutateurs

// Draw

void Cercle_p::draw(CImage *img) 
{
    #ifdef DEBUG
            cout << "[DEBUG] : This shape is a full circle\n";
    #endif //DEBUG

	unsigned int rayon_init = getRayon();
	int x 					= getCoord1().getAbscisse();
    int y 					= getCoord1().getOrdonnee();

    #ifdef DEBUG
    	cout << "DEBUG : Rayon du cercle plein : " << rayon_init << endl;
    	cout << "DEBUG : x : " << x << endl;
    	cout << "DEBUG : y : " << y << endl;
    #endif // DEBUG

	drawCircles(img, rayon_init, x, y);
}


// Méthodes publiques Diverses

// Attributs/Variables membres

// Méthodes privées diverses
void Cercle_p::drawCircles(CImage *img, unsigned int rayon, int const x, int const y) 
{
    float seg;
    RGB_t RGB_temp;

    /*#ifdef DEBUG
    	cout << "DEBUG : Rayon de Cercle_p : " << rayon << endl;
    #endif // DEBUG*/

    if(rayon != 0)
    {
	    for(int i = MAX(x - rayon, 0); i < x + rayon + 1; i++)
	    {
	    	/*#ifdef DEBUG 
	    		cout << "DEBUG : First loop, i = " << i << endl;
	    	#endif // DEBUG*/
	        for (int j = MAX(y - rayon, 0); j < y + rayon + 1; j++)
	        {
	        	seg = sqrt(pow(x - i, 2) + pow(y - j, 2));

	        	/*#ifdef DEBUG 
	    			cout << "DEBUG : Second loop, j = " << j << endl;
	    			cout << "DEBUG : seg = " << seg << endl;
	    		#endif // DEBUG*/

	            if ((seg < (rayon + 1)) & (seg > (rayon - 1))) // 1 étant un epsilon
	            {
	                RGB_temp = applyTransparency(img,i, j);
                    img->drawPixel(i, j, RGB_temp.r, RGB_temp.g, RGB_temp.b);
	                /*#ifdef DEBUG
	                	cout << "DEBUG : Drawing pixel at [" << i << ", " << j << "]\n";
	                #endif // DEBUG*/
	            }
	        }
	    }
	    drawCircles(img, --rayon, x, y);
	}
    img->drawPixel(x, y, getRGB().r, getRGB().g, getRGB().b); // Dessiner le centre
}