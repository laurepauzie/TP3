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
	std::vector<Produit> get_produit() const;
	std::vector<Client> get_client() const;
	std::vector<Commande> get_commande() const;
	void ajout_produit(Produit produit);
	void afficher_tous_produits() const;
	void afficher_produit(std::string nom) const;
	void quantite_produit(std::string nom,int quantite);
	void achat_client(Client& client);
private:
	std::vector<Produit> _produit;
	std::vector<Client> _client;
	std::vector<Commande> _commande;
};

#endif