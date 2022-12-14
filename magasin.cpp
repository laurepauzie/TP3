#include "magasin.h"


Magasin::Magasin(std::vector<Produit> produit, std::vector<Client> client, std::vector<Commande> commande) : _produit(produit), _client(client), _commande(commande) {

}
std::vector<Produit> Magasin::get_produit() const{
	return _produit;
}
std::vector<Client> Magasin::get_client() const{
	return _client;
}
std::vector<Commande> Magasin::get_commande() const{
	return _commande;
}
void Magasin::ajout_produit(Produit produit){
	_produit.push_back(produit);
}