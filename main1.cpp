#include <iostream>
#include <vector>
#include "produit.h"
#include "client.h"
#include "commande.h"
#include "magasin.h"


int main()
{
	std::vector<Produit> produit = {};
	std::vector<Client> client  = {};
	std::vector<Commande> commande  = {};
	Magasin EasyStore(produit,client,commande);


	Produit p1("PS4","Console de jeu",10,499.99);
	Produit p2("Clavier DELL","Clavier",1,29.99);

	std::vector<Produit> pc1 = {p1,p2};
	std::vector<Produit> pc = {};
	Client cl("lchapus","CHAPUS","Louka",pc);
	Client lp("lpauzie","PAUZIE","Laure",pc);
	std::vector<Client> clients = {cl,lp};

	EasyStore.ajout_produit(p1);
	EasyStore.ajout_produit(p2);
	//EasyStore.tous_produits();
	EasyStore.afficher_produit("PS4");
	EasyStore.quantite_produit("PS4",20);
	EasyStore.afficher_produit("PS4");

	return 0;
}
