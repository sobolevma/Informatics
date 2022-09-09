// Д_З часть2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "conio.h"

int _tmain(int argc, _TCHAR* argv[])
{
	int A,B,C,D,Naib;
	printf("Vvedite chetire celich chisla:\n");
	scanf("%d %d %d %d",&A,&B,&C,&D);
	Naib=(A>B)?A:(B>C)?B:(C>D)?C:D;
	printf("Naibolshee= %d\n",Naib);
	getch();
	return 0;
}

