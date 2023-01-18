#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "produit.h"
#include "client.h"
#include "commande.h"
#include "magasin.h"
#include "unistd.h"

//prototype des focntions utilisé plustard dans le programme
void start(Magasin& magasin);
void gestion_magasin(Magasin& magasin);
void ajout_produit(Magasin& magasin);
void afficheage_produit(Magasin& magasin);
void ajout_client(Magasin& magasin);
void suprimer_produit(Magasin& magasin);
void gestion_commande(Magasin& magasin);
void affichage_client_commande(Magasin& magasin);

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
  
  //std::cout << "test dans le main" << std::endl;
  //std::string phrase;
  //getline(std::cin, phrase);
  //std::cout << phrase << std::endl;

  return 0;
}


void start(Magasin& magasin)
{
  magasin.lecture_donne();
  system("clear");
  std::cout << "==================================================================================\n";
  std::cout << "|                          BIENVENUE DANS LE MAGASIN                             |\n";
  std::cout << "|================================================================================|\n";
  std::cout << "| Séléctionnez une action à faire parmis les suivantes :                         |\n";
  std::cout << "|--------------------------------------------------------------------------------|\n";
  std::cout << "| Gestion du magasin :       1                                                   |\n";
  std::cout << "| Gestion des clients :      2                                                   |\n";
  std::cout << "| Gestion des commandes :    3                                                   |\n";
  std::cout << "==================================================================================\n";
  std::cout << "> ";
  std::string choix="0";
  std::cin >> choix;

  if(choix=="1"){
    gestion_magasin(magasin);
  }
  if (choix=="2"){

  }
  if (choix=="3"){

  }
  if(choix!="1" && choix!="2" && choix!="3"){
    std::cout << "Commande inconue veuillez réessayer lorsque ce message disparaîtra.\n";
    sleep(3);
    start(magasin);
  }
}

void gestion_magasin(Magasin& magasin)
{
  system("clear");
  std::cout << "==================================================================================\n";
  std::cout << "|                               GESTION DU MAGASIN                               |\n";
  std::cout << "|================================================================================|\n";
  std::cout << "| Séléctionnez une action à faire parmis les suivantes :                         |\n";
  std::cout << "|--------------------------------------------------------------------------------|\n";
  std::cout << "| Ajouter un produit :      1                                                    |\n";
  std::cout << "| Supprimer un produit :    2                                                    |\n";
  std::cout << "| Afficher un produit :     3                                                    |\n";
  std::cout << "| Ajouter un client :       4                                                    |\n";
  std::cout << "| Revenir au menu :         5                                                    |\n";
  std::cout << "==================================================================================\n";
  std::cout << "> ";
  std::string choix="0";
  std::cin >> choix;

  if(choix=="1"){
    ajout_produit(magasin);
  }
  if(choix=="2"){
    suprimer_produit(magasin);
  }
  if(choix=="3"){
    afficheage_produit(magasin);
  }
  if(choix=="4"){
    ajout_client(magasin);
  }
  if(choix=="5"){
    start(magasin);
  }
  if(choix!="1" && choix!="2" && choix!="3" && choix!="4" && choix!="5"){
    std::cout << "Commande inconue veuillez réessayer lorsque ce message disparaîtra.\n";
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
  std::cout << "| Nom du produit :                                                               |\n";
  std::cout << "|--------------------------------------------------------------------------------|\n";
  std::cout << "> ";
  std::string nom="";
  std::cin >> nom;
  for(Produit& p : magasin.get_produit())
  {
    if(nom==p.get_titre())
    {
      std::cout << "|--------------------------------------------------------------------------------|\n";
      std::cout << "| Un produit avec le même nom est déjà dans le magasin, voulez-vous mettre à jour|\n";
      std::cout << "| la quantité de ce produit ?                                                    |\n";
      std::cout << "| o pour oui et n pout non                                                       |\n";
      std::cout << "|--------------------------------------------------------------------------------|\n";
      std::cout << "> ";
      std::string produit_double="";
      std::cin >> produit_double;
      if(produit_double=="o" || produit_double=="O")
      {
        std::cout << "|--------------------------------------------------------------------------------|\n";
        std::cout << "| Entrez la nouvelle quantité pour le produit : ";
        std::cout << "|--------------------------------------------------------------------------------|\n";
        std::cout << "> ";
        int quantite=0;
        std::cin >> quantite;
        p.quantite_produit(quantite);
        std::cout << "|--------------------------------------------------------------------------------|\n";
        std::cout << "| Quantité mise à jour, retour au menu de la gestion de magasin.                 |\n";
        std::cout << "|--------------------------------------------------------------------------------|\n";
        gestion_magasin(magasin);
      }
      else
      {
        gestion_magasin(magasin);
      }
    }
  }
  std::cout << "|--------------------------------------------------------------------------------|\n";
  std::cout << "| Description du produit :                                                       |\n";
  std::cout << "|--------------------------------------------------------------------------------|\n";
  std::cout << "> ";
  std::string phrase;
  std::cin.ignore();
  getline(std::cin, phrase);

  std::cout << "|--------------------------------------------------------------------------------|\n";
  std::cout << "| Quantité à ajouter dans le magasin :                                           |\n";
  std::cout << "|--------------------------------------------------------------------------------|\n";
  std::cout << "> ";
  int quantite_p=0;
  std::cin >> quantite_p;

  std::cout << "|--------------------------------------------------------------------------------|\n";
  std::cout << "| Prix unitaire du produit :                                                     |\n";
  std::cout << "|--------------------------------------------------------------------------------|\n";
  std::cout << "> ";
  float prix=0.0;
  std::cin >> prix;
  Produit produit(nom,phrase,quantite_p,prix);
  magasin.ajout_produit(produit);
  gestion_magasin(magasin);
}
void suprimer_produit(Magasin& magasin){
  system("clear");
  std::cout << "==================================================================================\n";
  std::cout << "|                               GESTION DU MAGASIN                               |\n";
  std::cout << "|================================================================================|\n";
  std::cout << "|                               AFFICHER UN PRODUIT                              |\n";
  std::cout << "|--------------------------------------------------------------------------------|\n";
  std::cout << "| Saisissez le nom du produit à supprimer parmis les noms suivants :             |\n";
  std::cout << "|--------------------------------------------------------------------------------|\n";
  for(Produit p : magasin.get_produit())
  {
    std::cout << "|   " << p.get_titre();
    for(int k=p.get_titre().size();k<77;++k)
    {
      std::cout << " ";
    }
    std::cout << "|\n";
  }
  std::cout << "==================================================================================\n";
  std::cout << "> ";
  std::string nom;
  std::cin >> nom;
  for(Produit p : magasin.get_produit())
  {
    if(nom==p.get_titre()){
      magasin.supprimer_produit(p);
    }
  }
  gestion_magasin(magasin);
}

void afficheage_produit(Magasin& magasin){
  system("clear");
  std::cout << "==================================================================================\n";
  std::cout << "|                               GESTION DU MAGASIN                               |\n";
  std::cout << "|================================================================================|\n";
  std::cout << "|                               AFFICHER UN PRODUIT                              |\n";
  std::cout << "|--------------------------------------------------------------------------------|\n";
  std::cout << "| Saisissez le nom du produit à afficher parmis les noms suivants :              |\n";
  std::cout << "| (écrire 'tous' pour tous les afficher)                                         |\n";
  std::cout << "|--------------------------------------------------------------------------------|\n";
  for(Produit p : magasin.get_produit())
  {
    std::cout << "|   " << p.get_titre();
    for(int k=p.get_titre().size();k<77;++k)
    {
      std::cout << " ";
    }
    std::cout << "|\n";
  }

  std::cout << "==================================================================================\n";
  std::string nom;
  std::cin >> nom;
  if(nom=="tous"){
    system("clear");
    magasin.afficher_tous_produits();
    std::cout << "==================================================================================\n";
    std::cout << "| Appuyer sur un touche pour revnenir au menu.                                   |\n";
    std::cout << "==================================================================================\n";
    std::cin >> nom;
    gestion_magasin(magasin);
  }
  else{
    system("clear");
    magasin.afficher_produit(nom);
    std::cout << "==================================================================================\n";
    std::cout << "| Appuyer sur un touche pour revnenir au menu.                                   |\n";
    std::cout << "==================================================================================\n";
    std::cin >> nom;
    gestion_magasin(magasin);
  }
}

void ajout_client(Magasin& magasin){
  system("clear");
  std::cout << "==================================================================================\n";
  std::cout << "|                               GESTION DU MAGASIN                               |\n";
  std::cout << "|================================================================================|\n";
  std::cout << "|                             AJOUT D'UN CLIENT                                |\n";
  std::cout << "|================================================================================|\n";
  std::cout << "| Nom du client :                                                                |\n";
  std::cout << "|--------------------------------------------------------------------------------|\n";
  std::cout << "> ";
  std::string nom="";
  std::cin >> nom;
  std::cout << "|--------------------------------------------------------------------------------|\n";
  std::cout << "| Prénom du client :                                                             |\n";
  std::cout << "|--------------------------------------------------------------------------------|\n";
  std::cout << "> ";
  std::string prenom="";
  std::cin >> prenom;
  std::string identifiant="";
  identifiant = prenom+nom;
  std::vector<Produit> panier_achat = {};
  Client client(identifiant,nom,prenom,panier_achat);
  magasin.ajout_client(client);
  gestion_magasin(magasin);
}

void gestion_commande(Magasin& magasin){
  system("clear");
  std::cout << "==================================================================================\n";
  std::cout << "|                               GESTION DES COMMANDES                            |\n";
  std::cout << "|================================================================================|\n";
  std::cout << "| Séléctionnez une action à faire parmis les suivantes :                         |\n";
  std::cout << "|--------------------------------------------------------------------------------|\n";
  std::cout << "| Afficher un client :      1                                                    |\n";
  std::cout << "| Revenir au menu :         2                                                    |\n";
  std::cout << "==================================================================================\n";
  std::cout << "> ";
  std::string choix="0";
  std::cin >> choix;

  if(choix=="1"){
    affichage_client_commande(magasin);
  }

  if(choix=="2"){
    start(magasin);
  }
  if(choix!="1" && choix!="2"){
    std::cout << "Commande inconue veuillez réessayer lorsque ce message disparaîtra.\n";
    sleep(3);
    gestion_commande(magasin);
  }
}

void affichage_client_commande(Magasin& magasin){
  system("clear");
  std::cout << "==================================================================================\n";
  std::cout << "|                               GESTION DES COMMANDES                            |\n";
  std::cout << "|================================================================================|\n";
  std::cout << "|                               AFFICHER UN CLIENT                               |\n";
  std::cout << "|--------------------------------------------------------------------------------|\n";
  std::cout << "| Saisissez le nom du client à afficher parmis les noms suivants :               |\n";
  std::cout << "| (écrire 'tous' pour affcher tous les clients)                                  |\n";
  std::cout << "|--------------------------------------------------------------------------------|\n";
  for(Client& c : magasin.get_client())
  {
    std::cout << "|   " << c.get_nom();
    for(int k=c.get_nom().size();k<77;++k)
    {
      std::cout << " ";
    }
    std::cout << "|\n";
  }

  std::cout << "==================================================================================\n";
  std::string nom;
  std::cin >> nom;
  if(nom=="tous"){
    system("clear");
    std::string ligne="-----------------------------------------------------------------------------------------------";
    std::cout << ligne << std::endl;
    std::cout << "| Détails de tous les clients du magasin                                                      |\n";
    std::cout << "|---------------------------------------------------------------------------------------------|\n";
    std::cout << "| Identifiant                                 Nom                     Prénom                  |\n";
    std::cout << "|---------------------------------------------------------------------------------------------|\n";
  
    for(Client& c : magasin.get_client()){
      std::cout << "| " << c.get_identifiant();
      for(int k=c.get_identifiant().size();k<29;k++){
        std::cout << " ";
      }
      std::cout << c.get_nom();
      for(int k=c.get_nom().size();k<19;k++){
        std::cout << " ";
      }
      std::cout << c.get_prenom();
      for(int k=c.get_prenom().size();k<19;k++){
        std::cout << " ";
      }
      std::cout << "  |" << std::endl;
    }
    std::cout << ligne << std::endl;
    std::cout << "==================================================================================\n";
    std::cout << "| Appuyer sur un touche pour revnenir au menu.                                   |\n";
    std::cout << "==================================================================================\n";
    std::cin >> nom;
    gestion_commande(magasin);
  }
  else{
    system("clear");
    int tmp=true;
    for(Client& c : magasin.get_client()){
      if(c.get_nom()==nom){
        std::string ligne="-----------------------------------------------------------------------------------------------";
        std::cout << ligne << std::endl;
        std::cout << "| Détail du client                                                                            |" << std::endl;
        std::cout << "|---------------------------------------------------------------------------------------------|" << std::endl;
        std::cout << "| " << c << "  |" << std::endl;
        std::cout << ligne << std::endl;
        tmp=false;
      }
    }
    if(tmp){
      std::cout << "--------------------------------------------------------------------------\n";
      std::cout << "| Le client recherché n'existe pas dans le magasin.                      |\n";
      std::cout << "--------------------------------------------------------------------------\n";
    }
    std::cout << "==================================================================================\n";
    std::cout << "| Appuyer sur un touche pour revenir au menu.                                   |\n";
    std::cout << "==================================================================================\n";
    std::cin >> nom;
    gestion_commande(magasin);
  }
}

