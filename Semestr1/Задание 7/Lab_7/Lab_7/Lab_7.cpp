// Lab_7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "conio.h"
#include "Перекодировка.h"
#include <iostream>
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
float X;
int Y,Y1;
printf(Ruc("Введите число X="));
cin>>X;
Y=(X<-1)?0:(X<0)?1:(X<2)?-1:1;

if(X<-1)
Y1=0;
if((X>=-1)&&(X<0)||(X>=2))
Y1=1;
if((X>=0)&&(X<2))
Y1=-1;
printf(Ruc("Значение функции с помощью минимального числа операторов if else: Y= %d\n"),Y);
printf(Ruc("Значение функции с помощью оператора if и без логических операций: Y1= %d\n"),Y1);

_getch();
return 0;
}

