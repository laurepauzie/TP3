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

	Produit p1("PS4","Console de jeu Nitendo",10,499.99);
	Produit p2("Clavier DELL","Clavier",1,29.99);
	Produit p3("Stylo","Stylo bleu a encre",5,3.99);
	Produit p4("Sucette","Bonbon gout fraise",100,0.99);
	Produit p5("Kindle","Tablette liseuse",8,100.99);

	//detail_produit(p1);

	std::vector<Produit> pc1 = {p1,p2};
	std::vector<Produit> pc = {};
	Client lc("lchapus","CHAPUS","Louka",pc);
	Client lp("lpauzie","PAUZIE","Laure",pc);
	std::vector<Client> clients = {lc,lp};

	
	EasyStore.ajout_produit(p1);
	EasyStore.ajout_produit(p2);
	EasyStore.ajout_produit(p3);
	EasyStore.ajout_produit(p4);
	EasyStore.ajout_produit(p5);

	//EasyStore.afficher_tous_produits();

	lc.ajouter_au_panier(p1);
	lc.ajouter_au_panier(p5);
	lc.quantite_produit_panier(p5,4);

	EasyStore.achat_client(lc);
	//EasyStore.afficher_tous_produits();

	//EasyStore.afficher_historique_client(lc);

	lp.ajouter_au_panier(p3);
	lp.ajouter_au_panier(p4);
	lp.quantite_produit_panier(p4,20);

	EasyStore.afficher_tous_produits();
	
	EasyStore.achat_client(lp);

	EasyStore.afficher_historique_commandes();

	EasyStore.afficher_tous_produits();
	return 0;
}
