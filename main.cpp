#include <iostream>
#include <vector>
#include "produit.h"
#include "client.h"

int main()
{
	std::cout << "test" << std::endl;
	std::cout << "test" << std::endl;

	Produit p("PS4","Console de jeu",10,499.99);
	std::cout << p.get_description() << std::endl;

	std::vector<Produit> pc;
	Client c1("lchapus","CHAPUS","Louka",pc);
	std::cout << c1.get_nom() << std::endl;
	
	return 0;
}
