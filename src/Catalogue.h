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
//------------------------------------------------------------------------
// Rôle de la classe <Catalogue>
//Implémente une collection ordonnée de trajets (simples ou composés)
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
    
    void RechercheAvancee(const char * Depart, const char * Arrivee) const;
    //Mode d'emploi : 
    //
    //Contrat :
    //

    void DFS(ListeChainee * listeChemins, const char * dest, const char * noeudAct) const ;
    // Mode d'emploi : 
    //
    // Contrat : 
    //

    void RechercheTrajet(const char * vd, const char * va) const;
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

//-------------------------------------------- Constructeur - Destructeur
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

#endif // CATALOGUE_H


