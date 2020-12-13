/*************************************************************************
                           ElemTrajet  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <ElemTrajet> (fichier ElemTrajet.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "ElemTrajet.h"
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void ElemTrajet::AfficheTrajet() const
// Algorithme :
// Affiche le trajet de l'élément invoquant la méthode AfficheTrajet
// de la classe Trajet.
//
{
	traj -> AfficheTrajet();
}//----- Fin de AfficheTrajet

void ElemTrajet::SetNext(ElemTrajet *ptrElemTrajet)
// Algorithme :
// On fait pointer l'attribut trajSuivant de l'objet invoquant la méthode
// sur l'ElemTrajet passé en paramètre.
{
	trajSuivant = ptrElemTrajet; //on fait pointer le trajet suivant sur un trajet passé en paramètre
}//----- Fin de SetNext

void ElemTrajet::SetNull()
{
	traj = nullptr;
}

ElemTrajet* ElemTrajet::GetNext()
// Algorithme :
// Renvoie l'attribut trajSuivant de l'objet invoquant la méthode.
{
	return trajSuivant;
}//----- Fin de GetNext

Trajet * ElemTrajet::GetTraj()
// Algorithme :
// Renvoie l'attribut traj de l'objet invoquant la méthode.
{
	return traj;
}//----- Fin de GetTraj

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

ElemTrajet::ElemTrajet (Trajet * unTrajet )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <ElemTrajet>" << endl;
#endif

	trajSuivant = nullptr;
	traj = unTrajet;

} //----- Fin de ElemTrajet


ElemTrajet::~ElemTrajet ( )
// Algorithme :
// Début :
	// Supprime(traj)
	// Si il y a un trajet suivant: 
	//     le détruit en faisant appel à ce destructeur;
	// Fin si
// Fin.
{
#ifdef MAP
    cout << "Appel au destructeur de <ElemTrajet>" << endl;
#endif
    
    	if(traj != nullptr)
	{
		delete traj;
	}

	if (HasNext( ))
	{
		delete trajSuivant;
	}

} //----- Fin de ~ElemTrajet


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

bool ElemTrajet::HasNext ( )
// Algorithme :
// Début :
	// Si il y a un trajet suivant :
	//     Renvoie vrai;
	// Sinon
	//     Renvoie faux;
	// Fin si
// Fin.
{
	if (trajSuivant == nullptr)
	{
		return false;
	}
	return true;
}

