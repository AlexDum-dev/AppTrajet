/*************************************************************************
                           Xxx  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Xxx> (fichier Xxx.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>
//------------------------------------------------------ Include personnel
#include "Catalogue.h"
#include "Trajet.h"
#include "ListeChainee.h"
#include "ElemTrajet.h"
#include "TrajetSimple.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Xxx::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
//

void Catalogue::RechercheTrajet(char * vd, char *va) const
//Algorithme :
{
        ElemTrajet *tmp;
        tmp = listeTrajets -> GetFirstElem();
        char * Ctmp;
        char * Ctmp2;
        bool equalArrivee;
        bool equalDepart;
        unsigned int i;
        while(tmp != nullptr)
        {
                equalArrivee = true;
                equalDepart = true;
                Ctmp = tmp -> GetTraj() -> GetVilleDepart();
                Ctmp2 = tmp -> GetTraj() -> GetVilleArrivee();
                i=0;
                while(i!=strlen(Ctmp) or i != strlen(vd))
                {
                        if(Ctmp[i] != vd[i])
                        {
                                equalDepart = false;
                        }

                        if(Ctmp2[i] != va[i])
                        {
                                equalArrivee = false;
                        }

                        i++;
                }

                if(equalDepart and equalArrivee)
                {
                        tmp -> AfficheTrajet();
			cout << endl;
                }


                tmp = tmp -> GetNext();

        }

}


void Catalogue::AjouteTrajet(Trajet * unTrajet)
//Algorithme :
{
	listeTrajets -> AjouterTrajet(unTrajet);
}

void Catalogue::AfficheCatalogue() const
//Algorithme
{
        ElemTrajet * tmp;
        tmp = listeTrajets -> GetFirstElem();
        while(tmp != nullptr)
        {       
                tmp -> GetTraj() -> AfficheTrajet();
                tmp = tmp -> GetNext();
                cout << endl;
        }
}

//------------------------------------------------- Surcharge d'opérateurs
//Xxx & Xxx::operator = ( const Xxx & unXxx )
// Algorithme :
//
//{
//} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
//Xxx::Xxx ( const Xxx & unXxx )
// Algorithme :
//
//{
//#ifdef MAP
//    cout << "Appel au constructeur de copie de <Xxx>" << endl;
//#endif
//} //----- Fin de Xxx (constructeur de copie)


Catalogue::Catalogue ()
// Algorithme :
//
{
	listeTrajets = new ListeChainee();
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif
} //----- Fin de Catalogue


Catalogue::~Catalogue ( )
// Algorithme :
//
{
	delete listeTrajets;
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif
} //----- Fin de ~Catalogue


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

