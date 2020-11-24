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
#include<cstring>

//------------------------------------------------------ Include personnel
#include "TrajetSimple.h"
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Xxx::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


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


TrajetSimple::TrajetSimple (char *villeD, char *villeA, char *moyDeT)
{
// Algortihme :
// Déclaration dynamique des attributs avec la longueur des paramètres +1 qui est lié au caractère '\0'
// Puis copie avec la fonction strcpy(destination, source)
//
	villeDepart = new char[strlen(villeD)+1];
	villeArrivee = new char[strlen(villeA)+1];
	moyDeTransport = new char[strlen(moyDeT)+1];
	
	strcpy(villeDepart, villeD);
	strcpy(villeArrivee, villeA);
	strcpy(moyDeTransport, moyDeT);
#ifdef MAP
    cout << "Appel au constructeur de TrajetSimple" << endl;
#endif
} //----- Fin de TrajetSimple


TrajetSimple::~TrajetSimple (void)
// Algorithme :
//
{
	delete [] villeDepart;
	delete [] villeArrivee;
	delete [] moyDeTransport;
#ifdef MAP
    cout << "Appel au destructeur de TrajetSimple" << endl;
#endif
} //----- Fin de ~TrajetSimple

void TrajetSimple::AfficheTrajet() const 
//Algorithme : test
//
{
	cout << "de ";
	for(unsigned int i=0;i<strlen(villeDepart);i++)
	{
		cout << villeDepart[i];
	}
	cout << " à ";
	for(unsigned int j=0;j<strlen(villeArrivee);j++)
        {
                cout << villeArrivee[j]; 
        }
	cout << " en ";
	for(unsigned int k=0;k<strlen(moyDeTransport);k++)
        {
                cout << moyDeTransport[k];
        }
	cout << endl;
}

	
//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

