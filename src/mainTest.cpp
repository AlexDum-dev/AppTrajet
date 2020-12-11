#include<iostream>
#include<cstring>

#include"TrajetSimple.h"
#include"Trajet.h"
#include"ListeChainee.h"
#include"ElemTrajet.h"
#include"TrajetCompose.h"
#include"Catalogue.h"
using namespace std;

void ecran()
{
	//system("cls");
	cout << "'a' pour ajouter un trajet" << endl;
	cout << "'c' pour afficher le catalogue" << endl;
	cout << "'r' pour rechercher un trajet" << endl;
	cout << "'q' pour quitter" << endl;
}

void VilleDepart(char * vd)
{	
	cout << "Veuillez saisir la ville de départ (appuyez sur entrée pour valider): ";
	char * car = new char[40+1];
	cin >> car;
	strcpy(vd, car);
	delete[] car;
}



void VilleArrivee(char * va)
{	
	cout << "Veuillez saisir la ville d'arrivée (appuyez sur entrée pour valider): ";
	char * car = new char[40+1];
	cin >> car;
	strcpy(va, car);
	delete[] car;			
}


void MoyenDeTransport(char * mdt)
{		
	cout << "Veuillez saisir le moyen de transport (appuyez sur entrée pour valider): ";
	char * car = new char[40+1];
	cin >> car;
	strcpy(mdt, car);
	delete[] car;
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
	cout << "ok" << endl;
	while(commande != 'q')
	{
        //system("cls");
		ecran();
        cin >> commande;
		char * vd = new char[40+1];
		char * va = new char[40+1];
		char * mdt = new char[40+1];
        switch(commande)
		{
            case 'a':
				char type;
                cout << "Voulez-vous ajouter un trajet simple ou composé ?" << endl;
				cout << " - '1' pour un trajet simple " << endl;
				cout << " - '2' pour un trajet composé " << endl;
				cout << " - autre touche pour annuler " << endl;
				cin >> type;
				Trajet * unTrajet;
				switch(type)
				{
					case '1':

					//On instancie un TrajetSimple qu'on ajoutera à la fin du catalogue 	

						vd = new char[40+1];
						va = new char[40+1];
						mdt = new char[40+1];
						
						VilleDepart(vd);
						VilleArrivee(va);
						MoyenDeTransport(mdt);

						unTrajet = new TrajetSimple(vd,va,mdt);

						delete[] vd;
						delete[] va;
						delete[] mdt;
						catalogue -> AjouteTrajet(unTrajet);
						break;
					case '2':

					//On instancie un pointeur sur Trajet. On fait un premier passage comme pour le cas précédent pour initialiser le TrajetCompose avec un TrajetSimple puis on ajoute les suivants à la fin

						Trajet * trajCompose;						
						Trajet * sousTrajet;

						vd = new char[40+1];
						va = new char[40+1];
						mdt = new char[40+1];
						
						VilleDepart(vd);
						VilleArrivee(va);
						MoyenDeTransport(mdt);

						sousTrajet = new TrajetSimple(vd,va,mdt);

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
							va = new char[40+1];
							mdt = new char[40+1];
							
							VilleArrivee(va);
							MoyenDeTransport(mdt);

							sousTrajet = new TrajetSimple(vd,va,mdt);

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
				cout << endl;

                break;
			case 'r':

				//char * vd = new char[40+1]; 
				//char * va = new char[40+1];

				VilleDepart(vd);
				VilleArrivee(va);


				catalogue -> RechercheTrajet(vd,va);

				//delete[] vd;
				//delete[] va;  
				
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
