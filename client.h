#pragma once
#ifndef CLIENT_H
#define CLIENT_H

#include <vector>
#include <iostream>
#include "produit.h"

class Client{
public:
	Client(std::string identifiant, std::string nom, std::string prenom, std::vector<Produit> panier_achat);
private: 
	std::string _identifiant;
	std::string _nom;
	std::string _prenom;
	std::vector<Produit> _panier_achat;
};


#endif