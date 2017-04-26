// Clovis Durand & Camille Magnan
// ENSEIRB-Matmeca, E2
// 2017

// PG208 - Projet Dessin Vectoriel

// Rectangle_p.cpp
// Rectangle class source file. 



//Con/Des
Rectangle_P::Rectangle(Coord const c1, 
	unsigned int const longueur, 
	unsigned int const hauteur,  
	std::string couleur, 
	unsigned int const transparence)
{
	m_c1 = c1;
	m_transparence = transparence;
	unsigned int const longueur;
	unsigned int const hauteur;
	setRGBcouleur(couleur);

}


// Rajouter le rectangle de travers


// Afficheurs
// Accesseurs
Coord getCoord1(void);

// Mutateurs
void setCoord1(Coord const &Coord1);

// Colorier
void color(CImage *img)
{
	setRGBcolor()
int i, j;

for(i = Coord1.getAbscisse(); i >= longueur; i++)
{
	for(j = Coord1.getOrdonee(); j>= hauteur; j++)
	{
		CPixel *p = Image->getPixel(i, j);
		p -> RGB(p->Red(),p->Green(),p->Blue());
	}
}
}