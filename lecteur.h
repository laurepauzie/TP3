#pragma once
#ifndef LECTEUR_H
#define LECTEUR_H

#include <iostream>
#include <vector>


class Lecteur{
public:
	Lecteur(std::string identifiant, std::string nom, std::string prenom, std::vector<long int> liste_ISBN);
	std::string get_identifiant() const;
	std::string get_nom() const;
	std::string get_prenom() const;
	std::vector<long int> get_liste_ISBN() const;
	void add_ISBN(long int ISBN);
	void remove_ISBN(long int ISBN);
	
private: 
	std::string _identifiant;
	std::string _nom;
	std::string _prenom;
	std::vector<long int> _liste_ISBN;
};

std::ostream& operator<<(std::ostream& os, const Lecteur& lecteur);

#endif