// Clovis Durand & Camille Magnan
// ENSEIRB-Matmeca, E2
// 2017

// PG208 - Projet Dessin Vectoriel

// Dessin.h
// Dessin class sources file. 

#include "../../HEADERS/Others/Dessin.h"

Dessin::Dessin()
{
	// Constructeur
}

Dessin::~Dessin()
{
	// Destructeur
	// Parcourir tout les elements du vecteur et free. delete
	for(unsigned int i = 0; i < m_formes.size(); i++)
		delete m_formes[i];
	m_formes.clear();
}

// Accesseurs
Forme *Dessin::getFormeFromIdx(unsigned int const &index) const
{
	#ifdef DEBUG
		cout << "[DEBUG] : Fetching shape with getFormeFromIdx(" << index << ")\n";
	#endif // DEBUG
	return m_formes[index];
}

vector<Forme *> Dessin::getFormes(void) const
{
	return m_formes;
}

// Mutateurs

void Dessin::setForme(Forme *f, unsigned int const &index)
{
	if(index < m_formes.size())
		m_formes[index] = f;
	else
	{
		cout << "[ERROR]  : Index not in vector size. \n";
		cout << "           Vector size is " << m_formes.size() << endl;
		cout << "           wheras index is " << index << endl;
	}
}

void Dessin::addForme(Forme *f)
{
	m_formes.push_back(f);
}

// Fonction Load depuis un fichier .vec

bool Dessin::loadVec(string const &filename)
{
	ifstream file(filename);
	string ligne;

	#ifdef DEBUG
		cout << "[DEBUG] : loadVec(" << filename << ")\n";
		unsigned int i = 0;
	#endif // DEBUG

	if(file)
	{
		while(getline(file, ligne))
		{
			// On parcours toutes les lignes du fichier
			// On charge toutes les formes correspondantes

			#ifdef DEBUG
				cout << "[DEBUG] : Fetch line #" << i++ << ", contents are : " << ligne << endl;
			#endif // DEBUG

			unsigned int pos = ligne.find("#"); // Commentaire

			if((pos != 0)) // Attention ne gère pas les lignes vides
			{
				#ifdef DEBUG
					cout << "[DEBUG] : Adding info from : " << ligne << endl;
				#endif // DEBUG
				Forme *tempshape = loadForme(ligne);
				addForme(tempshape);
			}
		}
		return 1;
	}
	else
		return 0;
}

// Fonctions publiques diverses

void Dessin::drawAll(CImage *img) const
{
	for(unsigned int i = 0; i < getFormes().size(); i++)
	{
		#ifdef DEBUG
			cout << "[DEBUG] : # of the shape in file : " << i << endl;
		#endif DEBUG
		getFormeFromIdx(i)->draw(img);
		#ifdef DEBUG
			cout << "[DEBUG] : Just drew shape #" << i << endl;
		#endif DEBUG
	}
	#ifdef DEBUG
		cout << "[DEBUG] : Drew every shape in vector" << endl;
	#endif DEBUG
}

// Fonctions privées diverses

Forme *Dessin::loadForme(string ligne)
{
	vector<string> infos;
	int taille = ligne.size();

	// On récupere le type de forme
	int pos = ligne.find(":"); // Curseur
	infos.push_back(ligne.substr(0, pos)); 
	ligne = ligne.substr(pos + 1, taille - pos - 1);

	#ifdef DEBUG
		cout << "[DEBUG] : Type of shape is : " << infos[0] << endl;
	#endif // DEBUG


	if( (infos[0] == "DISQUES") || 
		(infos[0] == "CERLCES") ||
		(infos[0] == "CERCLE_P"))
	{
		// La forme en question est un cercle plein
		// Ex : DISQUES:150,150,150,GOLD,0;

		#ifdef DEBUG
			cout << "[DEBUG] : This shape is a full circle\n";
		#endif //DEBUG

		// On récupère le reste des infos 
		for(unsigned int i = 0; i < 5; i++)
		{ // Recuperation des 3 int
			int pos = ligne.find(","); // Curseur
			infos.push_back(ligne.substr(0, pos)); 
			ligne = ligne.substr(pos + 1, taille - pos - 1);
		}

		int x              = stoi(infos[1]); // x : abscisse
		int y              = stoi(infos[2]); // y : ordonnée
		unsigned int r     = (unsigned int)stoi(infos[3]); // r : rayon
		string colorstring = infos[4]; // couleur sous forme de string
		unsigned int trsp  = (unsigned int)stoi(infos[5]);

		Coord c1(x, y);

		return new Cercle_p(c1, r, colorstring, trsp); // circp; //On retourne l'adresse de l'objet
	}
	else if((infos[0] == "DISQUE") ||
		    (infos[0] == "CERCLE"))
	{
		// La forme en question est un cercle simple
		// Ex : DISQUE:150,150,150,GOLD,0;

		#ifdef DEBUG
			cout << "[DEBUG] : This shape is a simple circle\n";
		#endif //DEBUG

		// On récupère le reste des infos 
		for(unsigned int i = 0; i < 5; i++)
		{ // Recuperation des 3 int
			int pos = ligne.find(","); // Curseur
			infos.push_back(ligne.substr(0, pos)); 
			ligne = ligne.substr(pos + 1, taille - pos - 1);
		}

		int x              = stoi(infos[1]); // x : abscisse
		int y              = stoi(infos[2]); // y : ordonnée
		unsigned int r     = (unsigned int)stoi(infos[3]); // r : rayon
		string colorstring = infos[4]; // couleur sous forme de string
		unsigned int trsp  = (unsigned int)stoi(infos[5]);

		Coord c1(x, y);

		return new Cercle(c1, r, colorstring, trsp); // circ; //On retourne l'adresse de l'objet
	}
	else if(infos[0] == "LIGNE")
	{
		// La forme en question est une ligne 
		// Ex : LIGNE:100,125,50,75,BLEU,0;

		#ifdef DEBUG
			cout << "[DEBUG] : This shape is a line\n";
		#endif //DEBUG

		// On récupère le reste des infos
		for(unsigned int i = 0; i < 6; i++)
		{ // Recuperation des 3 int
			int pos = ligne.find(","); // Curseur
			infos.push_back(ligne.substr(0, pos)); 
			ligne = ligne.substr(pos + 1, taille - pos - 1);
		}

		int x0 				= stoi(infos[1]);
		int y0 				= stoi(infos[2]);
		int x1 				= stoi(infos[3]);
		int y1 				= stoi(infos[4]);
		string colorstring 	= infos[5];
		unsigned int trsp 	= (unsigned int)stoi(infos[6]);  

		Coord c1(x0, y0);
		Coord c2(x1, y1);

		return new Ligne(c1, c2, colorstring, trsp); // l;
	}
	/*else if(infos[0] == "POINT")
	{
		// La forme en question est un point
		// Ex : POINT:100,100,BLEU,0;

		#ifdef DEBUG
			cout << "[DEBUG] : This shape is a pixel\n";
		#endif //DEBUG

		// On récupère le reste des infos
		for(unsigned int i = 0; i < 4; i++)
		{ // Recuperation des 3 int
			int pos = ligne.find(","); // Curseur
			infos.push_back(ligne.substr(0, pos)); 
			ligne = ligne.substr(pos + 1, taille - pos - 1);
		}

		int x 				= stoi(infos[1]);
		int y 				= stoi(infos[2]);
		string colorstring 	= infos[3];
		unsigned int trsp 	= (unsigned int)stoi(infos[4]);

		Coord c1(x, y);

		return new Point(c1, colorstring, trsp); // p;
	}*/
	else if(infos[0] == "RECTANGLE")
	{
		// La forme en question est un rectangle simple
		// Ex : RECTANGLE:100,120,30,40,BLANC,1;

		#ifdef DEBUG
			cout << "[DEBUG] : This shape is a simple rectangle\n";
		#endif //DEBUG

		// On récupère le reste des infos
		for(unsigned int i = 0; i < 6; i++)
		{ // Recuperation des 3 int
			int pos = ligne.find(","); // Curseur
			infos.push_back(ligne.substr(0, pos)); 
			ligne = ligne.substr(pos + 1, taille - pos - 1);
		}

		int x 				= stoi(infos[1]);
		int y 				= stoi(infos[2]);
		int longueur		= stoi(infos[3]);
		int hauteur			= stoi(infos[4]);
		string colorstring 	= infos[5];
		unsigned int trsp 	= (unsigned int)stoi(infos[6]); 

		Coord c1(x, y);

		return new Rectangle(c1, longueur, hauteur, colorstring, trsp); // rect;
	}
	else if((infos[0] == "RECTANGLES") ||
		    (infos[0] == "RECTANGLEP"))
	{
		// La forme en question est un rectangle plein
		// Ex : RECTANGLES:100,120,30,40,BLANC,1;

		#ifdef DEBUG
			cout << "[DEBUG] : This shape is a full rectangle\n";
		#endif //DEBUG

		// On récupère le reste des infos
		for(unsigned int i = 0; i < 6; i++)
		{ // Recuperation des 3 int
			int pos = ligne.find(","); // Curseur
			infos.push_back(ligne.substr(0, pos)); 
			ligne = ligne.substr(pos + 1, taille - pos - 1);
		}

		int x 				= stoi(infos[1]);
		int y 				= stoi(infos[2]);
		int longueur		= stoi(infos[3]);
		int hauteur			= stoi(infos[4]);
		string colorstring 	= infos[5];
		unsigned int trsp 	= (unsigned int)stoi(infos[6]); 

		Coord c1(x, y);

		return new Rectangle_p(c1, longueur, hauteur, colorstring, trsp); //rectp;
	}
	else if(infos[0] == "CARRE")
	{
		// La forme en question est un carre simple
		// Ex : CARRE:100,100,150,ROUGE,100;

		#ifdef DEBUG
			cout << "[DEBUG] : This shape is a simple square\n";
		#endif //DEBUG

		// On récupère le reste des infos
		for(unsigned int i = 0; i < 5; i++)
		{ // Recuperation des 3 int
			int pos = ligne.find(","); // Curseur
			infos.push_back(ligne.substr(0, pos)); 
			ligne = ligne.substr(pos + 1, taille - pos - 1);
		}

		int x 				= stoi(infos[1]);
		int y 				= stoi(infos[2]);
		int cote			= stoi(infos[3]);
		string colorstring 	= infos[4];
		unsigned int trsp 	= (unsigned int)stoi(infos[5]); 

		Coord c1(x, y);

		return new Carre(c1, cote, colorstring, trsp); // carre;
	}
	else if((infos[0] == "CARRES") ||
		    (infos[0] == "CARREP"))
	{
		// La forme en question est un carre plein
		// Ex : CARREP:100,100,150,ROUGE,100;

		#ifdef DEBUG
			cout << "[DEBUG] : This shape is a full square\n";
		#endif //DEBUG

		// On récupère le reste des infos
		for(unsigned int i = 0; i < 6; i++)
		{ // Recuperation des 3 int
			int pos = ligne.find(","); // Curseur
			infos.push_back(ligne.substr(0, pos)); 
			ligne = ligne.substr(pos + 1, taille - pos - 1);
		}

		int x 				= stoi(infos[1]);
		int y 				= stoi(infos[2]);
		int cote			= stoi(infos[3]);
		string colorstring 	= infos[4];
		unsigned int trsp 	= (unsigned int)stoi(infos[5]); 

		Coord c1(x, y);

		return new Carre_p(c1, cote, colorstring, trsp); // carrep;
	}
	else if(infos[0] == "TRIANGLE")
	{
		// La forme en question est un carre plein
		// Ex : TRIANGLE:100,100,200,200,100,300,BLUE,100

		#ifdef DEBUG
			cout << "[DEBUG] : This shape is a simple triangle\n";
		#endif //DEBUG

		// On récupère le reste des infos
		for(unsigned int i = 0; i < 8; i++)
		{ // Recuperation des 3 int
			int pos = ligne.find(","); // Curseur
			infos.push_back(ligne.substr(0, pos)); 
			ligne = ligne.substr(pos + 1, taille - pos - 1);
		}

		int x0 				= stoi(infos[1]);
		int y0 				= stoi(infos[2]);
		int x1 				= stoi(infos[3]);
		int y1 				= stoi(infos[4]);
		int x2 				= stoi(infos[5]);
		int y2 				= stoi(infos[6]);
		string colorstring 	= infos[7];
		unsigned int trsp 	= (unsigned int)stoi(infos[8]); 

		Coord c1(x0, y0);
		Coord c2(x1, y1);
		Ligne l(c1, c2, colorstring, trsp);
		Coord c3(x2, y2);

		return new Triangle(l, c3); // carrep;
	}
	else
	{
		// Mauvaise entrée, on ne fait rien ?
		// Ou commentaire avec # (ou autre caractère)
		return NULL;
	}
}