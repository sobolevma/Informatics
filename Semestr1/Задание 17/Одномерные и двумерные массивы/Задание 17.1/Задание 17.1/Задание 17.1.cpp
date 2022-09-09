// Задание 17.1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "conio.h"
#include <iostream>
#include <stdio.h>
using namespace std;
	const int ARRAY_LENGTH = 10; 
	const int ARRAY_HEIGHT = 8; 
	const int ARRAY_WIDTH  = 4;

char *AllocateMemoryFor1DArray (int length) 
{ 
	char *my_1d_array = new char[ length ];	
	return my_1d_array;
}

char **AllocateMemoryFor2DArray (int height, int width) 
{ 
	char * Memory_block = new char[ height * width ];
	char **my_2d_array = new char*[ height ];
	for (int row_index = 0; row_index < height; ++row_index)	
		my_2d_array [ row_index ] = &Memory_block [ row_index*width ];	
	return my_2d_array;
}

void Zero1DArray (char my_1d_array[], int length) 
{  
	for (int index = 0; index < length; ++index) 
		my_1d_array[ index ] = 0;  
}   

void Zero2DStaticArray (char my_2d_array[][ARRAY_WIDTH], int height, int width)
{  
	for (int row_index = 0; row_index < height; ++row_index)
		for (int column_index = 0; column_index < width; ++column_index) 
			my_2d_array[ row_index ][column_index] = 0;  
}  
  
void Zero2DDynamicArray (char **my_2d_array, int height, int width) 
{  
	for (int row_index = 0; row_index < height; ++row_index)   
		for (int column_index = 0; column_index < width; ++column_index) 
			my_2d_array[ row_index ][column_index] = 0;     
  
}   

void Zero2DStaticArrayUniversal (char my_2d_array[], int height, int width) 
{    
	for (int row_index = 0; row_index < height; ++row_index)   
		for (int column_index = 0; column_index < width; ++column_index) 
			my_2d_array[ row_index * width + column_index] = 0;       
 }

void Output1DStaticArray (char my_1d_array[], int length) 
{
	for (int length_index = 0; length_index < length; ++length_index)		
		cout<<my_1d_array[  length_index ] <<"\t";	
	cout<<endl<<endl;
	
}

void Output2DStaticArray (char my_2d_array[], int height, int width) 
{
	for (int row_index = 0; row_index < height; ++row_index)
	{
		for (int column_index = 0; column_index < width; ++column_index)		
				cout<<my_2d_array[ row_index * width + column_index ] <<"\t";	
		cout<<endl;		
	}
	cout<<endl<<endl;
}

 void FreeMemoryFor1DArray (char *my_1d_array, int length) 
{  	
	delete [] my_1d_array;
} 

void FreeMemoryFor2DArray (char **my_2d_array, int height, int width) 
{  
	char * Memory_block = &my_2d_array [ 0 ][ 0 ];
	delete [] Memory_block;		 
	delete [] my_2d_array;
}

 int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL,"Russian");	 
	char arrayS[ ARRAY_LENGTH ];  
	Zero1DArray (arrayS, ARRAY_LENGTH);
	cout<<"Статический одномерный массив arrayS."<<endl;
	Output1DStaticArray ((char *)arrayS, ARRAY_LENGTH);
	int variable_length;
	cout<<"Введите длину динамического одномерного массива arrayD."<<endl;
	cin>>variable_length;
	char *arrayD;
	if((variable_length%1==0)&&(variable_length>0))
	{
		cout<<endl;
		arrayD = AllocateMemoryFor1DArray(variable_length);	
		Zero1DArray (arrayD, variable_length); 
		cout<<"Динамический одномерный массив arrayD."<<endl;
		Output1DStaticArray (arrayD, variable_length);
		FreeMemoryFor1DArray(arrayD, variable_length); 
	}
	else
		cout<<endl<<"Проверьте значение введенного значения длины динамического одномерного массива!!!"<<endl<<endl;
	char matrixS[ ARRAY_HEIGHT ][ ARRAY_WIDTH ];  
	Zero2DStaticArray (matrixS,  ARRAY_HEIGHT, ARRAY_WIDTH);
	cout<<"Статический двумерный массив matrixS."<<endl;
	Output2DStaticArray ((char *)matrixS, ARRAY_HEIGHT, ARRAY_WIDTH);
	int variable_height, variable_width;
	char **matrixD;
	cout<<"Введите параметр height динамического двумерного массива matrixD."<<endl;
	cin>>variable_height;
	if((variable_height%1==0)&&(variable_height>0))
	{
		cout<<"Введите параметр width динамического двумерного массива matrixD."<<endl;
		cin>>variable_width;
		if((variable_width%1==0)&&(variable_width>0))
		{	
			cout<<endl;
			matrixD=AllocateMemoryFor2DArray(variable_height,variable_width);
			Zero2DDynamicArray (matrixD, variable_height, variable_width);      
			cout<<"Динамический двумерный массив matrixD."<<endl;
			Output2DStaticArray (&matrixD[0][0], variable_height, variable_width);
			FreeMemoryFor2DArray (matrixD, variable_height, variable_width);
		}
		else 
			cout<<endl<<"Проверьте значение введенного параметра width!!!"<<endl<<endl;
	}
	else
		cout<<endl<<"Проверьте значение введенного параметра height!!!"<<endl<<endl;
	char *row_pointers[ ARRAY_HEIGHT ];  
	for (int row_index = 0; row_index < ARRAY_HEIGHT; ++row_index) 
	row_pointers[ row_index ] = matrixS[ row_index ];   
	Zero2DDynamicArray (row_pointers, ARRAY_HEIGHT, ARRAY_WIDTH);
	cout<<"Статический двумерный массив row_pointers."<<endl;
	Output2DStaticArray(&row_pointers[0][0], ARRAY_HEIGHT, ARRAY_WIDTH);	
	Zero2DStaticArrayUniversal ((char*)matrixS, ARRAY_HEIGHT, ARRAY_WIDTH); 
	cout<<"Статический двумерный массив matrixS."<<endl;
	Output2DStaticArray ((char *)matrixS, ARRAY_HEIGHT, ARRAY_WIDTH);	
	_getch();
	return 0;
}

