/*************************************************************************
                           Xxx  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Catalogue> (fichier Catalogue.h) ----------------
#if ! defined ( CATALOGUE_H )
#define CATALOGUE_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
#include "ListeChainee.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Xxx>
//
//
//------------------------------------------------------------------------

class Catalogue
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
    
    void RechercheAvancee(const char * Depart, const char * Arrivee) ;
    //Mode d'emploi : 
    //
    //Contrat :
    //

    void DFS(ListeChainee * listeChemins, const char * dest, const char * noeudAct);
    // Mode d'emploi : 
    //
    // Contrat : 
    //

    void RechercheTrajet(char * vd, char * va) const;
    //Mode d'emploi : 
    //
    //Contrat 
    //


    void AfficheCatalogue() const;
    //Mode d'emploi : 
    //
    //Contrat : 
    //
    
    void AjouteTrajet(Trajet * unTrajet);
    // Mode d'emploi : 
    //
    // Contrat : 
    //


//------------------------------------------------- Surcharge d'opérateurs
    //Xxx & operator = ( const Xxx & unXxx );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    //Xxx ( const Xxx & unXxx );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Catalogue ();
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Catalogue ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
	ListeChainee * listeTrajets;
//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Xxx>

#endif // CATALOGUE_H


