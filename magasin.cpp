#include "magasin.h"
#include <fstream>
#include "array"

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


void Magasin::lecture_donne(){
	std::string ligne_client="";
	int indice_client=0;
	std::array<std::string,4> client={};
	std::vector<Produit> panier_achat={};
	std::ifstream fichier_client;
	fichier_client.open("clients.txt");
	while (std::getline(fichier_client, ligne_client)) {
        std::getline(fichier_client, ligne_client);
        for(long unsigned int k=0;k<ligne_client.size();++k){
        	if(ligne_client.at(k)==';'){
        		indice_client++;
        	}
        	else{
        		client.at(indice_client)+=ligne_client.at(k);
        	}
        }
        Client c(client.at(0),client.at(1),client.at(2),panier_achat);
        _client.push_back(c);
        client={};
        indice_client=0;
        std::cout << ligne_client << std::endl;
    }


	std::string ligne_produit="";
	std::array<std::string,4> produit={};
	int indice_produit=0;
	std::ifstream fichier_produit;
	fichier_produit.open("produits.txt");
	int nb_ligne_produit = 0;
	while (std::getline(fichier_produit, ligne_produit)){
		nb_ligne_produit++;
	}
	fichier_produit.close();

	std::cout << nb_ligne_produit << std::endl;
	fichier_produit.open("produits.txt");
	for(int i=0;i<nb_ligne_produit;++i){
		std::getline(fichier_produit, ligne_produit);
        for(long unsigned int k=0;k<ligne_produit.size();++k){
        	if(ligne_produit.at(k)==';'){
        		indice_produit++;
        	}
        	else{
        		produit.at(indice_produit)+=ligne_produit.at(k);
        	}
        }
        Produit p(produit.at(0),produit.at(1),std::stoi(produit.at(2)),std::stof(produit.at(3)));
        _produit.push_back(p);
        produit={};
        indice_produit=0;
        std::cout << ligne_produit << std::endl;
    }
	fichier_produit.close();

	std::string ligne_commande="";
	std::ifstream fichier_commande;
	fichier_commande.open("commandes.txt");
	while (std::getline(fichier_commande, ligne_commande)) {
        std::cout << ligne_commande << std::endl;
    }
	fichier_commande.close();
}