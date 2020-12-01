#include<iostream>
#include<cstring>

#include"TrajetSimple.h"
#include"Trajet.h"
#include"ListeChainee.h"
#include"ElemTrajet.h"
#include"TrajetCompose.h"
using namespace std;

int main()
{
	// Création de deux trajets 
	char vd[2+1] = {'P','a', '\0'};
	char va[2+1] = {'M', 'a','\0'};
	char mt[2+1] = {'V', 'e', '\0'};
	Trajet * traj; 
       	traj = new TrajetSimple(vd,va,mt);
	//traj -> AfficheTrajet();
	
	Trajet * traj2;
	traj2 = new TrajetSimple(va, vd, mt);
	//traj2 -> AfficheTrajet();
	
	/*
	//Liste de de trajets : 
	ListeChainee list(traj);
	list.AjouterTrajet(traj2);
	list.AjouterTrajet(traj);
	list.AfficheListe();
	*/

	TrajetCompose * trajCompo;
	trajCompo = new TrajetCompose(traj);
	trajCompo -> AjouteTrajet(traj2);
	trajCompo -> AfficheTrajet();
	return 0;
}
