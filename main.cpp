// Clovis Durand & Camille Magnan
// ENSEIRB-Matmeca, E2
// 2017

// PG208 - Projet Dessin Vectoriel

// main.cpp
// main source file

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string> 		// C++ string
#include <cstring> 		// C string (for strcmp)
using namespace std;

// L'image doit etre carré d'apres le code de CImage fourni
#define WIDTH  768
#define HEIGHT 768

#include "./HEADERS/Format/CBitmap.h"
#include "./HEADERS/Formes/Ligne.h"
#include "./HEADERS/Formes/Rectangle.h"
#include "./HEADERS/Formes/Rectangle_p.h"
#include "./HEADERS/Formes/Triangle.h"
#include "./HEADERS/Formes/Cercle.h"
#include "./HEADERS/Formes/Cercle_p.h"
#include "./HEADERS/Formes/Carre.h"
#include "./HEADERS/Others/Dessin.h"
//#include "./HEADERS/Others/Point.h"



int main(int argc, char *argv[])
{
	if(argc == 1)
	{
		cerr << "[ERROR]  : Not enough arguments\n";
	}
	else
	{
		cout << "[DEBUG] : " << argv[0] << ", " << argv[1] << endl;
		if((strcmp(argv[0], "test") == 0) || (strcmp(argv[0], "DEBUG") == 0))
		{

			cout << "[INFO]  : P_Bitmap exection start (" << __DATE__ << " - " << __TIME__ << ")" << endl;
			cout << "[INFO]  : Number of arguments = " << argc << endl;

			cout << "[INFO]  : CBitmap object creation" << endl;
			CBitmap *image = new CBitmap();
			string filename2 = "Sortie_test.bmp";

			cout << "[INFO]  : CImage pointer extraction" << endl;
			CImage   *img = new CImage(HEIGHT, WIDTH);

			// Dessine une ligne diagonale de (0, 0) a (200, 200), 
				// i.e. de en bas a gauche à en haut a droite
				// Sert de témoin pour savoir si on arrive tjr a dessiner
			for(int i=0; i<200; i++)
			{
				CPixel *p = img->getPixel(i, i);
				p->RGB(255,255,255);
			}

			// Test dessin Ligne
			Coord c1(300, 300);
			Coord c2(500, 400);
			Coord c3(600, 100);

			cout << "[INFO]  : Creation of the drawing" << endl;
			Dessin dessin_test; // Construit le dessin

			// Declaration des formes
			cout << "[INFO]  : Declaration of every shape" << endl;
			Ligne l(c1, c2, "BLANC", 100);
			Rectangle rect(c1, 100, 200, "ROSE", 100);
			Cercle circ(c1, 125, "BLANC", 100);
			Cercle_p circp(c3, 90, "BLEU", 100);
			Rectangle_p rectp(c1, 30, 50, "BLANC", 100);

			dessin_test.addForme(&l);
			dessin_test.addForme(&rect);
			dessin_test.addForme(&circ);
			dessin_test.addForme(&circp);
			dessin_test.addForme(&rectp);

			dessin_test.drawAll(img);

			/* TEST DIRECT DES FORMES
			// Test Ligne                                   // OK
			Ligne l(c1, c2, "BLANC", 100);
			cout << "[DRAW]  : Drawing [l]" << endl;
			l.draw(img); // Dessine sur l'image

			// Test rectangle droit                         // OK
			Rectangle rect(c1, 100, 200, "ROSE", 100);
			cout << "[DRAW]  : Drawing [rect]" << endl;
			rect.draw(img);

			// Test cercle                                  // OK
			Cercle circ(c1, 125, "BLANC", 100);
			cout << "[DRAW]  : Drawing [circ]" << endl;
			circ.draw(img);

			// Test cercle plein                            // OK
			Cercle_p circp(c3, 90, "BLEU", 100);
			cout << "[DRAW]  : Drawing [circp]" << endl;
			circp.draw(img);

			// Test rectangle plein                         // NOK
			Rectangle_p rectp(c1, 30, 50, "BLANC", 100);
			cout << "[DRAW]  : Drawing [rectp]" << endl;
			cout << "[DEBUG] : l1 à 4 : " << rectp.getLigne1() << ", ";
			cout << rectp.getLigne2() << ", ";
			cout << rectp.getLigne3() << ", ";
			cout << rectp.getLigne4() << "\n";
			rectp.draw(img);
			
			*/

			

			image->setImage(img); // Met l'image dessinée dans l'objet CBitmap
			cout << "[INFO]  : CBitmap image saving" << endl;
			image->SaveBMP(filename2); // Enregistre le CBitmap

			return 1;
		}
		else // Un nom de fichier a ete precise.
		{
			cout << "[INFO]  : P_Bitmap exection start (" << __DATE__ << " - " << __TIME__ << ")" << endl;
			cout << "[INFO]  : Number of arguments = " << argc << endl;

			cout << "[INFO]  : CBitmap object creation" << endl;
			CBitmap *image = new CBitmap();
			string filename2 = "Sortie_vec.bmp";

			cout << "[INFO]  : CImage pointer extraction" << endl;
			CImage   *img = new CImage(HEIGHT, WIDTH);

			// On déclare un dessin
			cout << "[INFO]  : Drawing creation" << endl;
			Dessin dessin; // Construit le dessin

			string filename = argv[1]; // On recupere le nom de fichier

			if(dessin.loadVec(filename))
			{
				cout << "[INFO]  : " << filename << " loaded. " << endl;
				cout << "[INFO]  : Drawing all info given by [" << filename << "]" << endl;
				dessin.drawAll(img);

				image->setImage(img); // Met l'image dessinée dans l'objet CBitmap
				cout << "[INFO]  : CBitmap image saving" << endl;
				image->SaveBMP(filename2); // Enregistre le CBitmap

				return 1;
			}
			else
				cout << "[ERROR] : " << filename << " failed to load. " << endl;

		}
	}
}

