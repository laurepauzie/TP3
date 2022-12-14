#include "produit.h"
#include <assert.h>

Produit::Produit(std::string titre, std::string description, int quantite, float prix_unitaire) : _titre(titre), _description(description), _quantite(quantite), _prix_unitaire(prix_unitaire) {
	bool status = produit_valide(quantite,prix_unitaire);
	assert(status && "prix ou quantité du porduit non valide");
}
bool Produit::produit_valide(int quantite,float prix){
	if(quantite <= 0) return false;
	if(prix < 0) return false;
	return true;
}