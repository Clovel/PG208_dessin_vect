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

// Accesseurs
Forme *Dessin::getFormeFromIdx(unsigned int const &index) const
{
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

// Fonctions publiques diverses

void Dessin::drawAll(CImage *img) const
{
	for(unsigned int i = 0; i < getFormes().size(); i++)
	{
		getFormeFromIdx(i)->draw(img);
	}
}