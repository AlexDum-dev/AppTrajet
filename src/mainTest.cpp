#include<iostream>
#include<cstring>

#include"TrajetSimple.h"
#include"Trajet.h"
#include"ListeChainee.h"
#include"ElemTrajet.h"
using namespace std;

int main()
{
	char vd[2+1] = {'P','a', '\0'};
	char va[2+1] = {'M', 'a','\0'};
	char mt[2+1] = {'V', 'e', '\0'};
	Trajet * traj; 
       	traj = new TrajetSimple(vd,va,mt);
	traj -> AfficheTrajet();
	TrajetSimple traj2(va, vd, mt);
	traj2.AfficheTrajet();

	ElemTrajet * ET;
	ET = new ElemTrajet(traj2);
	cout << ET -> GetTraj() << endl;
	cout << &traj2 << endl;
	
	//ListeChainee list(traj2);
	

	//list.AjouterTrajet(traj2);
	//list.AfficheListe();

	return 0;
}
