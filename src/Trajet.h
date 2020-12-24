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
// La classe Trajet est abstraite. Avec un pointeur de Trajet, nous pourrons avoir
// accès à un descendant de Trajet, soit un TrajetSimple ou un TrajetCompose.
//------------------------------------------------------------------------

class Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    virtual char GetType() {return 0;};
    //Mode d'emploi : 
    //Renvoie un char caractérisant le type de trajet

    virtual char * GetMoyenTransport ( ){char * m = 0; return m;};
    // Mode d'emploi :
    // La méthode GetMoyenTransport renvoie une chaîne de caractère
    // décrivant le moyen de transport utilisé pour le trajet.
    // Contrat :
    // Aucun contrat.

    virtual char * GetVilleDepart ( ){char * m = 0; return m;};
    // Mode d'emploi :
    // La méthode GetVilleDepart renvoie une chaîne de caractère
    // décrivant la ville de départ du trajet.
    // Contrat :
    // Aucun contrat.

    virtual char * GetVilleArrivee ( ){char * m = 0; return m;};
    // Mode d'emploi :
    // La méthode GetVilleArrivee renvoie une chaîne de caractère
    // décrivant la ville d'arrivée du trajet.
    // Contrat :
    // Aucun contrat.

    virtual void AjouteTrajet ( Trajet * unTrajet ){};
    // Mode d'emploi :
    // La méthode AjouteTrajet prend en paramètre un pointeur 
    // de Trajet et l'ajoute en fin de liste. Cette méthode est 
    // notamment utile pour ses descendants (TrajetCompose par exemple).
    // Contrat :
    // Aucun contrat.

    virtual void AfficheTrajet ( ) const = 0;
    // Mode d'emploi :
    // La méthode AfficheTrajet appelle la méthode AfficheTrajet des classes
    // descendantes. Elle ne doit en aucun cas servir à modifier le Trajet,
    // d'où le "const".
    // Contrat : 
    //


//------------------------------------------------- Surcharge d'opérateurs
    //Aucune surcharge d'opérateur
//-------------------------------------------- Constructeurs - destructeur

    Trajet ( ){}
    // Mode d'emploi :
    // Le constructeur de Trajet crée un Trajet.
    // Contrat :
    // Trajet est une classe abstraite, on ne peut pas instancier de Trajet
    // mais uniquement des pointeurs de Trajet.

    virtual ~Trajet ( ){}
    // Mode d'emploi :
    // Detruit le Trajet.
    // Contrat :
    // Aucun contrat.

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Trajet>

#endif // TRAJET_H

