/*************************************************************************
                           Xxx  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Xxx> (fichier Xxx.cpp) ------------

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
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Xxx::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
//

void Catalogue::RechercheAvancee(const char * Depart, const char * arrivee)
//Algorithme  : 
{
	ElemTrajet * tmp;
	tmp = listeTrajets -> GetFirstElem();

	while(tmp != nullptr)
	{
		if(strcmp(tmp -> GetTraj() -> GetVilleDepart(), Depart)==0)
		{
			ListeChainee * listeCheminsPossibles = new ListeChainee();
			listeCheminsPossibles -> AjouterTrajet(tmp -> GetTraj());
			DFS(listeCheminsPossibles, arrivee, tmp -> GetTraj() -> GetVilleArrivee());
			//delete listeCheminsPossibles;
		}
		
		tmp = tmp -> GetNext();
	}
}

void Catalogue::DFS(ListeChainee * listeChemins, const char * dest, const char * noeudAct)
{
	ElemTrajet  *tmp;
	tmp = listeTrajets -> GetFirstElem();
	
	while(tmp != nullptr)
	{
		if(strcmp(tmp -> GetTraj() -> GetVilleDepart(), noeudAct)==0)
		{
			//if pour le cas : on revient sur nos pas et on ne veut pas refaire le trajet déjà fait : 
			while(!listeChemins -> isEmpty()  && strcmp(listeChemins -> GetLastElem() -> GetTraj() -> GetVilleArrivee(), tmp -> GetTraj()-> GetVilleDepart())!=0)
			{
				listeChemins -> RetireLastElem();
			}

			listeChemins -> AjouterTrajet(tmp -> GetTraj());
			
			// Si on est arrivés a destination, on retire et  l'algo continue sinon on relance la recherche récursive à partir du noeud suivant 
			//
			if(strcmp(tmp -> GetTraj() -> GetVilleArrivee(), dest)==0)
			{
				listeChemins -> AfficheListe();
				listeChemins -> RetireLastElem();
				//DFS(listeChemins, dest, tmp -> GetTrajet() -> GetDepart());
			}
		       	else 
			{
				DFS(listeChemins, dest, tmp -> GetTraj() -> GetVilleArrivee());
			}
		}

		tmp = tmp -> GetNext();

	}
}

void Catalogue::RechercheTrajet(char * vd, char *va) const
//Algorithme :
{
        ElemTrajet *tmp;
        tmp = listeTrajets -> GetFirstElem();
        char * Ctmp;
        char * Ctmp2;
        bool equalArrivee;
        bool equalDepart;
        unsigned int i;
        while(tmp != nullptr)
        {
                equalArrivee = true;
                equalDepart = true;
                Ctmp = tmp -> GetTraj() -> GetVilleDepart();
                Ctmp2 = tmp -> GetTraj() -> GetVilleArrivee();
                i=0;
                while(i!=strlen(Ctmp) or i != strlen(vd))
                {
                        if(Ctmp[i] != vd[i])
                        {
                                equalDepart = false;
                        }

                        if(Ctmp2[i] != va[i])
                        {
                                equalArrivee = false;
                        }

                        i++;
                }

                if(equalDepart and equalArrivee)
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

//------------------------------------------------- Surcharge d'opérateurs
//Xxx & Xxx::operator = ( const Xxx & unXxx )
// Algorithme :
//
//{
//} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
//Xxx::Xxx ( const Xxx & unXxx )
// Algorithme :
//
//{
//#ifdef MAP
//    cout << "Appel au constructeur de copie de <Xxx>" << endl;
//#endif
//} //----- Fin de Xxx (constructeur de copie)


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


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

