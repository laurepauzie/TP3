#include "commande.h"


Commande::Commande(Client client, std::vector<Produit> produits_achetes, bool valide) : _client(client), _produits_achetes(produits_achetes), _valide(valide) {
}

Client Commande::get_client(){
	return _client;
}

std::vector<Produit> Commande::get_liste_produits(){
	return _produits_achetes;
}

bool Commande::get_valide(){
	return _valide;
}