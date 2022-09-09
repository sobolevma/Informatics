// Задание 20.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "conio.h"
#include <iostream>
using namespace std; 

double **AllocateAllMemoryBlocksForArray (int height,int width)
{
	double * Memory_block = new double[ height * width];
	double **my_complex_array = new double*[ height ];
	for (int i = 0; i < height; ++i)
			my_complex_array [ i ] = &Memory_block[  i * width ]; 
	return my_complex_array;
}


void InputComplexArray  (double** my_complex_array, int length, int width) 
{  
	for(int i=0;i<length;i++)
	{		
		for(int j=2*i;j<2*i+2;j++)
			for(int k=0;k<2;k++)
			{
				if((j==2*i)&&(k==0))
				{
					cout<<"Введите действительную часть X комплексного числа Z["<<j<<"]=";
					scanf_s ("%lf", &my_complex_array[j][k]);
				}
				else if((j==2*i+1)&&(k==0))
				{
					cout<<"Введите мнимую Y часть комплексного числа Z["<<i<<"]=";
					scanf_s ("%lf", &my_complex_array[j][k]);
				}
				else if(j==2*i) 
					my_complex_array[j][k]=-1;
				else 
					my_complex_array[j][k]=0;
		}
		cout<<endl<<endl;
	}
}  

void BubbleUp (double **my_complex_array,int start_index, int final_index)
{
for(int i=start_index-1;i<=final_index;i--)
{
 int opredel_1 =my_complex_array[0][0]*my_complex_array[1][1]-my_complex_array[0][1]*my_complex_array[1][0]	;
// if()

}
}

void BubbleSort (double **my_complex_array, int length)
{
for (int i = 0; i < length; ++i)
BubbleUp (my_complex_array, length-1, i);
}

void OutputComplexArray (double **my_complex_array, int length,int width) 
{
	for (int i = 0; i < length; i++)
	{
		cout<<"Комплексное число Z["<<i<<"]"<<endl;
		for (int j = 2*i; j < 2*i+2; ++j)
		{	for(int k=0;k<2;k++)						
				cout<<my_complex_array[j][ k] <<"\t";
			cout<<endl;
		}
		cout<<endl<<endl<<endl;
	}
}

void FreeAllMemoryBlocksFor3DArray (double **my_complex_array, int height, int width) 
{
	double * Memory_block = &my_complex_array [ 0 ][ 0 ];
	delete [] Memory_block;
	delete [] my_complex_array;
}

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL,"Russian");
	int length;
	double **my_complex_array;
	cout<<"Введите параметр height=";	
	cin>>length;
	if(length>0)
	{
		cout<<endl;
		const int width=2;
		my_complex_array = AllocateAllMemoryBlocksForArray (length*2, width);
		cout<<"Введите комплексные числа Z."<<endl<<endl;
		InputComplexArray (my_complex_array, length, width);
		cout<<"Вывод комплексных чисел Z."<<endl<<endl;
		OutputComplexArray (my_complex_array, length,width);
		FreeAllMemoryBlocksFor3DArray (my_complex_array, length*2, width);
	}
	else cout<<endl<<"Проверьте значение введенного параметра length!!!"<<endl<<endl;
	_getch();
	return 0;
}

