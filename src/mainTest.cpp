#include<iostream>
#include<cstring>

#include"TrajetSimple.h"
#include"Trajet.h"

using namespace std;

int main()
{
	char vd[1];
	vd[0] = 'P';
	char va[1];
	va[0] = 'L';
	char mt[1];
	mt[0] = 'T';
	TrajetSimple traj (vd, va, mt);
	traj.AfficheTrajet();

	return 0;
}
