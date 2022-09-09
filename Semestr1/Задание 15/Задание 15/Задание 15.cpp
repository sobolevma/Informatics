// Задание 15.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "conio.h"
#include <string>
#include <iostream>
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL,"Russian");
	string R,K="",D;
	long i,N,M;
	cout<<"Задание."<<endl;
	cout<<"Найти и сохранить в массиве K(N), N<=14, старшие N цифр правильной дроби R"<<endl;
	cout<<"при представлении её в десятичной системе счисления, а в переменной D - часть числа R, меньшую 10-N. "<<endl;
	cout<<"Введите правильную десятичную дробь."<<endl;
	cin>>R;
	cout<<"Введите количество элементов массива K."<<endl;
	cin>>N;
	M=R.length();
	if(R[0]!='-')
		for(i=2,D="0,";i<M;i++)
			if(i<=N+1)
			{
				K+=R[i];
				D+='0';
			}
			else D+=R[i];
	else
		for(i=3,D="-0,";i<M;i++)
		if(i<=N+2)
		{
			K+=R[i];
			D+='0';
		}
		else D+=R[i];
	cout<<"Массив K:"<<endl;
	cout<<K<<endl;
	cout<<"Переменная D:"<<endl;
	cout<<D<<endl;	
	_getch();
	return 0;
}

