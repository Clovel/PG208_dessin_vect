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
Forme Dessin::getForme(unsigned int const &index) const
{
	return m_formes[index];
}

vector<Forme> Dessin::getVectorForme(void) const
{
	return m_formes;
}

// Mutateurs

void Dessin::setForme(Forme const &f, unsigned int const &index)
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

void Dessin::addForme(Forme const &f)
{
	m_formes.push_back(f);
}