// Задание 18.cpp : Defines the entry point for the console application.
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

int Compare (void *first_pointer, void *second_pointer ) 
{
	int *first_element_int_pointer = (int *)first_pointer; 
	int *second_element_int_pointer = (int *)second_pointer;  
	return *first_element_int_pointer -  *second_element_int_pointer; 
}

int FindMinimumIndex (int input_data[], int length,  int first_index, int last_index)
{
	int minimum_index = first_index;	
	for (int element_number = first_index;  Compare (&element_number, &last_index)<0 ; ++element_number) 
	{  
		if (Compare (&input_data[element_number], &input_data [minimum_index] )<0) 
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

void SelectionSort (int input_data[], int length)
{
	for(int i=0;Compare (&i, &length)<0;i++)
	{
		int minimum_index=FindMinimumIndex (input_data, length, i, length);
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
	int length;
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
		SelectionSort (input_data, length);
		cout<<"Динамический отсортированный одномерный массив input_data."<<endl;
		OutputArray (input_data, length);
		FreeMemoryForArray(input_data, length);
		
	}
	else
		cout<<endl<<"Проверьте значение введенного значения длины динамического одномерного массива!!!"<<endl<<endl;
	_getch();
	return 0;
}

