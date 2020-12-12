#include<iostream>
#include<cstring>

#include"TrajetSimple.h"
#include"Trajet.h"
#include"ListeChainee.h"
#include"ElemTrajet.h"
#include"TrajetCompose.h"
#include"Catalogue.h"
using namespace std;

void ecran ( )
{
	cout << endl;
	cout << "'a' pour ajouter un trajet" << endl;
	cout << "'c' pour afficher le catalogue" << endl;
	cout << "'r' pour rechercher un trajet" << endl;
	cout << "'q' pour quitter" << endl;
}

int main()
{
	
	/*	
	// Création de deux trajets 
	char vd1[2+1] = {'P','a', '\0'};
	char va1[2+1] = {'M', 'a','\0'};
	char mt1[2+1] = {'V', 'e', '\0'};
	Trajet * traj; 
    	traj = new TrajetSimple(vd1,va1,mt1);
	//traj -> AfficheTrajet();
	
	
	//ElemTrajet * elem;
	//ElemTrajet * elem2;
	//elem2 = new ElemTrajet(traj);
	//elem = new ElemTrajet(traj);
	//elem -> SetNext(elem2);
	//delete elem;
	
	Trajet * traj2;
	traj2 = new TrajetSimple(va1, vd1, mt1);
	//traj2 -> AfficheTrajet();

		
	
	//Liste de de trajets : 
	ListeChainee * list;
	list = new ListeChainee();
	list -> AjouterTrajet(traj);
	list -> AjouterTrajet(traj2);
	list -> AfficheListe();
	delete list;
	//list.AjouterTrajet(traj);
	//list.AfficheListe();
	
	
		
	TrajetCompose * trajCompo;
	trajCompo = new TrajetCompose();
	trajCompo -> AjouteTrajet(traj);
	trajCompo -> AjouteTrajet(traj2);
	//trajCompo -> AfficheTrajet();
	
	Catalogue * catalogue;
	catalogue = new Catalogue();
	//catalogue -> AjouteTrajet(traj);
	//catalogue -> AjouteTrajet(traj2);
	//catalogue -> AjouteTrajet(trajCompo);
	catalogue -> AfficheCatalogue();
	
	delete traj;
	delete traj2;
	delete catalogue;
	delete trajCompo;

	*/

	//Menu

	char commande = 'c';
	Catalogue * catalogue = new Catalogue();
	while(commande != 'q')
	{
		ecran();
        cin >> commande;
		char * vd;
		char * va;
		char * mdt;
		char car[100];
        switch(commande)
		{
            case 'a':
				char type;
                cout << "Voulez-vous ajouter un trajet simple ou composé ?" << endl;
				cout << " - '1' pour un trajet simple " << endl;
				cout << " - '2' pour un trajet composé " << endl;
				cout << " - autre touche pour annuler " << endl;
				cin >> type;
				switch(type)
				{
					case '1':

						//On instancie un TrajetSimple qu'on ajoutera à la fin du catalogue
						Trajet * unTrajet;
						
						// Entrée de la ville de départ
						cout << "Veuillez saisir la ville de départ (appuyez sur entrée pour valider): ";
						cin >> car;
						vd = new char[strlen(car)+1]; 
						strcpy(vd, car);
						
						// Entrée de la ville d'arrivée
						cout << "Veuillez saisir la ville d'arrivée (appuyez sur entrée pour valider): ";
						cin >> car;
						va = new char[strlen(car)+1]; 
						strcpy(va, car);

						// Entrée du moyen de transport
						cout << "Veuillez saisir le moyen de transport (appuyez sur entrée pour valider): ";
						cin >> car;
						mdt = new char[strlen(car)+1]; 
						strcpy(mdt, car);

						unTrajet = new TrajetSimple(vd,va,mdt);
						catalogue -> AjouteTrajet(unTrajet);

						delete[] vd;
						delete[] va;
						delete[] mdt;
						
						break;
					case '2':

						//On instancie un pointeur sur Trajet. On fait un premier passage comme pour le cas précédent pour initialiser le TrajetCompose avec un TrajetSimple puis on ajoute les suivants à la fin

						Trajet * trajCompose;						
						Trajet * sousTrajet;
						
						// Entrée de la ville de départ
						cout << "Veuillez saisir la ville de départ (appuyez sur entrée pour valider): ";
						cin >> car;
						vd = new char[strlen(car)+1]; 
						strcpy(vd, car);
						
						// Entrée de la ville d'arrivée
						cout << "Veuillez saisir la ville d'arrivée (appuyez sur entrée pour valider): ";
						cin >> car;
						va = new char[strlen(car)+1]; 
						strcpy(va, car);

						// Entrée du moyen de transport
						cout << "Veuillez saisir le moyen de transport (appuyez sur entrée pour valider): ";
						cin >> car;
						mdt = new char[strlen(car)+1]; 
						strcpy(mdt, car);

						sousTrajet = new TrajetSimple(vd,va,mdt);

						// Copie de la ville d'arrivée de ce sous trajet dans la ville de départ pour le sous trajet suivant
						delete[] vd;
						vd = new char[strlen(va)+1];  
						strcpy(vd,va);

						delete[] va;
						delete[] mdt;

						trajCompose = new TrajetCompose();
						trajCompose -> AjouteTrajet(sousTrajet);

						cout << "Voulez vous ajouter un sous trajet à ce trajet composé ? 'o' oui, 'n' non" << endl;
						char ajout;
						bool keep;
						cin >> ajout;
						if (ajout == 'o')
						{
							keep = true;
						}else{keep = false;}

						while (keep)
						{
							cout << "Pour rappel, le ville d'arrivée était : " << vd << ". C'est donc le départ de ce sous trajet" << endl;
							
							// Entrée de la ville d'arrivée
							cout << "Veuillez saisir la ville d'arrivée (appuyez sur entrée pour valider): ";
							cin >> car;
							va = new char[strlen(car)+1]; 
							strcpy(va, car);

							// Entrée du moyen de transport
							cout << "Veuillez saisir le moyen de transport (appuyez sur entrée pour valider): ";
							cin >> car;
							mdt = new char[strlen(car)+1]; 
							strcpy(mdt, car);

							sousTrajet = new TrajetSimple(vd,va,mdt);

							// Copie de la ville d'arrivée de ce sous trajet dans la ville de départ pour le sous trajet suivant
							delete[] vd;
							vd = new char[strlen(va)+1];  
							strcpy(vd,va);
							delete[] va;
							delete[] mdt;

							trajCompose -> AjouteTrajet(sousTrajet);

							cout << "Voulez vous ajouter un sous trajet à ce trajet composé ? 'o' oui, 'n' non" << endl;
							cin >> ajout;
							if (ajout == 'o')
							{
								keep = true;
							}else{keep = false;}

						}	
						delete[] vd;

						catalogue -> AjouteTrajet(trajCompose);
						break;
					default:
						break;
				}
				
                break;
            case 'c':

				cout << "Voici le catalogue des trajets :" << endl;
                catalogue -> AfficheCatalogue();
				cout << endl;

                break;
			case 'r':

				// Entrée de la ville de départ
				cout << "Veuillez saisir la ville de départ (appuyez sur entrée pour valider): ";
				cin >> car;
				vd = new char[strlen(car)+1]; 
				strcpy(vd, car);
				
				// Entrée de la ville d'arrivée
				cout << "Veuillez saisir la ville d'arrivée (appuyez sur entrée pour valider): ";
				cin >> car;
				va = new char[strlen(car)+1]; 
				strcpy(va, car);

				catalogue -> RechercheTrajet(vd,va);

				delete[] vd;
				delete[] va;  
				
				break;
            case 'q':
                break;
			default:
				cout << "Erreur sur l'entrée: veuillez saisir un caractère valide " << endl;
				break;
        }

	
    }	
	delete catalogue;
	return 0;
}
