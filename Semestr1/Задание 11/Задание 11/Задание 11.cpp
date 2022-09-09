 // Задание 11.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "conio.h"
#include "math.h"
#include "Перекодировка.h"
#define PI 3.1415926535897932384626433832795
#include <iostream>
using namespace std;
 int _tmain(int argc, _TCHAR* argv[])
{
	double X=0,M,Zn,Zn1,P1,P2,P3,P4,AbsolOsh,OtnosOsh,F1,F2,F3,F4;
	F1=2;
	F2=F1*3*4;
	F3=F2*5*6;
	F4=F3*7*8;
	cout<<Ruc("\t\t\t\t Обозначения:")<<endl;
	cout<<Ruc(" cos X - косинус числа X")<<endl;
	cout<<Ruc(" Zn - приближенное значение функции с использованием скобочных форм и\n дополнительных переменных")<<endl;
	cout<<Ruc(" Zn1 - приближенное значение функции без использованием скобочных форм и\n дополнительных переменных")<<endl;
	cout<<Ruc(" AbsolOsh - абсолютная ошибка приближенного значения")<<endl;
	cout<<Ruc(" AbsolOsh - относительная ошибка приближенного значения\n")<<endl;
	cout<<Ruc("\t\t\t\t   Таблица.")<<endl;
	printf("  cos X\t\t   Zn\t\t   Zn1\t\t  AbsolOsh\t  OtnosOsh\n");
	do
	{
	M=cos(X);
	P1=X*X;
	P2=P1*X*X;
	P3=P2*X*X;
	P4=P3*X*X;
	Zn=1-P1/F1+P2/F2-P3/F3+P4/F4;
	Zn1=1-X*X/2+X*X*X*X/(2*3*4)-X*X*X*X*X*X/(2*3*4*5*6)+X*X*X*X*X*X*X*X/(2*3*4*5*6*7*8);
	AbsolOsh=abs(Zn-M);
	OtnosOsh=AbsolOsh/M*100;
	printf(" %lf\t%lf\t%lf\t%e\t%e%%\n",M,Zn,Zn1,AbsolOsh,OtnosOsh);		
	X+=0.1;
	}
	while(X<PI/4);				  
	cout<<"\n"<<endl;
	_getch();
	return 0;
}

