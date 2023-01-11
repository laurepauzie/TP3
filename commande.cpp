#include "commande.h"

Commande::Commande(Client client, std::vector<Produit> produits_achetes,bool valide) : _client(client), _produits_achetes(produits_achetes), _valide(valide) {}

Client Commande::get_client() const { 
  return _client; 
}

std::vector<Produit> Commande::get_liste_produits() const {
  return _produits_achetes;
}

bool Commande::get_valide() const { return _valide; }

void Commande::set_valide(bool val) { _valide = val; }

void panier(Commande &commande) {
  std::string ligne =
      "-----------------------------------------------------------";
  std::cout << ligne << std::endl;
  std::cout << "| Panier                                                  |"
            << std::endl;
  std::cout << "-----------------------------------------------------------"
            << std::endl;
  std::cout << commande << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Commande &commande) {
  std::string ligne="--------------------------------------------------------------------------";
  std::string ligne_barre="|------------------------------------------------------------------------|";
  std::cout << ligne << std::endl;
  os << commande.get_client();
  os << ligne_barre << std::endl;
  os << "| Liste des produits achetés :                                           |" << std::endl;
  for (Produit k : commande.get_liste_produits()) {
    os << "| " << k << "  |" << std::endl;
  }
  os << "|                                                                        |" << std::endl;
  os << "| Statut de la commande : ";
  if(commande.get_valide()){
    os << "valide                                         |" << std::endl;
  }
  else{
    os << "unvalide                                       |" << std::endl;
  }
  
  std::cout << ligne << std::endl;
  return os;
}
