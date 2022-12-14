#include <iostream>
#include <vector>
#include "produit.h"
#include "client.h"
#include "commande.h"
#include "magasin.h"


int main()
{
	Magasin EasyStore();

	Produit p("PS4","Console de jeu",10,499.99);
	std::cout << "Avant mise à jour" << std::endl;
	std::cout << p;
	p.quantite_produit(80);
	std::cout << "Après mise à jour" << std::endl;
	std::cout << p;
	
	Produit c("Clavier DELL","Clavier",1,29.99);

	std::vector<Produit> pc = {p, c};

	Client cl("lchapus","CHAPUS","Louka",pc);
	Client lp("lpauzie","PAUZIE","Laure",pc);
	std::vector<Client> clients = {cl,lp};

	std::cout << cl.get_nom() << std::endl;

	Commande com1(cl, pc, true);
	

	return 0;
}
