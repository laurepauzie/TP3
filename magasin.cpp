#include "magasin.h"


Magasin::Magasin(std::vector<Produit> produit, std::vector<Client> client, std::vector<Commande> commande) : _produit(produit), _client(client), _commande(commande) {

}
int Magasin::get_produit() const{
	return _produit;
}
int Magasin::get_client() const{
	return _client;
}
int Magasin::get_commande() const{
	return _commande;
}