#include <iostream>
#include <vector>
#include <fstream>
#include "produit.h"
#include "client.h"
#include "commande.h"
#include "magasin.h"
#include "unistd.h"

void start(Magasin& magasin);
void gestion_magasin(Magasin& magasin);
void ajout_produit(Magasin& magasin);


int main()
{
	std::vector<Produit> produit = {};
	std::vector<Client> client  = {};
	std::vector<Commande> commande  = {};
	Magasin EasyStore(produit,client,commande);

	start(EasyStore);

	//Produit p1("PS4","Console de jeu Nitendo",10,499.99);
	//Produit p2("Clavier DELL","Clavier",1,29.99);
	//Produit p3("Stylo","Stylo bleu a encre",5,3.99);
	//Produit p4("Sucette","Bonbon gout fraise",100,0.99);
	//Produit p5("Kindle","Tablette liseuse",8,100.99);

	//std::vector<Produit> pc1 = {p1,p2};
	//std::vector<Produit> pc = {};
	//Client lc("lchapus","CHAPUS","Louka",pc);
	//Client lp("lpauzie","PAUZIE","Laure",pc);
	//std::vector<Client> clients = {lc,lp};

	
	//EasyStore.ajout_produit(p1);
	//EasyStore.ajout_produit(p2);
	//EasyStore.ajout_produit(p3);
	//EasyStore.ajout_produit(p4);
	//EasyStore.ajout_produit(p5);

	//EasyStore.afficher_tous_produits();

	//lc.ajouter_au_panier(p1);
	//lc.ajouter_au_panier(p5);
	//lc.quantite_produit_panier(p5,4);

	//EasyStore.achat_client(lc);
	
	//EasyStore.afficher_tous_produits();

	//EasyStore.afficher_historique_client(lc);

	//lp.ajouter_au_panier(p2);
	//lp.ajouter_au_panier(p4);
	//lp.quantite_produit_panier(p4,20);

	//EasyStore.afficher_tous_produits();
	
	//EasyStore.achat_client(lp);

	//EasyStore.afficher_historique_commandes();

	//EasyStore.lecture_donne();
	//EasyStore.afficher_tous_produits();

	//std::ofstream client_fichier;
	//client_fichier.open("clients.txt");
	//client_fichier << "test d'écriture d'une ligne." << std::endl;
	//client_fichier.close();
	
	return 0;
}


void start(Magasin& magasin){
	magasin.lecture_donne();
	system("clear");
	std::cout << "==================================================================================\n";
	std::cout << "|                          BIENVENUE DANS LE MAGASIN                             |\n";
	std::cout << "|================================================================================|\n";
	std::cout << "| Séléctionnez une action à faire parmis les suivantes :                         |\n";
	std::cout << "|--------------------------------------------------------------------------------|\n";
	std::cout << "| Gestion du magasin :       1                                                   |\n";
	std::cout << "| Gestion des utilisateurs : 2                                                   |\n";
	std::cout << "| Gestion des commandes :    3                                                   |\n";
	std::cout << "==================================================================================\n";
	int choix=0;
	std::cin >> choix;
	if(choix==1){
		gestion_magasin(magasin);
	}
	if (choix==2){

	}
	if (choix==3){

	}
	if(choix!=1 && choix!=2 && choix!=3){
		std::cout << "Commande inconue veuillez réessayer lorsque ce message disparaîtra 2 .\n";
		sleep(3);
		start(magasin);
	}
}

void gestion_magasin(Magasin& magasin){
	system("clear");
	std::cout << "==================================================================================\n";
	std::cout << "|                               GESTION DU MAGASIN                               |\n";
	std::cout << "|================================================================================|\n";
	std::cout << "| Séléctionnez une action à faire parmis les suivantes :                         |\n";
	std::cout << "|--------------------------------------------------------------------------------|\n";
	std::cout << "| Ajouter un produit :      1                                                    |\n";
	std::cout << "| Supprimer un produit :    2                                                    |\n";
	std::cout << "| Afficher un produit :     3                                                    |\n";
	std::cout << "| Ajouter un utilisateurs : 4                                                    |\n";
	std::cout << "| Revenir au menu :         5                                                    |\n";
	std::cout << "==================================================================================\n";
	int choix=0;
	std::cin >> choix;
	if(choix==1){
		ajout_produit(magasin);
	}
	if(choix==2){

	}
	if(choix==3){
		
	}
	if(choix==4){
		
	}
	if(choix==5){
		start(magasin);
	}
	if(choix!=1 && choix!=2 && choix!=3 && choix!=4 && choix!=5){
		std::cout << "Commande inconue veuillez réessayer lorsque ce message disparaîtra 1.\n";
		sleep(3);
		gestion_magasin(magasin);
	}
}

void ajout_produit(Magasin& magasin){
	system("clear");
	std::cout << "==================================================================================\n";
	std::cout << "|                               GESTION DU MAGASIN                               |\n";
	std::cout << "|================================================================================|\n";
	std::cout << "|                               AJOUT D'UN PRODUIT                               |\n";
	std::cout << "|================================================================================|\n";
	std::cout << "| Nom du produit : ";
	std::string nom;
	std::cin >> nom;
	bool tmp=false;
	for(Produit& p : magasin.get_produit())
	{
		if(nom==p.get_titre())
		{
			tmp=true;
		}
	}
	if(tmp)
	{
		std::cout << "| Un produit avec le même nom est déjà dans le magasin, voulez-vous mettre à jour|\n";
		std::cout << "| la quantité de ce produit ?                                                    |\n";
		std::cout << "| o pour oui et n pout non                                                       |\n";
		std::string produit_double="";
		std::cin >> produit_double;
		if(produit_double=="o" || produit_double=="O")
		{
			std::cout << "|--------------------------------------------------------------------------------|\n";
			std::cout << "| Entrez la nouvelle quantité pour le produit : ";
			int quantite=0;
			std::cin >> quantite;
		}
		else{
			gestion_magasin(magasin);
		}
	}

}