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
	

	std::vector<Produit> pc;
	Client cl("lchapus","CHAPUS","Louka",pc);
	Client lp("lpauzie","PAUZIE","Laure",pc);
	std::vector<Client> clients = {cl,lp};

	std::cout << cl.get_nom() << std::endl;
	
	return 0;
}
