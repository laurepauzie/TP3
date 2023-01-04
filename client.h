#pragma once
#ifndef CLIENT_H
#define CLIENT_H

#include <vector>
#include <iostream>
#include "produit.h"

class Client{
public:
	Client(std::string identifiant, std::string nom, std::string prenom, std::vector<Produit> panier_achat);
	std::string get_identifiant() const;
	std::string get_nom() const;
	std::string get_prenom() const;
	std::vector<Produit> get_panier_achat() const;
	void ajouter_au_panier(Produit produit);
	void vider_panier();
	void quantite_produit_panier(Produit produit,int quantite);
	void supprimer_produit_panier(Produit produit);
private: 
	std::string _identifiant;
	std::string _nom;
	std::string _prenom;
	std::vector<Produit> _panier_achat;
};

std::ostream& operator<<(std::ostream& os, const Client& client);

#endif