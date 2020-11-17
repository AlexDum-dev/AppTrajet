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
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
//Xxx::Xxx ( const Xxx & unXxx )
// Algorithme :
//
//{
//#ifdef MAP
//    cout << "Appel au constructeur de copie de <Xxx>" << endl;
//#endif
//} //----- Fin de Xxx (constructeur de copie)


TrajetSimple::TrajetSimple (char * villeD, char *villeA, char *moyDeT)
{
// Algortihme :
// Déclaration dynamique des attributs avec la longueur des paramètres +1 qui est lié au caractère '\0'
// Puis copie avec la fonction strcpy(destination, source)
//
	char * villeDepart = new char[strlen(villeD)+1];
	char * villeArrivee = new char[strlen(villeA)+1];
	char * moyDeTransport = new char[strlen(moyDeT)+1];
	
	strcpy(villeDepart, villeD);
	strcpy(villeArrivee, villeA);
	strcpy(moyDeTransport, moyDeT);
#ifdef MAP
    cout << "Appel au constructeur de TrajetSimple" << endl;
#endif
} //----- Fin de TrajetSimple


TrajetSimple::~TrajetSimple ( )
// Algorithme :
//
{
	delete[] villeDepart;
	delete[] villeArrivee;
	delete[] moyDeTransport;
#ifdef MAP
    cout << "Appel au destructeur de TrajetSimple" << endl;
#endif
} //----- Fin de ~TrajetSimple

TrajetSImple::AfficheTrajet()
//Algorithme :
//
{
	cout << "de ";
	for(int i=0;i<strlen(villeDepart);i++)
	{
		cout << villeDepart[i]
	}
	cout << " à ";
	for(int j=0;i<strlen(villeArrivee);i++)
        {
                cout << villeArrivee[j] 
        }
	cout << " en ";
	for(int k=0;i<strlen(moyDeTransport);i++)
        {
                cout << moyDeTransport[k]
        }
	cout << endl;
}

	
//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

