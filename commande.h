#pragma once
#ifndef COMMANDE_H
#define COMMANDE_H
#include "produit.h"
#include "client.h"
#include <iostream>

class Commande{
public:
	Commande(Client client, std::vector<Produit> produits_achetes, bool valide);
	Client get_client();
	std::vector<Produit> get_liste_produits();
	bool get_valide();

private: 
	Client _client;
	std::vector<Produit> _produits_achetes;
	bool _valide;

};


#endif