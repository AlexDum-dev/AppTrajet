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
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <ElemTrajet>
// ElemTrajet désigne un "maillon" d'une liste chaînée d'ElemTrajet. Un
// ElemTrajet contient un pointeur de Trajet et un pointeur sur un ElemTrajet.
//
//------------------------------------------------------------------------

class ElemTrajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    
    void SetNext ( ElemTrajet * ptrElemTrajet );
    // Mode d'emploi :
    // Permet "d'attacher" un ElemTrajet grâce à un pointeur sur cet objet
    // à l'objet invoquant la méthode.
    // Contrat :
    // Aucun contrat.
	
    void SetNull ( );
    // Mode d'emploi : 
    // Permet de mettre à nullptr le pointeur de trajet
    // Contrat :
    // Pour utiliser cette méthode, il faut être dans l'un des cas suivants :
    // - soit l'attibut traj de l'objet invoquant la méthode n'a pas été
    // initialisé (utilisation d'un constructeur par défaut).
    // - soit il existe un autre ElemTrajet qui contient un pointeur de 
    // Trajet qui pointe sur l'attribut traj de l'objet invoquant la méthode.
    // Si ce n'est pas le cas, lors de la destruction des objets, le 
    // TrajetSimple ou TrajetCompose initialement pointé par l'objet 
    // invoquant la méthode ne sera jamais supprimé en mémoire.

    ElemTrajet * GetNext ( );
    // Mode d'emploi :
    // Renvoie l'ElemTrajet suivant via un pointeur d'ElemTrajet. 
    // Contrat :
    // Aucun contrat.

    Trajet * GetTraj ( );
    // Mode d'emploi :
    // Renvoie le pointeur sur Trajet de l'objet invoquant la méthode.
    // Contrat :
    // Aucun contrat.
    
    void AfficheTrajet ( ) const;
    // Mode d'emploi :
    // Permet d'afficher le trajet contenu dans l'objet invoquant la méthode.
    // Contrat :
    // Aucun contrat.
		
//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

    ElemTrajet ( Trajet * unTrajet );
    // Mode d'emploi :
    // Permet de construire un ElemTrajet qui contient le trajet passé en paramètre.
    // Contrat :
    // Aucun contrat.

    ElemTrajet ( ){};
    // Mode d'emploi :
    // Il s'agit d'un constructeur par défaut. Il permet d'instancier un ElemTrajet
    // non initialisé.
    // Contrat :
    // Aucun contrat.

    virtual ~ElemTrajet ( );
    // Mode d'emploi :
    // Détruit l'objet invoquant la méthode.
    // Contrat :
    // Aucun contrat.

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

	bool HasNext ( ); 
    //Renvoie vrai si il y a un trajet suivant, faux sinon.

//----------------------------------------------------- Attributs protégés

	Trajet * traj;
	ElemTrajet * trajSuivant;

};

//-------------------------------- Autres définitions dépendantes de <ElemTrajet>

#endif // ELEMTRAJET_H
