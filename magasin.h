#pragma once
#ifndef MAGASIN_H
#define MAGASIN_H

#include "produit.h"
#include "client.h"
#include "commande.h"
#include <vector>
#include <iostream>

class Magasin{
public:
	Magasin(std::vector<Produit> produit, std::vector<Client> client, std::vector<Commande> commande);	
	int get_produit() const;
	int get_client() const;
	int get_commande() const;
private:
	std::vector<Produit> _produit;
	std::vector<Client> _client;
	std::vector<Commande> _commande;
};

#endif