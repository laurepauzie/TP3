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
	

	std::vector<Produit> pc;
	Client cl("lchapus","CHAPUS","Louka",pc);
	Client lp("lpauzie","PAUZIE","Laure",pc);
	std::vector<Client> clients = {cl,lp};

	EasyStore.ajout_produit(p1);
	std::cout << EasyStore.get_produit().at(0);

	return 0;
}
