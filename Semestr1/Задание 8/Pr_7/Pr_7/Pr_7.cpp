// Pr_7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "conio.h"
#include "�������������.h"
#include <iostream>
#include <string>
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
float X,Y,M,N;
string Z1,Z2;
M=0.0;
N=-2.0;
cout<<Ruc("������� ���������� �����.")<<endl;
cout<<Ruc("���������� X= ");
cin>>X;
cout<<Ruc("���������� Y= ");
cin>>Y;

if(Y<N)
	Z1="IV";
else if(Y<M)
	Z1="III";
else if (Y<X)
	Z1="III";
else if (Y>X+2)
	Z1="II";
else if (X>=M)
	Z1="II";
else Z1="I";

if((X<M)&&(Y<=X+2))
	Z2="I";
if((X<M)&&(Y>X+2)||(X>=M)&&(Y>=X))
	Z2="II";
if((Y<M)&&(Y>=N)||(Y>=M)&&(Y<X))
	Z2="III";
if(Y<N)
	Z2="IV";
cout<<Ruc("� �������������� ���������� else if � ��� ���������� ��������")<<endl;
cout<<Ruc("��������� �������� ��������:  ");
cout<<Ruc("Z1= ")<<Z1<<endl;
cout<<Ruc("� �������������� ������ ��������� else � ���������� ��������")<<endl;
cout<<Ruc("��������� �������� ��������:  ");
cout<<Ruc("Z2= ")<<Z2<<endl;
_getch();	
return 0;
}

