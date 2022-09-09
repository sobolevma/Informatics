// Programme_1(Sobolev).cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "conio.h" 
#include "math.h" 
#include "Перекодировка.h"


int _tmain(int argc, _TCHAR* argv[])
{ 
float const g=9.8;
float T;
int S;
printf("Enter S: ");
printf(Ruc("Программа вычисляет время, за которое тело \n при ускорении %f\n пройдёт заданный путь.\n"), g); 
printf(Ruc("Введите длину пути в метрах: ")); 
scanf("%d",&S); 
T=sqrt(S*2/g); 
printf("%s T=%f", Ruc("Путь будет пройден за "), T); 
printf("%s\n", Ruc(" секунд.")); 
getch(); 
return 0; 
	}