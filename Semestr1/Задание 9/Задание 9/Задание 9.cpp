// Задание 9.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "conio.h"
#include "math.h"
#include "Перекодировка.h"
#include <iostream>
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	double a,b,c,D,X1,X2;
	cout<<(Ruc(" Программа вычисляет корни квадратного уравнения по введенным\n значениям коэффициентов a,b,c.\n"))<<endl;
	cout<<(Ruc(" Введите коэффициент a= "));
	cin>>a;
	cout<<(Ruc(" Введите коэффициентt b= "));
	cin>>b;
	cout<<(Ruc(" Введите коэффициент c= "));
	cin>>c;
	cout<<"\n"<<endl;
	if((a==0)&&(b==0)&&(c==0))
		cout<<Ruc(" Любое число\n")<<endl;
	else if ((a==0)&&(b==0)&&(c!=0))
		cout<<(Ruc(" Корней нет.\n"))<<endl;
	else if((a==0)&&(b!=0))
	{
		X1=-c/b;
		if (X1==0)
		cout<<(Ruc(" Единственный корень уравнения X1= "))<<0<<"\n"<<endl;
		else
		cout<<(Ruc(" Единственный корень уравнения X1= "))<<X1<<"\n"<<endl;
		
	}
	else 
	{
		D=b*b-4*a*c;
		if(D<0) 
			cout<<(Ruc(" Корней нет.\n"))<<endl;
		else if(D==0)
		{
			X1=-b/(2*a);
			if (X1==0)
				cout<<(Ruc(" Единственный корень уравнения X1= "))<<0<<"\n"<<endl;
			else
				cout<<(Ruc(" Единственный корень уравнения X1= "))<<X1<<"\n"<<endl;
		}
		else if(D>0)
		{
			X1=(-b+sqrt(D))/(2*a);
			X2=(-b-sqrt(D))/(2*a);
			cout<<(Ruc(" Два корня уравнения: X1= "))<<X1;
			cout<<(Ruc(" и X2= "))<<X2<<"\n"<<endl;
		}
		}
	_getch();
	return 0;
}

