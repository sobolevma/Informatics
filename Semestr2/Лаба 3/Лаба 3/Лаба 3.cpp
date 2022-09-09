// ���� 3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "conio.h"
#include <windows.h>
#include <io.h>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <sstream>
using namespace std;
#define N 225
struct country{
char name[30] ;
char capital[30] ;
} ;

bool b;
struct country* countries=( country*)malloc(sizeof(struct country[N]));
struct country* Strana=( country*)malloc(sizeof(struct country[N]));

void Poisk1(int L)
{
	cout<<"������� �������� ������:";
	string s1;
	bool a=false;
	SetConsoleCP(1251);
	cin>>s1;
	SetConsoleCP(866);
	for(int i=0;i<L;i++)
		if(s1==countries[i].name)
			{
			cout<<"������� ������ "<<countries[i].name<<" ��� "<<countries[i].capital<<'.'<<endl;
			a=true;
			break;
			}
	if(a==false)
		cout<<"�� ������ ������� ������ �� �������."<<endl;
	cout<<endl;
}

void Poisk2(int L)
{
	cout<<"������� ������� ������:";
	string s1;
	bool a=false;
	SetConsoleCP(1251);
	cin>>s1; 
	SetConsoleCP(866);
	for(int i=0;i<L;i++)
		if(s1==countries[i].capital)
			{
			cout<<"������, �������� ������� �������� ��������� �����"<<countries[i].capital<<" ��� "<<countries[i].name<<'.'<<endl;
			a=true;
			break;
			}
	if(a==false)
		cout<<"�� ������ ������� ������ �� �������."<<endl;
	cout<<endl;
}

void Otpravka(int R)
{
	FILE *MyFile;
	fopen_s(&MyFile,"F:\\�������� �� ����������� � �������� ����\\� ���� 3\\� ��-�� 1.dat","wb");
	if(MyFile)
	{	 
		if(R<=N)			
			for(int i=0;i<R;i++)					
				fwrite(&countries[i],sizeof(country),1,MyFile);				
	}
	else cout<<"���������� ������!!!";
	fclose(MyFile);	
	cout<<endl;
}

void Zaprosy(int R)
{
	cout<<"�� ������ �� ������ ������?"<<endl;
	cout<<"������� (��) ��� (���).";
	string S;
	SetConsoleCP(1251);
	cin>>S;
	SetConsoleCP(866);
	if(S=="��")
	{
		cout<<"������� ����� ������� (1 ��� 2)."<<endl;		
		int n;
		cin>>n;
		if(n==1)
			Poisk1(R);
		else if(n==2)
			Poisk2(R);	
		else
			cout<<"������������ ���� ������."; 
	}
	else if(S=="���") cout<<endl;
	else
		cout<<"������������ ���� ������."<<endl;
	cout<<endl;
}

void Sortirovka (int P)
{
	for(int i=0;i<P-1;i++)
	{
		bool a=false;
		for(int j=0;j<P-i-1;j++)
		{
			int h=strlen(countries[j].name);
			int k=strlen(countries[j+1].name);
			h=h<k?h:k;
			int m=0;
			while((countries[j].name[m]==countries[j+1].name[m])&&(m<h))m++;
			if(countries[j].name[m]>countries[j+1].name[m])
			{
				strcpy_s(Strana[j].name,countries[j].name);
				strcpy_s(Strana[j].capital,countries[j].capital);
				strcpy_s(countries[j].name,countries[j+1].name);
				strcpy_s(countries[j].capital,countries[j+1].capital);
				strcpy_s(countries[j+1].name,Strana[j].name);
				strcpy_s(countries[j+1].capital,Strana[j].capital);		
				a=true;
			}
		}
		if(a==false)break;
	}
}

 void Vvod(int i,int P)
 {
			for(i;i<P;i++)		
			{
				cout<<"������� �������� ������: ";
				SetConsoleCP(1251);
				cin>>countries[i].name;
				SetConsoleCP(866);
				cout<<"������� ������� ������ "<<countries[i].name<<" : ";
				SetConsoleCP(866);
				SetConsoleCP(1251);
				cin>>countries[i].capital;				
				SetConsoleCP(866);				
			}
			cout<<endl;
 }

 int Vopros1(int P1)
{
	cout<<"�� ������ �� ������ � ������ ����� ������?"<<endl;
	cout<<"������� (��) ��� (���): ";	
	string S;
	SetConsoleCP(1251);
	cin>>S;
	SetConsoleCP(866);
	int n;
	if(S=="��")
		{
		cout<<"�������, ������� ����� �� ������ ��������."<<endl;		
		cin>>n;
		Vvod(P1,P1+n);
		Sortirovka(P1+n);
		}
	else if(S=="���") cout<<endl;
	else
		cout<<"������������ ���� ������."<<endl; 
	cout<<endl;
	if(S=="��")
	return P1+n;
	else return P1;
 }

int Zapolnenienew()
{  
	FILE *MyFile1;
	fopen_s(&MyFile1,"F:\\�������� �� ����������� � �������� ����\\� ���� 3\\� ��-�� 1.dat","rb");	
	int dlina_faila;
	if(MyFile1)
		{
			dlina_faila=_filelength(_fileno(MyFile1))/sizeof(country);	
			for(int i=0;i<dlina_faila;i++)
			{				
				fseek(MyFile1,i*sizeof(country),SEEK_SET);
				fread(&countries[i],sizeof(country),1,MyFile1);
				cout<<countries[i].name;
				cout<<"          ";				
				cout<<countries[i].capital;
				cout<<endl;
			}			
		}
	else cout<<"���������� ������!!!";
	fclose(MyFile1);
	return dlina_faila;
}

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL,"Russian");
	int P;
	cout<<"������� ���������� �����:";
	cin>>P;
	if((P>0)&&(P<=N))
	{
			int i=0;
			cout<<"������� �������� ���� ����������_������ ������� ����� ������ _ ."<<endl;
			Vvod(i,P);
			Sortirovka(P);
			Otpravka(P);			
			int H=Zapolnenienew();	
			H=Vopros1(H);				
			Otpravka(H);
			int H1=Zapolnenienew();	
			Zaprosy(H1);
			Otpravka(H1);
	}
	free(countries);
	free(Strana);
	_getch();
	return 0;
}

