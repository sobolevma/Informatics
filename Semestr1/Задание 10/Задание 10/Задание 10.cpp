// Задание 10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "conio.h"
#include "Перекодировка.h"
#include <iostream>
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
int A,An,i,N,N1,N2,N3,N4,B1,B2,B3,B4;
cout<<(Ruc(" Программа формирует на основе введённого четырёхзначного числа новое число\n таким образом, чтобы цифры в сформированном числе были расположены в порядке\n неубывания слева направо.\n"))<<endl;
cout<<(Ruc(" Введите четырехзначное число А= "));
cin>>A;
if((A/1000>0)&&(A/1000<=9))
{
	B1=A%10;
	B2=A/10%10;
	B3=A/100%10;
	B4=A/1000;
	for(i=1;i<=4;i++)
	{
		if((B1>=B2)&&(B1>=B3)&&(B1>=B4))
		{
			N=B1;
			B1=-1;
		}
		else if((B2>=B1)&&(B2>=B3)&&(B2>=B4))
		{
			N=B2;
			B2=-1;
		}
		else if((B3>=B1)&&(B3>=B2)&&(B3>=B4))
		{
			N=B3;
			B3=-1;
		}
		else 
		{
			N=B4;
			B4=-1;
		}
		switch(i)
		{
			case 1:N1=N;
			case 2:N2=N;
			case 3:N3=N;
			case 4:N4=N;
		}
	}
	An=1000*N4+100*N3+10*N2+N1;
	cout<<(Ruc(" Новое сформированное число An = "))<<An<<"\n"<<endl;
	}
else
cout<<(Ruc(" Ошибка!!! Проверьте правильность ввода!!!\n"))<<endl;
_getch();
return 0;
}

