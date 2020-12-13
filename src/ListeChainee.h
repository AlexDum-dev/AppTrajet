/*************************************************************************
                           ListeChainee  -  description
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
// Rôle de la classe <ListeChainee>
// La classe ListeChainee contient deux pointeurs sur ElemTrajet, un pointant 
// sur le "début" de la liste et l'autre pointant sur la "fin". Grâce à ces
// deux pointeurs, on peut manipuler une liste chaînée d'ElemTrajet.
// 
//------------------------------------------------------------------------

class ListeChainee
{
//----------------------------------------------------------------- PUBLIC
public:
//----------------------------------------------------- Méthodes publiques
	
    ElemTrajet * GetFirstElem ( ); 
    // Mode d'emploi :
    // La méthode renvoie firstElem, cela servira aux classes utilisant 
    // ListeChainee.
    // Contrat :
    // Aucun contrat.

    ElemTrajet * GetLastElem();
    //Mode d'emploi : 
    //La méthode renvoie lastElem.

    void AfficheListe ( ) const;
    // Mode d'emploi :
    // Affiche l'ensemble des trajets de la liste.
    // Contrat :
    // Aucun contrat.

    void AjouterTrajet ( Trajet * unTrajet );
    // Mode d'emploi : 
    // Permet d'ajouter à la liste le trajet passé en paramètre
    // (via un pointeur de Trajet).
    // Contrat : 
    // Aucun contrat.

    bool isEmpty();
    // Renvoie vrai si la ListeChainee est vide, faux sinon.
    
    void RetireLastElem();
    //Mode d'emploi : 
    //Permet d'enlever le dernier élement de la liste chainée.
   

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

    ListeChainee ( );
    // Mode d'emploi :
    // Construit une ListeChainee vide.
    // Contrat :
    // Aucun contrat.

    virtual ~ListeChainee ( );
    // Mode d'emploi :
    // Détruit la ListeChainee invoquant la méthode.
    // Contrat :
    // Aucun contrat.

protected:
//----------------------------------------------------- Méthodes protégées
 
//----------------------------------------------------- Attributs protégés

    ElemTrajet * firstElem;
    ElemTrajet * lastElem;
    
};

//-------------------------------- Autres définitions dépendantes de <ListeChainee>

#endif // LISTECHAINEE_H

