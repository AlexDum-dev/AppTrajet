/*************************************************************************
                           Xxx  -  description
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
//------------------------------------------------------ Include personnel
#include "TrajetCompose.h"
#include "ListeChainee.h"
#include "Trajet.h"
#include "ElemTrajet.h"


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Xxx::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
//

char * TrajetCompose::GetVilleDepart()
{
	return villeDepart;
}

char * TrajetCompose::GetVilleArrivee()
{
	return villeArrivee;
}

void TrajetCompose::AfficheTrajet() const 
//Algorithme : 
{
	//listeTrajets -> AfficheListe();
	ElemTrajet * tmp;
        tmp = listeTrajets -> GetFirstElem();
        while(tmp != nullptr)
        {
		cout << "- ";
                tmp -> GetTraj() -> AfficheTrajet();
                tmp = tmp -> GetNext();
        }
        //lastElem -> GetTraj() -> AfficheTrajet();
	cout << endl;
}


void TrajetCompose::AjouteTrajet(Trajet * unTrajet)
// Algorithme
{	
	if(villeDepart == nullptr)
	{
		villeDepart = new char[40+1];
		strcpy(villeDepart,unTrajet -> GetVilleDepart());

	}
	strcpy(villeArrivee, unTrajet -> GetVilleArrivee());
	listeTrajets -> AjouterTrajet(unTrajet);
}




//------------------------------------------------- Surcharge d'opérateurs
//Xxx & Xxx::operator = ( const Xxx & unXxx )
// Algorithme :z
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


TrajetCompose::TrajetCompose()
// Algorithme :
//
{
	listeTrajets = new ListeChainee();
	villeArrivee = new char[40+1];
	villeDepart = nullptr;
#ifdef MAP
    cout << "Appel au constructeur de <TrajetCompose>" << endl;
#endif
} //----- Fin de TrajetCompose


TrajetCompose::~TrajetCompose ( )
// Algorithme :
//
{
	delete listeTrajets;
	delete [] villeArrivee;
	delete [] villeDepart;
#ifdef MAP
    cout << "Appel au destructeur de <TrajetCompose>" << endl;
#endif
} //----- Fin de ~TrajetCompose


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

