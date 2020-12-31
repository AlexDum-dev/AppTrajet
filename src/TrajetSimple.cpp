/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <TrajetSimple> (fichier TrajetSimple.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>
#include <fstream>

//------------------------------------------------------ Include personnel
#include "TrajetSimple.h"
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void TrajetSimple::WriteInto ( ofstream & flux )
{
	flux << GetType();
	flux << GetVilleDepart();
	flux << ',';
	flux << GetVilleArrivee();
	flux << ',';
	flux << GetMoyenTransport();
	flux << '\n';
} 

char TrajetSimple::GetType()
{
	return 'S';
}

char * TrajetSimple::GetMoyenTransport ( )
// Algorithme :
// Renvoie l'attribut protégé moyDeTransport.
{
	return moyDeTransport;
}//----- Fin de GetMoyenTransport

char * TrajetSimple::GetVilleDepart ( )
// Algorithme :
// Renvoie l'attribut protégé villeDepart.
{
	return villeDepart;
}//----- Fin de GetVilleDepart

char * TrajetSimple::GetVilleArrivee ( )
// Algorithme :
// Renvoie l'attribut protégé villeArrivee.
{
	return villeArrivee;
}//----- Fin de GetVilleArrivee

void TrajetSimple::AfficheTrajet ( ) const 
// Algorithme : 
// Début :
	// Affiche("De");
	// Pour i allant de 0 à taille(villeDepart) faire :
	//     Affiche(villeDepart[i]);
	// Fin pour
	// Affiche(" à ");
	// Pour i allant de 0 à taille(villeArrivee) faire :
	//     affiche(villeArrivee[i]);
	// Fin pour
	// Affiche(" en ");
	// Pour i allant de 0 à taille(moyDeTransport) faire :
	//     affiche(moyDeTransport[i]);
	// Fin pour
// Fin
//
{
	cout << "De ";
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
	cout << " ";
}//----- Fin de AfficheTrajet

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

TrajetSimple::TrajetSimple (const char *villeD, const char *villeA, const char *moyDeT )
{
// Algortihme :
// On déclare dynamiquement les attributs avec la longueur des paramètres +1 qui est 
// lié au caractère de fin de chaîne '\0', puis on copie avec la fonction strcpy(destination, source)
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


TrajetSimple::~TrajetSimple ( void )
// Algorithme :
// On supprime la mémoire allouée à chaque chaîne de caractère.
//
{
	delete [] villeDepart;
	delete [] villeArrivee;
	delete [] moyDeTransport;
#ifdef MAP
    cout << "Appel au destructeur de TrajetSimple" << endl;
#endif
} //----- Fin de ~TrajetSimple

	
//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

