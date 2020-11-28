/*************************************************************************
                           Trajet  -  description
                             -------------------
    début                : $17/11/2020$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Trajet> (fichier Trajet.h) ----------------
#if ! defined ( TRAJET_H )
#define TRAJET_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Trajet>
//
//
//------------------------------------------------------------------------

class Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual char * GetMoyenTransport ( ){};
    virtual char * GetVilleDepart ( ){};
    virtual char * GetVilleArrivee ( ){};

    virtual void AfficheTrajet ( ) const = 0;
    // Mode d'emploi :
    // La méthode AfficheTrajet appelle la méthode AfficheTrajet des classes
    // descendantes.
    // Contrat : 
    //


//------------------------------------------------- Surcharge d'opérateurs
    //Trajet & operator = ( const Trajet & unTrajet );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    //Trajet ( const Trajet & unTrajet );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Trajet ( ){}
    // Mode d'emploi :
    // Le constructeur de Trajet initialise un trajet contenant la ville 
    // de départ et la ville d'arrivée.
    // Contrat :
    //

    virtual ~Trajet ( ){}
    // Mode d'emploi :
    // 
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Xxx>

#endif // TRAJET_H

