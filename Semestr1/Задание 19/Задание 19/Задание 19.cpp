// ������� 19.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "conio.h"
#include "math.h"
#include <iostream>
using namespace std;
 void stepen2nerekursiv(int m,int n)
 { 	
	int l,nach,kon;
	nach=ceil(log(m*1.0)/log(2.0));
	kon=floor(log(n*1.0)/log(2.0));
	cout<<"\t"<<"������� 2 c ������� ������������� �������"<<endl;
	for(l=nach;l<=kon;l++)	
		cout<<"\t"<<l<<"\t";	 
	cout<<endl;
 }
 void stepen3nerekursiv(int m,int n)
 { 	
	int l,nach,kon;
	nach=ceil(log(m*1.0)/log(3.0));
	kon=floor(log(n*1.0)/log(3.0));
	cout<<"\t"<<"������� 3 c ������� ������������� �������"<<endl;
	for(l=nach;l<=kon;l++)	
		cout<<"\t"<<l<<"\t";	
	cout<<endl;
 }
int stepen2rekursiv(int m,int n)
{	
	if(floor(log(n*1.0)/log(2.0))>=ceil(log(m*1.0)/log(2.0)))	
	{	
		cout<<'\t'<<ceil(log(m*1.0)/log(2.0))<<'\t';
		return stepen2rekursiv(pow(2.0,ceil(log(m*1.0)/log(2.0))+1),n);
	}
	else
		return 0;
}
int stepen3rekursiv(int m,int n)
{	
	if(floor(log(n*1.0)/log(3.0))>=ceil(log(m*1.0)/log(3.0)))	
	{	
		cout<<'\t'<<ceil(log(m*1.0)/log(3.0))<<'\t';
		return stepen3rekursiv(pow(3.0,ceil(log(m*1.0)/log(3.0))+1),n);
	}
	else
		return 0;
}
 int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL,"Russian");	
	int m,n,u;
	cout<<"  ��������� �������� ������� ������ � ������ � �������� ��������� ����� (�� m \t  �� n ������������)."<<endl<<endl;
	cout<<"  ������� ����� m=";
	cin>>m;	
	cout<<"  ������� ����� n=";
	cin>>n;
	cout<<endl;
	if(n<=m)
	{
		u=n;
		n=m;
		m=u;
	}
	if((n>0)&&(m>0))
	{
		stepen2nerekursiv(m,n);
		cout<<endl;
		stepen3nerekursiv(m,n);
		cout<<endl;
		cout<<"\t"<<"������� 2 c ������� ����������� �������"<<endl;
		stepen2rekursiv(m,n);
		cout<<endl<<endl;
		cout<<"\t"<<"������� 3 c ������� ����������� �������"<<endl;
		stepen3rekursiv(m,n);
		cout<<endl<<endl<<endl;
	}
	else
		cout<<"��������� ���� ������!!!"<<endl;	
	_getch();
	return 0;
}

