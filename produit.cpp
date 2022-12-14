#include "produit.h"
#include <assert.h>

Produit::Produit(std::string titre, std::string description, int quantite, float prix_unitaire) : _titre(titre), _description(description), _quantite(quantite), _prix_unitaire(prix_unitaire) {
	bool status = produit_valide(quantite,prix_unitaire);
	assert(status && "prix ou quantité du porduit non valide");
}
bool Produit::produit_valide(int quantite,float prix){
	if(quantite < 0) return false;
	if(prix < 0) return false;
	return true;
}
std::string Produit::get_titre() const{
	return _titre;
}
std::string Produit::get_description() const{
	return _description;
}
int Produit::get_quantite() const{
	return _quantite;
}
float Produit::get_prix_unitaire() const{
	return _prix_unitaire;
}
void Produit::quantite_produit(int quantite){
	bool status = (quantite>0);
	assert(status && "quantité négative lors de la mise à jour");
	_quantite = quantite;
}
std::ostream& operator<<(std::ostream& os, const Produit& produit){
	os << std::endl;
	os << "Nom du produit : " << produit.get_titre() << std::endl;
	os << "Description : " << produit.get_description() << std::endl;
	os << "Prix du produit : " << produit.get_prix_unitaire() << std::endl;
	os << "Quantité restante : " << produit.get_quantite() << std::endl;
	return os;
}