#include "commande.h"


Commande::Commande(Client client, std::vector<Produit> produits_achetes, bool valide) : _client(client), _produits_achetes(produits_achetes), _valide(valide) {
}

Client Commande::get_client() const {
	return _client;
}

std::vector<Produit> Commande::get_liste_produits() const {
	return _produits_achetes;
}

bool Commande::get_valide() const {
	return _valide;
}

void Commande::set_valide(bool val) {
	_valide = val;
}

std::ostream& operator<<(std::ostream& os, const Commande& commande){
	os << std::endl;
	os << "Client : " << commande.get_client(). << std::endl;
	for(Client c : commande.get_client()){
		os << c << " - ";
	}
	os << std::endl;

	os << "Liste des produits achetés : ";
	for(Produit k : commande.get_liste_produits()){
		os << k << " ,";
	}
	os << std::endl;

	os << "Statut de la commande : " << commande.get_valide() << std::endl;

	return os;
}