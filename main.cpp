// Clovis Durand & Camille Magnan
// ENSEIRB-Matmeca, E2
// 2017

// PG208 - Projet Dessin Vectoriel

// main.c source file

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// L'image doit etre carré d'apres le code de CImage fourni
#define WIDTH  768
#define HEIGHT 768

#include "./HEADERS/Format/CBitmap.h"
#include "./HEADERS/Formes/Ligne.h"
#include "./HEADERS/Formes/Rectangle.h"
#include "./HEADERS/Formes/Rectangle_p.h"
//#include "./HEADERS/Formes/Triangle.h"
#include "./HEADERS/Formes/Cercle.h"
#include "./HEADERS/Formes/Cercle_p.h"
//#include "./HEADERS/Formes/Carre.h"



int main(int argc, char * argv[]) {
    cout << "INFO  : P_Bitmap exection start (" << __DATE__ << " - " << __TIME__ << ")" << endl;
    cout << "INFO  : Number of arguments = " << argc << endl;

    cout << "INFO  : CBitmap object creation" << endl;
    CBitmap *image = new CBitmap();
    string filename2 = "Sortie.bmp";

    //Contstuction des formes

    cout << "INFO  : CImage pointer extraction" << endl;
    CImage   *img = new CImage(HEIGHT, WIDTH);

    // Dessine une ligne diagonale de (0, 0) a (200, 200), 
        // i.e. de en bas a gauche à en haut a droite
    for(int i=0; i<200; i++)
    {
        CPixel *p = img->getPixel(i, i);
        p->RGB(255,255,255);
    }

    // Test dessin Ligne
    Coord c1(300, 300);
    Coord c2(500, 400);
    Coord c3(600, 100);

    // Test Ligne                                   // OK
    Ligne l(c1, c2, "BLANC", 0);
    cout << "[DRAW]  : Drawing [l]" << endl;
    l.draw(img); // Dessine sur l'image

    // Test rectangle droit                         // OK
    Rectangle rect(c1, 100, 200, "ROSE", 0);
    cout << "[DRAW]  : Drawing [rect]" << endl;
    rect.draw(img);

/*    // Test rectangle de biais                      // NOK
    Rectangle rect2(l, 150, "BLEU", 0);
    cout << "[DRAW]  : Drawing [rect2]" << endl;
    cout << "[DEBUG] : l1 à 4 : " << rect2.getLigne1() << ", ";
    cout << rect2.getLigne2() << ", ";
    cout << rect2.getLigne3() << ", ";
    cout << rect2.getLigne4() << "\n";
    rect2.draw(img);*/

    // Test cercle                                  // OK
    Cercle circ(c1, 125, "BLANC", 0);
    cout << "[DRAW]  : Drawing [circ]" << endl;
    circ.draw(img);

    // Test cercle plein                            // OK
    Cercle_p circp(c3, 90, "BLANC", 0);
    cout << "[DRAW]  : Drawing [circp]" << endl;
    circp.draw(img);

    // Test rectangle plein                         // NOK
    Rectangle_p rectp(c1, 30, 50, "BLANC", 0);
    cout << "[DRAW]  : Drawing [rectp]" << endl;
    cout << "[DEBUG] : l1 à 4 : " << rectp.getLigne1() << ", ";
    cout << rectp.getLigne2() << ", ";
    cout << rectp.getLigne3() << ", ";
    cout << rectp.getLigne4() << "\n";
    rectp.draw(img);

    /*Triangle tri(l, c3, "ROUGE", 0);
    cout << "[DRAW] : Drawing [tri]" << endl;
    tri.draw(img);*/

    image->setImage(img); // Met l'image dessinée dans l'objet CBitmap
    cout << "INFO  : CBitmap image saving" << endl;
    image->SaveBMP(filename2); // Enregistre le CBitmap

    return 1;
}

