/*************************************************************************
                           Xxx  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <TrajetSimple> (fichier TrajetSimple.h) ----------------
#if ! defined ( TRAJETSIMPLE_H )
#define TRAJETSIMPLE_H

//--------------------------------------------------- Interfaces utilisées
#include <Trajet.h>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe TrajetSimple
//Hérite de la classe trajet 
//Possède une ville de départ, une ville d'arrivée et un moyen de transport
//------------------------------------------------------------------------

class TrajetSimple : public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void AfficheTrajet() const;
    //Mode d'emploi : 
    //Print sur l'entrée standard la ville de départ et d'arrivée ainsi que le moyen de transport
    //Contrat : 
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

    TrajetSimple(char * villeD, char * villeA, char * moyDeT);
    // Mode d'emploi : 
    // Initialise un trajet avec une ville de départ, une ville d'arrivée et un moyen de transport
    // Contrat :
    //

    virtual ~TrajetSimple( );

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

