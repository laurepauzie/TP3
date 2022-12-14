#pragma once
#ifndef DATE_H
#define DATE_H

#include <iostream>

class Date{
public:
	Date(int jours=1,int mois=1,int annee=2000);	
	int get_annee() const;
	int get_mois() const;
	int get_jours() const;
	std::string to_text();
private:
	int _annee;
	int _mois;
	int _jours;
	bool date_valide(int jours,int mois,int annee);
};

#endif