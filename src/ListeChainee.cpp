/*************************************************************************
                           ListeChainee  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <ListeChainee> (fichier ListeChainee.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "ListeChainee.h"
#include "Trajet.h"
#include "ElemTrajet.h"
#include "TrajetSimple.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

ElemTrajet * ListeChainee::GetFirstElem( )
// Algorithme : 
// Renvoie firstElem;
{
	return firstElem;
}

void ListeChainee::AfficheListe( ) const 
// Algorithme : 
// Début :
	// ElemTrajet * tmp;
	// tmp <- firstElem;
	// Tant que tmp != lastElem faire :
	//     Affiche le trajet contenu dans tmp;
	//     tmp <- (*tmp).GetNext();                   //tmp prend la valeur du pointeur sur ElemTrajet suivant dans la liste.
	// Fin tant que
	// Affiche le trajet contenu dans lastElem;
// Fin.
{
	ElemTrajet * tmp;
	tmp = firstElem;
	while(tmp != lastElem)
	{
		tmp -> GetTraj() -> AfficheTrajet();
		tmp = tmp -> GetNext();
	} 
	lastElem -> GetTraj() -> AfficheTrajet();
}//----- Fin de AfficheListe

void ListeChainee::AjouterTrajet( Trajet * unTrajet )
// Algorithme : 
// paramètres : Trajet * unTrajet
// Début :
	// Si la liste invoquant la méthode est nulle faire :
	//     création d'un pointeur sur ElemTrajet dont l'objet pointé contient le pointeur unTrajet;
	//     firstElem pointe sur l'ElemTrajet pointé;
	//     lastElem <- firstElem;                               // lastElem pointe aussi sur cet ElemTrajet
	// Sinon faire :
	//     création d'un pointeur sur ElemTrajet "elem" dont l'objet pointé contient le pointeur unTrajet;
	//     l'attribut trajSuivant de lastElem pointe sur cet ElemTrajet;
	//     lastElem pointe ensuite sur l'objet pointé par elem;
	// Fin si
// Fin.
{
	if(isEmpty())
	{
		firstElem = new ElemTrajet(unTrajet);
		lastElem = firstElem;
	} else {
		ElemTrajet * elem;
		elem = new ElemTrajet(unTrajet);
		lastElem -> SetNext(elem);
	    lastElem = elem;	
	}
}//----- Fin de AjouterTrajet

//------------------------------------------- Constructeurs - Destructeur
ListeChainee::ListeChainee ( )
// Algorithme :
// firstElem <- nullptr;
{
#ifdef MAP
    cout << "Appel au constructeur de <ListeChainee>" << endl;
#endif
	firstElem = nullptr;
} //----- Fin de ListeChainee


ListeChainee::~ListeChainee ( )
// Algorithme :
// Début:
	// Si firstElem != nullptr faire :
	//     supprimer firstElem;
	// Fin si
// Fin.
{
#ifdef MAP
    cout << "Appel au destructeur de <ListeChainee>" << endl;
#endif
	if(firstElem != nullptr)
	{
		delete firstElem;
	}
} //----- Fin de ~ListeChainee

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées


bool ListeChainee::isEmpty ( )
// Algorithme :
// Début :
	// Si firstElem == nullptr faire :
	//     renvoie vrai;
	// Sinon faire
	//     renvoie faux;
	// Fin si
// Fin.
{
	if(firstElem == nullptr)
	{
		return true;
	}
	return false;
} //----- Fin de isEmpty

