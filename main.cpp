#include <iostream>
#include <vector>
#include "commande.h"

int main()
{
	std::cout << "test" << std::endl;
	std::cout << "test" << std::endl;

	Produit p("PS4","Console de jeu",10,499.99);
	std::cout << p.get_description() << std::endl;

	Produit c("Clavier DELL","Clavier",1,29.99);

	std::vector<Produit> pc = {p, c};
	Client c1("lchapus","CHAPUS","Louka",pc);
	std::cout << c1.get_nom() << std::endl;
	
	Commande com1(c1, pc, true);
	

	return 0;
}
