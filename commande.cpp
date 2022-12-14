#include "commande.h"


Commande::Commande(Client c1, std::vector<Produit> produits_achetes, bool valide) : _c1(c1), _produits_achetes(produits_achetes), _valide(valide) {
}

Client Commande::get_client(){
	return _c1;
}

std::vector<Produit> Commande::get_liste_produits(){
	return _produits_achetes;
}

bool get_valide(){
	return _valide;
}