/*
 *  CImage.h
 *  P_Bitmap
 *
 *  Created by Le Gal on 24/10/06.
 *  Copyright 2006 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

#include "CLigne.h"

#ifndef CIMAGE_H_
#define CIMAGE_H_

class CImage
{
private:
    CLigne** liste;
    int taille;

public:
    CImage(int hauteur, int largeur);

    ~CImage();

    int size();

    CLigne* getLigne(int position);

    CPixel* getPixel(int posX, int posY);

    void drawPixel(int const posX, int const posY, unsigned int r, unsigned int g, unsigned int b);
};

#endif /*CIMAGE_H_*/
