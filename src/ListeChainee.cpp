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

ElemTrajet * ListeChainee::GetFirstElem ( )
// Algorithme : 
// Renvoie firstElem;
{
	return firstElem;
} //----- Fin de GetFirstElem

ElemTrajet * ListeChainee::GetLastElem ( )
// Algorithme : 
// Renvoie un pointeur sur le dernier élément
{
	return lastElem;
} //----- Fin de GetLastElem

void ListeChainee::AfficheListe ( ) const 
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
	if(firstElem!=nullptr)
	{
	ElemTrajet * tmp;
	tmp = firstElem;
	while(tmp != lastElem)
	{
		tmp -> GetTraj() -> AfficheTrajet();
		cout << endl;
		tmp = tmp -> GetNext();
	} 
	lastElem -> GetTraj() -> AfficheTrajet();
	cout << endl;
	}
} //----- Fin de AfficheListe

void ListeChainee::AjouterTrajet ( Trajet * unTrajet )
// Algorithme : 
// paramètres : Trajet * unTrajet
// Début :
	// Si la liste invoquant la méthode est vide faire :
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
	if (isEmpty())
	{
		firstElem = new ElemTrajet(unTrajet);
		lastElem = firstElem;
	} 
	else 
	{
		ElemTrajet * elem;
		elem = new ElemTrajet(unTrajet);
		lastElem -> SetNext(elem);
	    lastElem = elem;	
	}
} //----- Fin de AjouterTrajet

void ListeChainee::RetireLastElem ( )
// Algorithme : 
// Début :
	// Si la liste invoquant la méthode n'est pas vide faire :
	//     ElemTrajet * tmp;
	//     tmp <- firstElem;
	//     Tant que tmp!=lastElem et que l'élément suivant tmp est aussi différent de lastElem faire :
	//         tmp <- élément suivant tmp;
	//     Fin tant que
	//     Si tmp==firstElem et tmp==lastElem faire :
	//         firstELem <- nullptr;
	//         lastElem -> SetNull();                // on fait pointer l'attribut traj de lastELem sur nullptr
	//         Supprime(lastElem);
	//         lastElem <- nullptr;
	//     Sinon faire :
	//         lastElem -> SetNull();
	//         Supprime(lastElem);
	//         On fait pointer l'élément suivant tmp sur nullptr;
	//         lastELem <- tmp;
	//     Fin si
// Fin.
{
	if (!isEmpty())
	{
		ElemTrajet * tmp;
		tmp = firstElem;
		while(tmp!=lastElem and tmp -> GetNext() != lastElem)
		{
			tmp = tmp -> GetNext();
		}
		
		//si c'est le dernier élement qu'on supprime : 
		if (tmp==firstElem and tmp==lastElem)
		{
			firstElem = nullptr;
			lastElem -> SetNull();
			delete lastElem;
			lastElem = nullptr;
		} 
		else 
		{
			lastElem -> SetNull();
			delete lastElem;
			ElemTrajet * tmp2;
			tmp2 = nullptr;
			tmp -> SetNext(tmp2);
			lastElem = tmp;
		}
	}
} //----- Fin de RetireLastElem

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

