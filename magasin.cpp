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
void Magasin::tous_produits() const{
	for(Produit p : _produit){
		std::cout << p;
	}
}
void Magasin::afficher_produit(std::string nom) const{
	int tmp=0;
	for(Produit p : _produit){
		if(p.get_titre()==nom){
			std::cout << p;
			tmp=1;
		}
	}
	if(tmp==0){
		std::cout << "Le produit recherché n'est pas dans le magasin." << std::endl;
	}
}
void Magasin::quantite_produit(std::string nom,int quantite){
	int tmp=0;
	for(Produit& p : _produit){
		if(p.get_titre()==nom){
			p.quantite_produit(quantite);
			tmp=1;
		}
	}
	if(tmp==0){
		std::cout << "Le produit recherché n'est pas dans le magasin." << std::endl;
	}
}