/*************************************************************************
                           Xxx  -  description
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
//----------------------------------------------------- Méthodes protected
bool ListeChainee::isEmpty()
{
	if(firstElem == nullptr)
	{
		return true;
	}

	return false;
}
//----------------------------------------------------- Méthodes publiques
ElemTrajet * ListeChainee::GetFirstElem()
{
	return firstElem;
}

void ListeChainee::AfficheListe() const 
// Algorithme : parcours la liste avec un pointeur et affiche le trajet
{
	ElemTrajet * tmp;
	tmp = firstElem;
	while(tmp != lastElem)
	{
		tmp -> GetTraj() -> AfficheTrajet();
		tmp = tmp -> GetNext();
	} 
	lastElem -> GetTraj() -> AfficheTrajet();
}

void ListeChainee::AjouterTrajet(Trajet * unTrajet)
//Algorithme : On créé un nouvel élement, on fait pointer le suivant du dernier élément sur ce nouvel élément
//ce qui raccorde la chaine puis on fait pointer le dernier élément sur ce nouvel élément.
{
	if(isEmpty())
	{
		firstElem = new ElemTrajet(unTrajet);
		lastElem = firstElem;
	} else {
		ElemTrajet *elem;
		elem = new ElemTrajet(unTrajet);
		lastElem -> SetNext(elem); 
		lastElem = elem;
	}
}


//------------------------------------------------- Surcharge d'opérateurs
ListeChainee & ListeChainee::operator = ( const ListeChainee & uneListechainee)
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
ListeChainee::ListeChainee ( const ListeChainee & uneListeChainee )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Xxx>" << endl;
#endif
} //----- Fin de Xxx (constructeur de copie)


ListeChainee::ListeChainee ()
// Algorithme :
//
{
	firstElem = nullptr;
	lastElem  = nullptr;
#ifdef MAP
    cout << "Appel au constructeur de <ListeChainee>" << endl;
#endif
} //----- Fin de ListeChainee


ListeChainee::~ListeChainee ( )
//
//
{
	if(firstElem !=nullptr)
	{
		delete firstElem;
		delete lastElem;
	}

#ifdef MAP
    cout << "Appel au destructeur de <ListeChainee>" << endl;
#endif
} //----- Fin de ~ListeChainee

