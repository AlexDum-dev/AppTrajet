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
// type Xxx::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
//

ElemTrajet* ElemTrajet::GetNext()
{
	return trajSuivant;
}
//------------------------------------------------- Surcharge d'opérateurs
/*
Xxx & Xxx::operator = ( const Xxx & unXxx )
// Algorithme :
//
{
} //----- Fin de operator =
*/

//-------------------------------------------- Constructeurs - destructeur
ElemTrajet::ElemTrajet ( const ElemTrajet & unElemTrajet )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <ElemTrajet>" << endl;
#endif

} //----- Fin de Xxx (constructeur de copie)


ElemTrajet::ElemTrajet (const Trajet & unTrajet )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <ElemTrajet>" << endl;
#endif
	
	trajSuivant = new ElemTrajet;
	*traj = unTrajet;

} //----- Fin de ElemTrajet


ElemTrajet::~ElemTrajet ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <ElemTrajet>" << endl;
#endif

	if (HasNext( ))
	{
		delete traj;
		delete trajSuivant;
	}

} //----- Fin de ~Xxx


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

bool ElemTrajet::HasNext ( )
{
	if (trajSuivant == nullptr)
	{
		return false;
	}
	return true;
}

