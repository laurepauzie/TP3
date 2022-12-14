
#include "client.h"

Client::Client(std::string identifiant, std::string nom, std::string prenom, std::vector<Produit> panier_achat) : _identifiant(identifiant), _nom(nom), _prenom(prenom), _panier_achat(panier_achat) {
}
std::string Client::get_identifiant() const{
	return _identifiant;
}
std::string Client::get_nom() const{
	return _nom;
}
std::string Client::get_prenom() const{
	return _prenom;
}
std::vector<Produit> Client::get_panier_achat() const{
	return _panier_achat;
}
void Client::ajouter_au_panier(Produit produit){
	_panier_achat.push_back(produit);
}
void Client::vider_panier(){
	_panier_achat = {};
}