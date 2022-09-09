// Lab4_20(1).cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
 #include "conio.h"
 #include "math.h"

int _tmain(int argc, _TCHAR* argv[])
{
double X,D,E,F,V,W,M,N,Y1,Y;
printf("X= ");
scanf("%lf",&X);	
D=exp(X);
E=exp(2*X);
F=exp(3*X);
V=asin(X);
W=acos(X);
M=D-E+F*pow(W,2);
N=D-E+F*sqrt(V);
Y=M/N;
Y1=(exp(X)-exp(2*X)+exp(3*X)*pow(acos(X),2))/(exp(X)-exp(2*X)+exp(3*X)*sqrt(asin(X)));
printf("Y= %lf\n",Y);
printf("Y1= %lf\n",Y1);
	getch();
	return 0;
}	


		  