#include <iostream>
#include <vector>
#include "livre.h"
#include "bibliotheque.h"
#include "auteur.h"
#include "lecteur.h"
#include "emprunt.h"

int main()
{
	Date date_vh(26,2,1802);
	Auteur VH("Vhugo","Hugo","Victor",date_vh);
	Date date_ac(7,11,1913);
	Auteur AC("Acamus","Camus","Albert",date_ac);
	Date date_ez(2,4,1902);
	Auteur EZ("Ezola","Zola","Emile",date_ez);
	std::vector<Auteur> auteurs = {VH,AC,EZ};

	std::vector<long int> liste_l1 = {};
	Lecteur l1("lchapus","CHAPUS","Louka",liste_l1);
	Lecteur l2("lpauzie","PAUZIE","Laure",liste_l1);
	Lecteur l3("rzapata","ZAPATA","Romain",liste_l1);
	std::vector<Lecteur> lecteurs = {l1,l2,l3};

	std::vector<std::string> emprunteur = {};
	Date publi_les_miserable(17,5,1892);
	Livre VH_Les_Miserables("Les Misérables",VH,"Français","Roman",publi_les_miserable,9780453009669,emprunteur,true);
	Date publi_les_contemplations(1,1,1856);
	Livre VH_Les_Contemplations("Les Contemplations",VH,"Français","Poésie",publi_les_contemplations,9780453009520,emprunteur,true);
	Date publi_notre_dame_de_paris(16,3,1856);
	Livre VH_Notre_Dame_de_Paris("Notre Dame de Paris",VH,"Français","Roman",publi_notre_dame_de_paris,9780453009604,emprunteur,true);
	Date publi_poemes_de_victor_hugo(1,1,1830);
	Livre VH_Poemes_de_Victor_Hugo("Poèmes de Victor Hugo",VH,"Français","Poésie",publi_poemes_de_victor_hugo,9780453009702,emprunteur,true);
	Date publi_germinal(1,1,1885);
	Livre EZ_Germinal("Germinal",EZ,"Français","Roman",publi_germinal,9788453489504,emprunteur,true);
	Date publi_nana(5,2,1880);
	Livre EZ_Nana("Nana",EZ,"Français","Roman",publi_nana,9788453489984,emprunteur,true);
	Date publi_j_accuse(13,1,1898);
	Livre EZ_J_accuse("J'accuse... !",EZ,"Français","Roman",publi_j_accuse,9788453489420,emprunteur,true);
	Date publi_l_etranger(1,1,1942);
	Livre AC_L_etranger("L'étranger",AC,"Français","Roman",publi_l_etranger,9788415607845,emprunteur,true);
	std::vector<Livre> livres = {VH_Les_Miserables,VH_Les_Contemplations,VH_Notre_Dame_de_Paris,VH_Poemes_de_Victor_Hugo,EZ_Germinal,EZ_Nana,EZ_J_accuse};
	
	Bibliotheque BU(livres,auteurs,lecteurs);
	BU.add_livre(AC_L_etranger);

	Date date_emprunt1(7,7,2022);
	BU.emprunter(date_emprunt1,VH_Les_Miserables,l1);
	
	Date date_emprunt3(7,7,2022);
	BU.emprunter(date_emprunt3,EZ_Germinal,l1);
	std::cout << l1;
	Date date_emprunt4(9,7,2022);
	BU.emprunter(date_emprunt4,EZ_Germinal,l2);
	Date date_restitution3(15,7,2022);
	BU.restituer(date_restitution3,EZ_Germinal,l1);
	
	Date date_restitution1(7,8,2022);
	BU.restituer(date_restitution1,VH_Les_Miserables,l1);

	Date date_emprunt2(8,8,2022);
	BU.emprunter(date_emprunt2,VH_Les_Miserables,l2);
	
	Date date_restitution2(12,8,2022);
	BU.restituer(date_restitution2,VH_Les_Miserables,l1);	
	
	std::cout << l1;
	std::cout << VH_Les_Miserables;

	BU.chercherLivresAvecAuteur(VH);


	return 0;
}