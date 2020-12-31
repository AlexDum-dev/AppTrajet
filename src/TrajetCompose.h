/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <TrajetCompose> (fichier TrajetCompose.h) ----------------
#if ! defined ( TRAJETCOMPOSE_H )
#define TRAJETCOMPOSE_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
#include "TrajetSimple.h"
#include "ListeChainee.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajetCompose>
// La classe TrajetCompose permet de créer des objets constitués de plusieurs
// trajets, simples ou composés. TrajetCompose hérite de Trajet et peut donc
// être manipulé de la même façon que TrajetSimple avec un pointeur de 
// Trajet.
//
//------------------------------------------------------------------------

class TrajetCompose : public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

   void WriteInto ( std::ofstream & flux );
   
   char GetType ( );

   ListeChainee * GetListeTraj ( );
    
   char * GetVilleDepart ( );
   // Mode d'emploi : 
   // Cette méthode permet d'avoir accès à l'attribut villeDepart 
   // de TrajetCompose.
   // Contrat : 
   // Aucun contrat.

   char * GetVilleArrivee ( );
   // Mode d'emploi : 
   // Cette méthode permet d'avoir accès à l'attribut villeArrivee 
   // de TrajetCompose.
   // Contrat : 
   // Aucun contrat.
    
   void AfficheTrajet ( ) const;
   // Mode d'emploi : 
   // Affiche le trajet dans sa globalité, à savoir chaque sous-trajet
   // composant l'objet invoquant la méthode.
   // Contrat :
   // Aucun contrat.

   void AjouteTrajet ( Trajet * unTrajet );
   // Mode d'emploi : 
   // La méthode AjouteTrajet permet d'ajouter un sous-trajet au 
   // TrajetCompose invoquant la méthode. Formellement, la listeTrajets
   // va contenir en fin de liste un pointeur de Trajet pointant sur 
   // la même zone pointée par le pointeur passé en paramètre.
   // Contrat :
   // Aucun contrat.


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

    TrajetCompose ( );
    // Mode d'emploi :
    // Instancie un TrajetCompose vide.
    // Contrat :
    // Aucun contrat.

    virtual ~TrajetCompose ( );
    // Mode d'emploi :
    // Détruit l'objet invoquant la méthode.
    // Contrat :
    // Aucun contrat.

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

    char * villeDepart;
    char * villeArrivee;
    ListeChainee * listeTrajets;

};

//-------------------------------- Autres définitions dépendantes de <TrajetCompose>

#endif // TRAJETCOMPOSE_H

