// Задание 18 (ч.4).cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "conio.h"
#include <iostream>
using namespace std; 

int *AllocateMemoryFor1DIntArray (int length) 
{ 
	int *my_1d_array = new int[ length ];
	return my_1d_array;
}

char *AllocateMemoryFor1DCharArray (int length) 
{ 
	char *my_1d_array = new char[ length ];
	return my_1d_array;
}

void InputIntArray  (int my_int_array[], int length) 
{  
	for (int index = 0; index < length; ++index)
	{
		cout<<"Введите элемент my_int_array["<<index<<"]=";
		scanf_s("%d",&my_int_array[ index ]) ;
	}
}   

void InputCharArray  (char my_char_array[], int length) 
{  
	for (int index = 0; index < length; ++index)
	{
		cout<<"Введите элемент my_char_array["<<index<<"]=";
		cin>>my_char_array[ index ] ;
	}
}   


int CompareInt0to9 (void *first_pointer, void *second_pointer ) 
{  
	int *first_element_int_pointer = (int*)first_pointer;  
	int *second_element_int_pointer = (int *)second_pointer;  
	return *first_element_int_pointer -  *second_element_int_pointer; 
} 

int CompareCharAtoZ (void *first_pointer, void *second_pointer ) 
{  
	char *first_element_int_pointer = (char *)first_pointer;  
	char *second_element_int_pointer = (char *)second_pointer;  
	return *first_element_int_pointer -  *second_element_int_pointer; 
} 


typedef int (*CompareFunctionType) (void *, void *);
 
int FindMinimumIndex (void *data_array, int width,  CompareFunctionType compare_function_pointer,   int first_index, int last_index) 
{ 
	char *bytevise_array = (char *)data_array;  
	int minimum_index = first_index;  
	int minimum_byte_number = minimum_index * width;  
	int current_byte_number;   
	for (int element_number = first_index+1;  element_number < last_index; ++element_number) 
	{  
		current_byte_number = element_number * width;   
		if ((*compare_function_pointer) (&bytevise_array [current_byte_number],    &bytevise_array [minimum_byte_number]) < 0 ) 
		    minimum_byte_number = current_byte_number;  
	}  
	minimum_index = minimum_byte_number / width;  
	return minimum_index; 
} 

void SwapChar (char *first_pointer, char *second_pointer) 
{ 
	char temp = *first_pointer;  
	*first_pointer = *second_pointer;  
	*second_pointer = temp;  
}  

void Swap (void *first_pointer, void *second_pointer,  int width) 
{
	for (int byte_number = 0; byte_number < width; ++byte_number)	
				SwapChar ((char *)first_pointer + byte_number,  (char *)second_pointer + byte_number);	
} 

void SelectionSort (char *data_array, int length, int width, CompareFunctionType compare_function_pointer)
{
	for(int i=0;i<length-1;++i)
	{
		int minimum_index=FindMinimumIndex ((void *)data_array, width,compare_function_pointer,i,length);
		Swap(&data_array[i*width],&data_array[minimum_index*width],width);
	
	}
}

void OutputIntArray (int my_int_array[], int length) 
{
	for (int index = 0; index < length; ++index)		
		cout<<my_int_array[ index ] <<endl;	
	cout<<endl<<endl;	
}

void OutputCharArray (char my_char_array[], int length) 
{
	for (int index = 0; index < length; ++index)		
		cout<<my_char_array[ index ] <<endl;	
	cout<<endl<<endl;	
}

void FreeMemoryForIntArray (int *input_data, int length) 
{  	
	delete [] input_data;
} 

void FreeMemoryForCharArray (char *input_data, int length) 
{  	
	delete [] input_data;
} 


int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL,"Russian");
	int length1,length2;
	int *my_int_array;
	char *my_char_array;
	cout<<"Введите длину массива my_int_array=";
	cin>>length1;
	if(length1>0)
	{
		my_int_array=AllocateMemoryFor1DIntArray (length1); 
		cout<<"Введите элементы массива my_int_array."<<endl<<endl;	
		InputIntArray (my_int_array, length1);
		cout<<endl<<"Неотсортированный одномерный целочисленный массив my_int_array."<<endl;
		OutputIntArray (my_int_array, length1);	
		SelectionSort ((char*)my_int_array, length1,sizeof(my_int_array[0]),CompareInt0to9);	
		cout<<endl<<endl<<"Отсортированный одномерный целочисленный массив my_int_array."<<endl;
		OutputIntArray (my_int_array, length1);
		FreeMemoryForIntArray (my_int_array,length1); 
	}
	else cout<<"Проверьте ввод данных!!!"<<endl<<endl;
	cout<<"Введите длину массива my_char_array=";
	cin>>length2;
	if(length2>0)
	{
		my_char_array=AllocateMemoryFor1DCharArray (length2);
		cout<<"Введите элементы char массива my_char_array"<<endl<<endl;
		InputCharArray (my_char_array, length2);
		cout<<endl<<"Неотсортированный одномерный char массив my_char_array."<<endl;
		OutputCharArray (my_char_array, length2);	
		SelectionSort (my_char_array, length2,sizeof (my_char_array [0]), CompareCharAtoZ);
		cout<<endl<<endl<<"Отсортированный одномерный char my_char_array."<<endl;
		OutputCharArray (my_char_array, length2);
		FreeMemoryForCharArray (my_char_array,length2);
	}
	else cout<<"Проверьте ввод данных!!!"<<endl<<endl;
	_getch();
	return 0;
}
