/*************************************************************************
                           ElemTrajet  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <ElemTrajet> (fichier ElemTrajet.h) ----------------
#if ! defined ( ELEMTRAJET_H )
#define ELEMTRAJET_H

//--------------------------------------------------- Interfaces utilisées
#include"Trajet.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <ElemTrajet>
//
//
//------------------------------------------------------------------------

class ElemTrajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

	void Enchaine ( const ElemTrajet & * unElemTrajet ) 
	{
		trajSuivant = unElemTrajet;
	}
	
//------------------------------------------------- Surcharge d'opérateurs
    ElemTrajet & operator = ( const ElemTrajet & unElemTrajet );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    ElemTrajet ( const ElemTrajet & unElemTrajet );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    ElemTrajet ( const Trajet & trajet )
	{
		traj = trajet;
		trajSuivant = new ElemTrajet;
		trajSuivant = nullptr;
	}
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~ElemTrajet ( )
	{
		delete trajSuivant;
	}
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

Trajet traj;
ElemTrajet * trajSuivant;

};

//-------------------------------- Autres définitions dépendantes de <Xxx>

#endif // XXX_H
