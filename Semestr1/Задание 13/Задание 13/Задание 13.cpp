// Задание 13.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "conio.h"
#include "Перекодировка.h"
#include <iostream>
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	int A,B,A1,B1;
	cout<<Ruc(" Программа преобразует число A в число B и выводит команды, используемые\n для этого.")<<endl;
	cout<<Ruc("Введите натуральное число A= ");
	cin>>A;
	cout<<Ruc("Введите натуральное число B= ");
	cin>>B;
	A1=A;
	B1=B;
	cout<<endl;
	if((A>0)&&(B>0))
	{
	cout<<Ruc("Через цикл for")<<endl;
	for(A;B!=A;)
		if((A%2==0)&&(A/2>=B))
		{
			A/=2;
			cout<<"2";
		}
		else
		{
			A--;
			cout<<"-1";
		}
	cout<<endl;
	cout<<Ruc("Через цикл while")<<endl;
	while(B1!=A1)
		if((A1%2==0)&&(A1/2>=B1))
		{
			A1/=2;
			cout<<"2";
		}
		else
		{
			A1--;
			cout<<"-1";
		}
	cout<<endl;
	}
	else
	cout<<Ruc("Проверьте ввод данных!!!")<<endl;
	_getch;
	return 0;
}

