// ���� 1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "conio.h"
#include <windows.h>
#include <iostream>
#include <sstream>//��� ����������� ������� ��� �������� ������ ���� double � �����.
#include <fstream>
using namespace std;
bool yavliaetsia_glasnoi(char k)
{
if((k=='a')||(k=='e')||(k=='i')||(k=='o')||(k=='u')||(k=='y')||(k=='A')||(k=='E')||(k=='I')||(k=='O')||(k=='U')||(k=='Y')||
			(k=='�')||(k=='�')||(k=='�')||(k=='�')||(k=='�')||(k=='�')||(k=='�')||(k=='�')||(k=='�')||(k=='�')||(k=='�')||(k=='�')||
			(k=='�')||(k=='�')||(k=='�')||(k=='�')||(k=='�')||(k=='�')||(k=='�')||(k=='�'))
	return true;
else
	return false;
}

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL,"Russian");
	ofstream MyFile("F:\\�������� �� ����������� � �������� ����\\� ���� 2\\����� ������.txt");
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
		cout<<"���������� ������� ����!!!";
	MyFile.close();
	ifstream  MyFile1("F:\\�������� �� ����������� � �������� ����\\� ���� 2\\����� ������.txt",ios::in);
	ofstream  MyFile2("F:\\�������� �� ����������� � �������� ����\\� ���� 2\\����� ������.txt");
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
		string S1="���� �������";
		n1=S1.length();
		MyFile2<<"�����"<<"                         "<<S1<<"          ���� ���������";
		for (i=0;i<n;i++)
		{
		if((S[i]>='a')&&(S[i]<='z')||(S[i]>='A')&&(S[i]<='Z')||(S[i]>='�')&&(S[i]<='�')||(S[i]>='�')&&(S[i]<='�')||(S[i]=='�')||(S[i]=='�'))
		{
			slovo=true; 
			word+=S[i];
			bukvy_v_slove++;
			if(yavliaetsia_glasnoi(S[i]))
				glasn++;
		} 		
		if(!((S[i]>='a')&&(S[i]<='z')||(S[i]>='A')&&(S[i]<='Z')||(S[i]>='�')&&(S[i]<='�')||(S[i]>='�')&&(S[i]<='�')||(S[i]=='�')||(S[i]=='�'))||(i==n-1)&&(slovo))
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
	 cout<<"���������� ������� ���� �� ������ ��� ��� �����!!!";
	MyFile1.close();
	MyFile2.close();	
	_getch();
	return 0;
}

