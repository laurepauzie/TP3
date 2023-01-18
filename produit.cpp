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
	bool status = (quantite>=0);
	assert(status && "quantité négative lors de la mise à jour");
	_quantite = quantite;
}
void detail_produit(Produit& produit){
	std::string ligne="-----------------------------------------------------------------------------------------------";
	std::cout << ligne << std::endl;
	std::cout << "| Détail du produit                                                                           |" << std::endl;
	std::cout << "|---------------------------------------------------------------------------------------------|" << std::endl;
	std::cout << "| " << produit << "  |" << std::endl;
	std::cout << ligne << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Produit& produit){
	os << produit.get_titre();
	for(int k=produit.get_titre().size();k<19;k++){
		os << " ";
	}
	os << " " << produit.get_description();
	for(int k=produit.get_description().size();k<49;k++){
		os << " ";
	}
	
	if(produit.get_quantite()>=100){
		os << " (" << produit.get_quantite() << ")     ";
	}
	if(produit.get_quantite()<10){
		os << " (" << produit.get_quantite() << ")       ";
	}
	if(produit.get_quantite()>=10 && produit.get_quantite()<100){
		os << " (" << produit.get_quantite() << ")      ";
	}
	
	if(produit.get_prix_unitaire()<100.0 && produit.get_prix_unitaire()>=10.0){
		os << produit.get_prix_unitaire() << "   € ";
	}
	if(produit.get_prix_unitaire()<10.0){
		os << produit.get_prix_unitaire() << "    € ";
	}
	if(produit.get_prix_unitaire()>=100.0 && produit.get_prix_unitaire() <1000.0){
		os << produit.get_prix_unitaire() << "  € ";
	}
	if(produit.get_prix_unitaire()>=1000.0){
		os << produit.get_prix_unitaire() << " € ";
	}
	return os;
}