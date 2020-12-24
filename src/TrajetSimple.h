/**********************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <TrajetSimple> (fichier TrajetSimple.h) ----------------
#if ! defined ( TRAJETSIMPLE_H )
#define TRAJETSIMPLE_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe TrajetSimple
// La classe TrajetSimple hérite de la classe Trajet. 
// Un TrajetSimple possède une ville de départ, une ville d'arrivée et un moyen de transport
// sous forme de chaîne de caractère.
//------------------------------------------------------------------------

class TrajetSimple : public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    
    char GetType();
    
    void AfficheTrajet ( ) const;
    // Mode d'emploi :
    // La méthode AfficheTrajet affiche le Trajet. Elle ne doit en aucun cas servir à modifier 
    // le trajet, d'où le "const".
    // Contrat : 
    // Aucun contrat.

	char * GetMoyenTransport ( );
    // Mode d'emploi :
    // La méthode GetMoyenTransport renvoie le moyen de transport utilisé pour ce trajet.
    // Contrat : 
    // Aucun contrat.

	char * GetVilleDepart ( );
    // Mode d'emploi :
    // La méthode GetVilleDepart renvoie la ville de départ du trajet.
    // Contrat : 
    // Aucun contrat.

	char * GetVilleArrivee ( );
    // Mode d'emploi :
    // La méthode GetMoyenTransport renvoie la ville d'arrivée du trajet.
    // Contrat : 
    // Aucun contrat.

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

    TrajetSimple (const char * villeD, const char * villeA, const char * moyDeT );
    // Mode d'emploi : 
    // Initialise un trajet avec une ville de départ, une ville d'arrivée et un moyen de transport
    // passé en paramètre
    // Contrat :
    // Aucun contrat.

    virtual ~TrajetSimple ( );
    // Mode d'emploi : 
    // Détruit le TrajetSimple invoquant la méthode en supprimant la 
    // mémoire allouée.
    // Contrat :
    // Aucun contrat.

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    char *villeDepart;
    char *villeArrivee;
    char *moyDeTransport;

};
//-------------------------------- Autres définitions dépendantes de <Trajet>

#endif // TRAJETSIMPLE_H

