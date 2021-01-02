/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <TrajetCompose> (fichier TrajetCompose.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>
#include <string> 
#include <fstream>
//------------------------------------------------------ Include personnel
#include "TrajetCompose.h"
#include "ListeChainee.h"
#include "Trajet.h"
#include "ElemTrajet.h"


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void TrajetCompose::WriteInto ( ofstream & flux )
//Algorithme : on parcourt toute la liste chainée puis on écrit les caractéristiques des trajets dans un fichier passé en paramètre  : 
{
	ElemTrajet * tmp;
    tmp = listeTrajets -> GetFirstElem();
	while (tmp != nullptr)
	{
		flux << tmp->GetTraj()->GetVilleDepart();
		flux << ",";
		flux << tmp->GetTraj()->GetVilleArrivee();
		flux << ",";
		flux << tmp->GetTraj()->GetMoyenTransport();
		flux << ">";
		tmp = tmp->GetNext();								
	}
	flux << '\n';
} 

char TrajetCompose::GetType()
{
	
	return 'C';
}

char * TrajetCompose::GetVilleDepart ( )
{
	return villeDepart;
} 

char * TrajetCompose::GetVilleArrivee ( )
{
	return villeArrivee;
} //----- Fin de GetVilleArrivee

void TrajetCompose::AfficheTrajet ( ) const 
// Algorithme : 
// Début : 
// ElemTrajet * tmp;
// tmp <- pointeur sur le premier élément de listeTrajets;
// Tant que tmp != nullptr faire :
//     affiche("- ");
//     affiche le trajet de tmp;
//     tmp <- pointeur sur l'ElemTrajet suivant;
// Fin tant que
// affiche(retour à la ligne);
// Fin.
{
    ElemTrajet * tmp;
    tmp = listeTrajets -> GetFirstElem();
    while(tmp != nullptr)
    {
		cout << "- ";
        tmp -> GetTraj() -> AfficheTrajet();
        tmp = tmp -> GetNext();
    }
} //----- Fin de AfficheTrajet


void TrajetCompose::AjouteTrajet ( Trajet * unTrajet )
// Algorithme :
// paramètres : Trajet* unTrajet
// Début :
	// Si villeDepart == nullptr faire :
	//     villeDepart <- ville de départ de unTrajet;
	// Fin si
	// villeArrivee <- ville d'arrivée de unTrajet;
	// Ajouter unTrajet à listeTrajets;
// Fin.
{	
	if(villeDepart == nullptr)
	{
		villeDepart = unTrajet -> GetVilleDepart();
	}
	villeArrivee = unTrajet -> GetVilleArrivee();
	listeTrajets -> AjouterTrajet(unTrajet);
} //----- Fin de AjouteTrajet

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

TrajetCompose::TrajetCompose ( )
// Algorithme :
// allocation mémoire de listeTrajets;
// villeArrivee = nullptr;
// villeDepart = nullptr;
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetCompose>" << endl;
#endif
	listeTrajets = new ListeChainee();
	villeArrivee = nullptr;
	villeDepart = nullptr;
} //----- Fin de TrajetCompose


TrajetCompose::~TrajetCompose ( )
// Algorithme :
// détruit listeTrajets;
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetCompose>" << endl;
#endif
	delete listeTrajets;
} //----- Fin de ~TrajetCompose


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

