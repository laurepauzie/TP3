#pragma once
#ifndef PRODUIT_H
#define PRODUIT_H

#include <iostream>

class Produit{
public:
	Produit(std::string titre, std::string description, int quantite, float prix_unitaire);
private:
	std::string _titre;
	std::string _description;
	int _quantite;
	float _prix_unitaire;
	bool produit_valide(int quantite,float prix);
};


#endif