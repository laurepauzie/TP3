#include "client.h"
#include "commande.h"
#include "magasin.h"
#include "produit.h"
#include <iostream>
#include <vector>

int main() {
  std::vector<Produit> produit = {};
  std::vector<Client> client = {};
  std::vector<Commande> commande = {};
  Magasin EasyStore(produit, client, commande);

  Produit p1("PS4", "Console de jeu Nitendo", 10, 499.99);
  Produit p2("Clavier DELL", "Clavier", 1, 29.99);
  Produit p3("Stylo", "Stylo bleu a encre", 5, 3.99);
  Produit p4("Sucette", "Bonbon gout fraise", 100, 0.99);
  Produit p5("Kindle", "Tablette liseuse", 8, 100.99);

  std::vector<Produit> pc1 = {p1, p2};
  std::vector<Produit> pc = {};
  Client cl("lchapus", "CHAPUS", "Louka", pc);
  Client lp("lpauzie", "PAUZIE", "Laure", pc1);
  std::vector<Client> clients = {cl, lp};

  Commande com1(lp, pc1, 1);
  panier(com1);
  // std::cout << com1 << std::endl;

  cl.ajouter_au_panier(p1);
  // std::cout << cl.get_panier_achat().at(0) << std::endl;
  cl.quantite_produit_panier(p1, 5);
  // std::cout << cl.get_panier_achat().at(0) << std::endl;

  EasyStore.ajout_produit(p1);
  EasyStore.ajout_produit(p2);
  // EasyStore.tous_produits();
  // EasyStore.afficher_produit("PS4");
  EasyStore.quantite_produit("PS4", 20);
  EasyStore.quantite_produit("Clavier DELL", 20);
  // EasyStore.afficher_produit("PS4");

  return 0;
}
