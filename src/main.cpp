#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include "TrajetSimple.h"
#include "Trajet.h"
#include "ListeChainee.h"
#include "ElemTrajet.h"
#include "TrajetCompose.h"
#include "Catalogue.h"
using namespace std;


void ecran ( )
{
	cout << "'a' pour ajouter un trajet" << endl;
	cout << "'c' pour afficher le catalogue" << endl;
	cout << "'r' pour rechercher un trajet" << endl;
	cout << "'x' pour faire une recherche avancée" << endl;
	cout << "'l' pour faire une lecture depuis un fichier" << endl;
	cout << "'s' pour sauvegarder le catalogue dans un fichier" << endl;
	cout << "'q' pour quitter" << endl;
}

int main()
{
	/*
	Catalogue cata;
	string nomFichier = "bdd.txt";
	cata.Lecture(nomFichier);
	cata.AfficheCatalogue();
	string s = "test.txt";
	cata.Ecriture(s);
	cata.Lecture(s);
	cout << "on ouvre le catalogue en sortie qui s'ajoute au précédent:" << endl;
	cata.AfficheCatalogue();
	//char type = 'C';
	//cata.Lecture(nomFichier, type);

	//string nomFichier2("bdd2.txt");
	//ata.Ecriture(nomFichier2);
	*/

	
	//Menu
	
	char commande = 'c';
	Catalogue * catalogue = new Catalogue();
	while(commande != 'q') //comment q pour quitter
	{
		ecran();
        cin >> commande;
		char * vd;
		char * va;
		char * mdt;
		char car[100];
		string nomFichier;
		string dep = "";
		string arr = "";
        switch(commande)
		{
            case 'a': //Ajouter un trajet
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
            case 'c': //Affiche tous les trajets

				cout << "Voici le catalogue des trajets :" << endl;
                catalogue -> AfficheCatalogue();
				cout << endl;

                break;
			case 'r': //Recherche simple sur les trajets déjà présents dans le catalogue

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
			case 'x': //Recherche avanée : combine les trajets composés et les trajets simples pour effectuer la recherche 
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

				catalogue -> RechercheAvancee(vd,va);

				delete[] vd;
				delete[] va;
			
				break;
	    	case 'l':
			
				cout << "Veuillez entrez le nom du fichier depuis lequel vous voulez charger les trajets : ";
				cin >> nomFichier;
				
				char critereLec;
				cout << "Veuillez faire un choix :" << endl;

				cout << " - '1' pour sélectionner tous les trajets sans exception" << endl;
				cout << " - '2' pour sélectionner seulement un type de trajet" << endl;
				cout << " - '3' pour sélectionner des trajets selon leur ville de départ et/ou d'arrivée" << endl;
				cout << "Votre choix : ";
				cin >> critereLec;
			

				switch(critereLec)
				{
					case '1':
						catalogue->Lecture(nomFichier);
						break;
					case '2':
						cout << "Veuillez entrer '1' pour sélectionner uniquement les trajets simples" << endl;
						cout << "Veuillez entrer '2' pour sélectionner uniquement les trajets composés" << endl;
						char choixLec;
						cin >> choixLec;

						switch(choixLec)
						{
							case '1':
								catalogue->Lecture(nomFichier, 'S');
								break;
							case '2':
								catalogue->Lecture(nomFichier, 'C');
								break;
							default:
								cout << "Erreur sur la saisie" << endl;
								break;
						}

						break;

					case '3':
						dep = "";
						arr = "";
						char specLec;
						cout << "Souhaitez-vous spécifier une ville de départ ? 'o' oui / 'n' non : ";
						cin >> specLec;

						switch(specLec)
						{
							case 'o':
								cout << "Veuillez saisir la ville de départ : ";
								cin >> dep;
								break;
							case 'n':
								break;
							default:
								cout << "Erreur sur la saisie" << endl;
								break;
						}

						cout << "Souhaitez-vous spécifier une ville d'arrivée ? 'o' oui / 'n' non : ";
						cin >> specLec;

						switch(specLec)
						{
							case 'o':
								cout << "Veuillez saisir la ville d'arrivée : ";
								cin >> arr;
								break;
							case 'n':
								break;
							default:
								cout << "Erreur sur la saisie" << endl;
								break;
						}

						catalogue->Lecture(nomFichier, dep, arr);

						break;

					default:
						cout << "Erreur sur la saisie" << endl;
						break;
				}
				
				cout << "La lecture a bien été prise en compte." << endl << endl;
			
				break;

			case 's':

				cout << "Veuillez entrez le nom du fichier dans lequel vous souhaitez sauvegarder le catalogue actuel : ";
				cin >> nomFichier;
				
				char critereSauv;
				cout << "Veuillez faire un choix :" << endl; 

				cout << " - '1' pour sauvegarder tous les trajets sans exception" << endl;
				cout << " - '2' pour sauvegarder seulement un type de trajet" << endl;
				cout << " - '3' pour sauvegarder des trajets selon leur ville de départ et/ou d'arrivée" << endl;
				cout << "Votre choix : ";
				cin >> critereSauv;
			

				switch(critereSauv)
				{
					case '1':
						catalogue->Ecriture(nomFichier);
						break;
					case '2':
						cout << "Veuillez entrer '1' pour sauvegarder uniquement les trajets simples" << endl;
						cout << "Veuillez entrer '2' pour sauvegarder uniquement les trajets composés" << endl;
						char choixSauv;
						cin >> choixSauv;

						switch(choixSauv)
						{
							case '1':
								catalogue->Ecriture(nomFichier, 'S');
								break;
							case '2':
								catalogue->Ecriture(nomFichier, 'C');
								break;
							default:
								cout << "Erreur sur la saisie" << endl;
								break;
						}

						break;

					case '3':
						dep = "";
						arr = "";
						char specSauv;
						cout << "Souhaitez-vous spécifier une ville de départ ? 'o' oui / 'n' non : ";
						cin >> specSauv;

						switch(specSauv)
						{
							case 'o':
								cout << "Veuillez saisir la ville de départ : ";
								cin >> dep;
								break;
							case 'n':
								break;
							default:
								cout << "Erreur sur la saisie" << endl;
								break;
						}

						cout << "Souhaitez-vous spécifier une ville d'arrivée ? 'o' oui / 'n' non : ";
						cin >> specSauv;

						switch(specSauv)
						{
							case 'o':
								cout << "Veuillez saisir la ville d'arrivée : ";
								cin >> arr;
								break;
							case 'n':
								break;
							default:
								cout << "Erreur sur la saisie" << endl;
								break;
						}

						catalogue->Ecriture(nomFichier, dep, arr);

						break;

					default:
						cout << "Erreur sur la saisie" << endl;
						break;
				}
				
				cout << "Le catalogue a bien été sauvegardé." << endl << endl;
			
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
