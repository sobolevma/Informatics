// Лаба 1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "conio.h"
#include <windows.h>
#include <iostream>
#include <sstream>//Для подключения функции для перевода строки типа double в число.
#include <fstream>
using namespace std;
bool yavliaetsia_glasnoi(char k)
{
if((k=='a')||(k=='e')||(k=='i')||(k=='o')||(k=='u')||(k=='y')||(k=='A')||(k=='E')||(k=='I')||(k=='O')||(k=='U')||(k=='Y')||
			(k=='а')||(k=='е')||(k=='ё')||(k=='и')||(k=='о')||(k=='у')||(k=='ы')||(k=='э')||(k=='ю')||(k=='я')||(k=='А')||(k=='Е')||
			(k=='Ё')||(k=='И')||(k=='О')||(k=='У')||(k=='Ы')||(k=='Э')||(k=='Ю')||(k=='Я'))
	return true;
else
	return false;
}

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL,"Russian");
	ofstream MyFile("F:\\Практика по информатике в бауманке Лабы\\К лабе 2\\Часть первая.txt");
	string S;		
	int n;
	SetConsoleCP(1251);
	getline(cin,S);
	SetConsoleCP(866);
	n=S.length();
	if(MyFile)
	{
		for(int i=0;i<n;i++)
				MyFile<<S[i];
	}
	else
		cout<<"Невозможно открыть файл!!!";
	MyFile.close();
	ifstream  MyFile1("F:\\Практика по информатике в бауманке Лабы\\К лабе 2\\Часть первая.txt",ios::in);
	ofstream  MyFile2("F:\\Практика по информатике в бауманке Лабы\\К лабе 2\\Часть вторая.txt");
	if((MyFile1)&&(MyFile2))
	{	
		int i=0;
		string word="";	
		while(!MyFile1.eof())
		{
		char simbol=MyFile1.get();
		S+=simbol;		
		i++;
		}
		int n=i-1;		
		int glasn=0,bukvy_v_slove=0,n1;		
		const int MAX_BUKV_V_SLOVE=26;
		bool slovo=false;
		string S1="Доля гласных";
		n1=S1.length();
		MyFile2<<"Слово"<<"                         "<<S1<<"          Доля согласных";
		for (i=0;i<n;i++)
		{
		if((S[i]>='a')&&(S[i]<='z')||(S[i]>='A')&&(S[i]<='Z')||(S[i]>='а')&&(S[i]<='я')||(S[i]>='А')&&(S[i]<='Я')||(S[i]=='ё')||(S[i]=='Ё'))
		{
			slovo=true; 
			word+=S[i];
			bukvy_v_slove++;
			if(yavliaetsia_glasnoi(S[i]))
				glasn++;
		} 		
		if(!((S[i]>='a')&&(S[i]<='z')||(S[i]>='A')&&(S[i]<='Z')||(S[i]>='а')&&(S[i]<='я')||(S[i]>='А')&&(S[i]<='Я')||(S[i]=='ё')||(S[i]=='Ё'))||(i==n-1)&&(slovo))
			{																										   
				
				if((glasn>=bukvy_v_slove-glasn)&&(bukvy_v_slove!=0))
				{
					MyFile2<<endl;
					int j;
					for(j=0;j<bukvy_v_slove;j++)
						MyFile2<<word[j];
					while(j<MAX_BUKV_V_SLOVE-1)
					{
						j++;
						MyFile2<<' ';
					}
					double dolia_glasnich_bukv=(double)glasn/bukvy_v_slove;
					ostringstream ost;
					ost<<dolia_glasnich_bukv;
					int n2=(ost.str()).length();
					MyFile2<<"     "<<dolia_glasnich_bukv;
					while(n2<n1)
						{
						n2++;
						MyFile2<<' ';
						}
					MyFile2<<"          "<<(double)(bukvy_v_slove-glasn)/bukvy_v_slove;					
				}
				word="";
				bukvy_v_slove=0;
				glasn=0;			
				slovo=false;
			}	
		
		} 
	}
	else
	 cout<<"Невозможно открыть один из файлов или оба файла!!!";
	MyFile1.close();
	MyFile2.close();	
	_getch();
	return 0;
}

