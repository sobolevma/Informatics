// Задание 14.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "conio.h"
#include "math.h"
#define PI 3.1415926535897932384626433832795
#include <iostream>
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{	
	setlocale(LC_ALL,"Russian");
	double Xm,Xl,Xr,X0,Xn,e,Yl,Yr,Ym,Xp[3],Xi[3];
	int i,n,N;
	cout<<"Программа вычисляет корни уравнения с помощью метода половинного деления"<<endl;
	cout<<"и метода пошаговых итераций."<<endl;
	cout<<"Введите значение начальной точности:";
	cin>>e;
	for(i=0;i<=2;i++)
		Xp[i]=Xi[i]=1000;
	N=10000;
	cout<<"Предельное количество итераций: "<<N<<endl;
	for(i=0;i<=2;i++)
	{
   		n=0;
		if(i==0)
		{
			Xl=-2*PI/3;
			Xr=-PI/16;
		}
		else if(i==1)
		{
			Xl=-2*PI/3;
			Xr=2*PI/3;
		}
		else if(i==2)
		{
			Xl=PI/16;
			Xr=2*PI/3;
		}
		while(abs(Xl-Xr)>=abs(e))
			{					 
				Xm=(Xl+Xr)/2.0;
				Yl=sin(2*Xl)-Xl;
				Yr=sin(2*Xr)-Xr;
				Ym=sin(2*Xm)-Xm;
				if(Yr*Ym>0)
					Xp[i]=Xr=Xm;
				if(Yl*Ym>0)
					Xp[i]=Xl=Xm;
				if(Ym==0)
				{
					Xp[i]=Xm;
					break;
				}	
				n++;   
				if(n>N) break;  
			}
	}	 
	for(i=0;i<=2;i++)
	{
   		n=0;
		X0=(i==0)?-PI/4:(i==1)?PI/2:PI/4;
		Xn=sin(2*X0);
		while(abs(Xn-X0)>=abs(e))
		{	
			X0=Xn;
			Xn=sin(2*X0);	 	 
			n++;
			if(n>=N)	
			{
				Xn=1000;
				break;
			} 
		}
		if(Xn!=1000) Xi[i]=Xn;
	}		 
	cout<<"Корни уравнения методом половинного деления."<<endl;
	for(i=0;i<=2;i++)
		if(Xp[i]<1000)
		cout<<Xp[i]<<endl;
		else cout<<"Метод не подходит для получения корня"<<endl;
    cout<<"Корни уравнения методом простых итераций."<<endl;	
	for(i=0;i<=2;i++)
		if(Xi[i]<1000)
		cout<<Xi[i]<<endl;
		else cout<<"Метод не подходит для получения корня"<<endl;	
	_getch();	
	return 0;
}

