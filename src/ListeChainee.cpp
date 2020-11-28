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
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void ListeChainee::AjouterTrajet(const Trajet & unTrajet)
//Algorithme : On créé un nouvel élement, on fait pointer le suivant du dernier élément sur ce nouvel élément
//ce qui raccorde la chaine puis on fait pointer le dernier élément sur ce nouvel élément.
{
	ElemTrajet *elem;
	elem = new ElemTrajet(unTrajet);
	elem = lastElem -> GetNext();
	lastElem = elem;
	delete elem;
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


ListeChainee::ListeChainee (const Trajet  &unTrajet)
// Algorithme :
//
{
	firstElem = new ElemTrajet(unTrajet);
	lastElem = new ElemTrajet(unTrajet); // Initialisation de la liste chainee avec un seul élément qui est le premier et le dernier

	
#ifdef MAP
    cout << "Appel au constructeur de <ListeChainee>" << endl;
#endif
} //----- Fin de ListeChainee


ListeChainee::~ListeChainee ( )
// Algorithme : On crée deux pointeurs qui vont parcourir la liste chainée. Tant que le deuxième
//pointeur n'est pas égal au dernier élément de la liste on libère la mémoire alouée du pointeur précédent.
//
{	
	delete firstElem;
	delete lastElem;

#ifdef MAP
    cout << "Appel au destructeur de <ListeChainee>" << endl;
#endif
} //----- Fin de ~ListeChainee

