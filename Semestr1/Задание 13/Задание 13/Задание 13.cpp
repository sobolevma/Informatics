// ������� 13.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "conio.h"
#include "�������������.h"
#include <iostream>
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	int A,B,A1,B1;
	cout<<Ruc(" ��������� ����������� ����� A � ����� B � ������� �������, ������������\n ��� �����.")<<endl;
	cout<<Ruc("������� ����������� ����� A= ");
	cin>>A;
	cout<<Ruc("������� ����������� ����� B= ");
	cin>>B;
	A1=A;
	B1=B;
	cout<<endl;
	if((A>0)&&(B>0))
	{
	cout<<Ruc("����� ���� for")<<endl;
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
	cout<<Ruc("����� ���� while")<<endl;
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
	cout<<Ruc("��������� ���� ������!!!")<<endl;
	_getch;
	return 0;
}

