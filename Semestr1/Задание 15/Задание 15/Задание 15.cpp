// ������� 15.cpp : Defines the entry point for the console application.
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
	cout<<"�������."<<endl;
	cout<<"����� � ��������� � ������� K(N), N<=14, ������� N ���� ���������� ����� R"<<endl;
	cout<<"��� ������������� � � ���������� ������� ���������, � � ���������� D - ����� ����� R, ������� 10-N. "<<endl;
	cout<<"������� ���������� ���������� �����."<<endl;
	cin>>R;
	cout<<"������� ���������� ��������� ������� K."<<endl;
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
	cout<<"������ K:"<<endl;
	cout<<K<<endl;
	cout<<"���������� D:"<<endl;
	cout<<D<<endl;	
	_getch();
	return 0;
}

