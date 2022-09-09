// Задание 18(ч.3).cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "conio.h"
#include <iostream>
#include <stdio.h>
using namespace std; 

int *AllocateMemoryForArray (int length) 
{ 
	int *input_data = new int[ length ];	
	return input_data;
}
void InputArray  (int input_data[], int length) 
{  
	for (int index = 0; index < length; ++index)
	{
		cout<<"Введите элемент input_data["<<index<<"]=";
		scanf_s("%i",&input_data[ index ]) ;
	}
}   

int CompareInt0to9 (void *first_pointer, void *second_pointer ) 
{  
	int *first_element_int_pointer = (int *)first_pointer;  
	int *second_element_int_pointer = (int *)second_pointer;  
	return *first_element_int_pointer -  *second_element_int_pointer; 
} 

int CompareInt9to0 (void *first_pointer, void *second_pointer ) 
{  
	int *first_element_int_pointer = (int *)first_pointer;  
	int *second_element_int_pointer = (int *)second_pointer;  
	return *second_element_int_pointer -  *first_element_int_pointer;
} 


typedef int (*CompareFunctionType) (void *, void *);
 
int FindMinimumIndex (int input_data[], int length,  int first_index, int last_index,CompareFunctionType compare_function_pointer)
{
	int minimum_index = first_index; 
	for (int element_number = first_index; CompareInt0to9(&element_number, &last_index)<0 ; ++element_number) 
	{  
		if ((*compare_function_pointer) (&input_data[element_number], &input_data [minimum_index] )<0) 
			minimum_index = element_number; 
	}  
	return minimum_index;
} 

void Swap (int &first_element, int &second_element)
{
	int prom;
	prom=first_element;
	first_element=second_element;
	second_element=prom;
} 

void SelectionSort (int input_data[], int length,CompareFunctionType compare_function_pointer)
{
	for(int i=0;CompareInt0to9(&i, &length)<0;i++)
	{
		int minimum_index=FindMinimumIndex (input_data, length, i, length,compare_function_pointer);	
		Swap(input_data[minimum_index],input_data[i]);	
	}


}

void OutputArray (int input_data[], int length) 
{
	for (int index = 0; index < length; ++index)		
		cout<<input_data[ index ] <<endl;	
	cout<<endl<<endl;	
}
void FreeMemoryForArray (int *input_data, int length) 
{  	
	delete [] input_data;
} 



int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL,"Russian");
	int length,K;
	cout<<"Введите длину динамического одномерного массива arrayD:";
	cin>>length;
	int *input_data;
	if((length%1==0)&&(length>0))
	{
		cout<<endl;		
		input_data = AllocateMemoryForArray(length);	
		InputArray (input_data, length);
		cout<<endl<<"Динамический неотсортированный одномерный массив input_data."<<endl;
		OutputArray (input_data, length);
		const int N=2;
		CompareFunctionType compareFunctionPointers[ N ];
		cout<<"Введите какую операцию необходимо выполнить: для сортировки \nпо возрастанию введите число 1, а для сортировки \nпо убыванию введите число 2:";
		cin>>K;
		if(K==1)
		{
			compareFunctionPointers[0]= CompareInt0to9 ;
			SelectionSort (input_data, length,compareFunctionPointers[0]);
		}
		else if(K==2)
		{
		compareFunctionPointers[1]= CompareInt9to0 ;
		SelectionSort (input_data, length,compareFunctionPointers[1]);
		}
		else cout<<"Проверьте ввод данных!!!"<<endl;
		if((K==1)||(K==2))
		{
		cout<<endl<<endl<<"Динамический отсортированный одномерный массив input_data."<<endl;
		OutputArray (input_data, length); 
		}
		FreeMemoryForArray(input_data, length); 
	}
	else
		cout<<endl<<"Проверьте значение введенного значения длины динамического одномерного массива!!!"<<endl<<endl;
	_getch();
	return 0;
}
