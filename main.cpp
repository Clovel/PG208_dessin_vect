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

#include "./HEADERS/Format/CBitmap.h"

#define WIDTH  1024
#define HEIGHT 768


int main(int argc, char * argv[]) {
    cout << "INFO : P_Bitmap exection start (" << __DATE__ << " - " << __TIME__ << ")" << endl;
    cout << "INFO : Number of arguments = " << argc << endl;

    cout << "INFO : CBitmap object creation" << endl;
    CBitmap *image = new CBitmap();
    string filename2 = "Sortie.bmp";

    cout << "INFO : CImage pointer extraction" << endl;
    CImage   *img = new CImage(HEIGHT, WIDTH);



    // Dessine une ligne diagonale de (0, 0) a (200, 200), 
        // i.e. de en bas a gauche à en haut a droite
    for(int i=0; i<200; i++)
    {
        CPixel *p = img->getPixel(i, i);
        p->RGB(255,255,255);
    }

    image->setImage(img); // Met l'image dessinée dans l'objet CBitmap
    cout << "INFO : CBitmap image saving" << endl;
    image->SaveBMP(filename2); // Enregistre le CBitmap

    return 1;
}

