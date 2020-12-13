/*************************************************************************
                           Xxx  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>
//------------------------------------------------------ Include personnel
#include "Catalogue.h"
#include "Trajet.h"
#include "ListeChainee.h"
#include "ElemTrajet.h"
#include "TrajetSimple.h"
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques


void Catalogue::RechercheAvancee(const char * Depart, const char * arrivee) const
//Algorithme  : 
{
	ElemTrajet * tmp;
	tmp = listeTrajets -> GetFirstElem();
	

	RechercheTrajet(Depart, arrivee); //Affiche les trajets trouvés par la méthode simple

	while(tmp != nullptr) //On parcourt tout le catalogue
	{
		if(strcmp(tmp -> GetTraj() -> GetVilleDepart(), Depart)==0) //si on trouve une ville de départ d'un trajet qui est la ville de départ recherchée par l'utilisateur
		{
			ListeChainee * listeCheminsPossibles = new ListeChainee();
			listeCheminsPossibles -> AjouterTrajet(tmp -> GetTraj());
			DFS(listeCheminsPossibles, arrivee, tmp -> GetTraj() -> GetVilleArrivee()); //Recherche des combinaisons possibles à partir d'un point de départ
			
			while(listeCheminsPossibles -> GetFirstElem() != nullptr) //Retire tous les élements de la liste temporaire
			{
				listeCheminsPossibles -> RetireLastElem();
			}
			delete listeCheminsPossibles;
		}
		
		tmp = tmp -> GetNext();
	}
}

void Catalogue::DFS(ListeChainee * listeChemins, const char * dest, const char * noeudAct) const
//Algorithme : Fonction récursive qui remplit la listeChemins au fur et à mesure. On part en faisant un trajet avec la ville de départ correspondant au départ recherché par l'utilisateur.
//A partir de l'arrivée de ce trajet: si cette arrivée est la destination voulue par l'utilisateur on s'arrête, on affiche tous le chemins fait pour on revient sur nos pas jusqu'à trouver un autre chemin possible.
//Si l'arrivée n'est pas la destination alors on relance la recherche (fonction récursive) à partir de cette arrivée. 

{
	ElemTrajet  *tmp;
	tmp = listeTrajets -> GetFirstElem();
	
	while(tmp != nullptr)
	{
		if(strcmp(tmp -> GetTraj() -> GetVilleDepart(), noeudAct)==0)
		{
			// Permet de on revient sur nos pas et on ne veut pas refaire le trajet déjà fait : 
			while(!listeChemins -> isEmpty()  && strcmp(listeChemins -> GetLastElem() -> GetTraj() -> GetVilleArrivee(), tmp -> GetTraj()-> GetVilleDepart())!=0)
			{
				listeChemins -> RetireLastElem();
			}


			listeChemins -> AjouterTrajet(tmp -> GetTraj()); //On avance d'un trajet 
			
			// Si on est arrivés a destination, on retire et  l'algo continue sinon on relance la recherche récursive à partir du noeud suivant 
			if(strcmp(tmp -> GetTraj() -> GetVilleArrivee(), dest)==0)
			{
				listeChemins -> AfficheListe();
				listeChemins -> RetireLastElem();
			}
		       	else
			{
				DFS(listeChemins, dest, tmp -> GetTraj() -> GetVilleArrivee());
			}
		}

		tmp = tmp -> GetNext();

	}
}

void Catalogue::RechercheTrajet(const char * vd, const char *va) const
//Algorithme : On recherche les trajets pour lesquels la ville de départ et la ville d'arrivée sont égales aux données de l'utilisateur
{
        ElemTrajet *tmp;
        tmp = listeTrajets -> GetFirstElem();
        char * Ctmp;
        char * Ctmp2;
        while(tmp != nullptr)
        {
                Ctmp = tmp -> GetTraj() -> GetVilleDepart();
                Ctmp2 = tmp -> GetTraj() -> GetVilleArrivee();


		if(strcmp(Ctmp, vd)==0 and strcmp(Ctmp2, va)==0)
		{
			tmp -> AfficheTrajet();
			cout << endl;
		}

		
                tmp = tmp -> GetNext();

        }

}


void Catalogue::AjouteTrajet(Trajet * unTrajet)
//Algorithme :
{
	listeTrajets -> AjouterTrajet(unTrajet);
}

void Catalogue::AfficheCatalogue() const
//Algorithme
{
        ElemTrajet * tmp;
        tmp = listeTrajets -> GetFirstElem();
        while(tmp != nullptr)
        {       
                tmp -> GetTraj() -> AfficheTrajet();
                tmp = tmp -> GetNext();
                cout << endl;
        }
}

Catalogue::Catalogue ()
// Algorithme :
//
{
	listeTrajets = new ListeChainee();
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif
} //----- Fin de Catalogue


Catalogue::~Catalogue ( )
// Algorithme :
//
{
	delete listeTrajets;
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif
} //----- Fin de ~Catalogue

