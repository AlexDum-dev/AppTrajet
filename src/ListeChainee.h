/*************************************************************************
                           Xxx  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <ListeChainee> (fichier ListeChainee.h) ----------------
#if ! defined ( LISTECHAINEE_H )
#define LISTECHAINEE_H

//--------------------------------------------------- Interfaces utilisées
#include "ElemTrajet.h"
#include "Trajet.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <listeChainee>
//Implémentation d'une liste chainée
//
//------------------------------------------------------------------------

class ListeChainee
{
//----------------------------------------------------------------- PUBLIC
public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    //
    //
    void AjouterTrajet(const Trajet & unTrajet);
    // Mode d'emploi : 
    // Appel de la méthode à partir d'un instance de ListeChainee en passant en paramètre un objet de type Trajet
    // Contrat : 


//------------------------------------------------- Surcharge d'opérateurs
    ListeChainee & operator = ( const ListeChainee & uneChaine );
    // Mode d'emploi :
    //
    // Contrat :
    //

//-------------------------------------------- Constructeurs - destructeur
    ListeChainee ( const ListeChainee & uneChaine );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    ListeChainee(const Trajet & unTrajet);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~ListeChainee( );
    // Mode d'emploi :
    //
    // Contrat :
    //

protected:
//----------------------------------------------------- Attributs protégés
ElemTrajet * firstElem;
ElemTrajet * lastElem;
};

//-------------------------------- Autres définitions dépendantes de <Xxx>

#endif // LISTECHAINEE_H

