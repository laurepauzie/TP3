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
void Magasin::afficher_tous_produits() const{
	std::string ligne="--------------------------------------------------------------------------";
	std::cout << ligne << std::endl;
	std::cout << "| Détails de tous les produits du magasin                                |" << std::endl;
	std::cout << "|------------------------------------------------------------------------|" << std::endl;
	std::cout << "| Nom                Description                  Quantité    Prix       |" << std::endl;
	std::cout << "|------------------------------------------------------------------------|" << std::endl;
	
	for(Produit p : _produit){
		std::cout << "| " << p << "  |" << std::endl;
	}
	std::cout << ligne << std::endl;
}
void Magasin::afficher_produit(std::string nom) const{
	int tmp=0;
	for(Produit p : _produit){
		if(p.get_titre()==nom){
			detail_produit(p);
		}
	}
	if(tmp==0){
		std::cout << "Le produit recherché n'est pas dans le magasin." << std::endl;
	}
}
void Magasin::quantite_produit(std::string nom,int quantite){
	int tmp=0;
	for(Produit& p : _produit){
		if(p.get_titre() == nom){
			p.quantite_produit(quantite);
			tmp=1;
		}
	}
	if(tmp==0){
		std::cout << "Le produit recherché n'est pas dans le magasin." << std::endl;
	}
}
void Magasin::achat_client(Client& client){
	bool tmp=true;
	for(Produit& prod1 : client.get_panier_achat()){
		for(Produit& prod2 : _produit){
			if(prod1.get_titre()==prod2.get_titre()){
				if(prod2.get_quantite()<prod1.get_quantite()){
					tmp=false;
				}
			}
		}
	}

	
	Commande commande(client,client.get_panier_achat(),tmp);
	_commande.push_back(commande);
	if(tmp){
		for(Produit& prod1 : client.get_panier_achat()){
			for(Produit& prod2 : _produit){
				if(prod1.get_titre()==prod2.get_titre()){
					prod2.quantite_produit(prod2.get_quantite()-prod1.get_quantite());
				}
			}
		}
	}
	client.vider_panier();
	_client.push_back(client);
}
void Magasin::afficher_historique_commandes() const{
	std::cout << "-----------------------------------------------------------------" << std::endl;
	std::cout << "|                 Historique global des commandes               |" << std::endl;
	std::cout << "-----------------------------------------------------------------" << std::endl;
	for(Commande com : _commande){
		std::cout << com << std::endl;
	}
}
void Magasin::afficher_historique_client(Client client){
	for(long unsigned int k=0;k<_client.size();++k){
		if(client.get_identifiant()==_commande.at(k).get_client().get_identifiant()){
			std::cout << _commande.at(k);
		}
	}
}

void Magasin::ajouter_panier_achat_client(Produit produit, Client& client){
	client.ajouter_au_panier(produit);
}
void Magasin::supprimer_panier_achat_client(Produit produit, Client& client){
	client.supprimer_produit_panier(produit);
}
void Magasin::modifier_quantite_produit_panier_client(Produit produit, Client& client, int quantite){
	client.quantite_produit_panier(produit, quantite);
}