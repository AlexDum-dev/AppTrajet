#include<iostream>
#include<cstring>

#include"TrajetSimple.h"
#include"Trajet.h"

using namespace std;

int main()
{
	char vd[2+1] = {'P','a', '\0'};
	char va[2+1] = {'M', 'a','\0'};
	char mt[2+1] = {'V', 'e', '\0'};
	TrajetSimple traj (vd,va,mt);
	//traj.AfficheTrajet();

	return 0;
}
