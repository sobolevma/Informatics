// ������� 9.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "conio.h"
#include "math.h"
#include "�������������.h"
#include <iostream>
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	double a,b,c,D,X1,X2;
	cout<<(Ruc(" ��������� ��������� ����� ����������� ��������� �� ���������\n ��������� ������������� a,b,c.\n"))<<endl;
	cout<<(Ruc(" ������� ����������� a= "));
	cin>>a;
	cout<<(Ruc(" ������� �����������t b= "));
	cin>>b;
	cout<<(Ruc(" ������� ����������� c= "));
	cin>>c;
	cout<<"\n"<<endl;
	if((a==0)&&(b==0)&&(c==0))
		cout<<Ruc(" ����� �����\n")<<endl;
	else if ((a==0)&&(b==0)&&(c!=0))
		cout<<(Ruc(" ������ ���.\n"))<<endl;
	else if((a==0)&&(b!=0))
	{
		X1=-c/b;
		if (X1==0)
		cout<<(Ruc(" ������������ ������ ��������� X1= "))<<0<<"\n"<<endl;
		else
		cout<<(Ruc(" ������������ ������ ��������� X1= "))<<X1<<"\n"<<endl;
		
	}
	else 
	{
		D=b*b-4*a*c;
		if(D<0) 
			cout<<(Ruc(" ������ ���.\n"))<<endl;
		else if(D==0)
		{
			X1=-b/(2*a);
			if (X1==0)
				cout<<(Ruc(" ������������ ������ ��������� X1= "))<<0<<"\n"<<endl;
			else
				cout<<(Ruc(" ������������ ������ ��������� X1= "))<<X1<<"\n"<<endl;
		}
		else if(D>0)
		{
			X1=(-b+sqrt(D))/(2*a);
			X2=(-b-sqrt(D))/(2*a);
			cout<<(Ruc(" ��� ����� ���������: X1= "))<<X1;
			cout<<(Ruc(" � X2= "))<<X2<<"\n"<<endl;
		}
		}
	_getch();
	return 0;
}

