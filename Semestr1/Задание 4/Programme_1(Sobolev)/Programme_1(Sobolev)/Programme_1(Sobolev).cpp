// Programme_1(Sobolev).cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "conio.h" 
#include "math.h" 
#include "�������������.h"


int _tmain(int argc, _TCHAR* argv[])
{ 
float const g=9.8;
float T;
int S;
printf("Enter S: ");
printf(Ruc("��������� ��������� �����, �� ������� ���� \n ��� ��������� %f\n ������ �������� ����.\n"), g); 
printf(Ruc("������� ����� ���� � ������: ")); 
scanf("%d",&S); 
T=sqrt(S*2/g); 
printf("%s T=%f", Ruc("���� ����� ������� �� "), T); 
printf("%s\n", Ruc(" ������.")); 
getch(); 
return 0; 
	}