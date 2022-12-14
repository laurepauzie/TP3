#pragma once
#ifndef COMMANDE_H
#define COMMANDE_H
#include "produit.h"
#include "client.h"
#include <iostream>

class Commande{
public:
	Commande(Client client, std::vector<Produit> produits_achetes, bool valide);
	Client get_client() const;
	std::vector<Produit> get_liste_produits() const;
	bool get_valide() const;
	void set_valide(bool val);

private: 
	Client _client;
	std::vector<Produit> _produits_achetes;
	bool _valide;

};

std::ostream& operator<<(std::ostream& os, const Commande& commande);

#endif