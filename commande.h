#pragma once
#ifndef COMMANDE_H
#define COMMANDE_H

#include "client.h"
#include "produit.h"
#include <iostream>

class Commande{
public:
	Commande(Client client, std::vector<Produit> produits_achetes, bool valide);
	Client get_client() const;
	std::vector<Produit> get_liste_produits() const;
	bool get_valide() const;

private: 
	Client _client;
	std::vector<Produit> _produits_achetes;
	bool _valide;

};


#endif