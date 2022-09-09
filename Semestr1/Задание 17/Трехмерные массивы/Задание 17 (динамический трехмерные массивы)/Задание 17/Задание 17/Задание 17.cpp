// Задание 17.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "conio.h"
#include <iostream>
#include <stdio.h>
using namespace std;

int ***AllocateMemoryFor3DArray (int height, int width, int depth) 
{ 
	int ***my_3d_array = new int**[ height ];
	for (int row_index = 0; row_index < height; ++row_index) 
	{
		my_3d_array [ row_index ] = new int * [ width ];
		for (int column_index = 0; column_index < width; ++column_index)
			my_3d_array [ row_index ][ column_index ] = new int [ depth ]; 
	}
	return my_3d_array;
}

int ***AllocateLargeMemoryBlockFor3DArray (int height, int width, int depth)
{
	int * large_memory_block = new int[ height * width * depth ]; 
	int ***my_3d_array = new int**[ height ];
	for (int row_index = 0; row_index < height; ++row_index) 
	{
		my_3d_array [ row_index ] = new int * [ width ];
		for (int column_index = 0; column_index < width; ++column_index)
			my_3d_array [ row_index ][ column_index ] = &large_memory_block[ ( row_index * width + column_index )*depth]; 
	}
	return my_3d_array;
}

int ***AllocateAllMemoryBlocksFor3DArray (int height, int width, int depth)
{
	int * large_memory_block = new int[ height * width * depth ];
	int **first_level_pointers_memory_block=new int*[ height * width];
	int ***my_3d_array = new int**[ height ];
	for (int row_index = 0; row_index < height; ++row_index) 
	{
		my_3d_array [ row_index ] = &first_level_pointers_memory_block[ row_index * width ];
		for (int column_index = 0; column_index < width; ++column_index)
			my_3d_array [ row_index ][ column_index ] = &large_memory_block[ ( row_index * width + column_index )*depth]; 
	}
	return my_3d_array;
}

void Input3DDynamicArray (int ***my_3d_array, int height, int width, int depth) 
{
	cout<<"Введите элементы динамического массива my_3d_array."<<endl<<endl;
	for (int row_index = 0; row_index < height; ++row_index)
		for (int column_index = 0; column_index < width; ++column_index)
			for (int depth_index = 0; depth_index < depth; ++depth_index)
			{
				cout<<"Введите элемент my_3d_array["<<row_index<<"]["<<column_index<<"]["<<depth_index<<"]=";
				scanf_s ("%i", &my_3d_array[ row_index ][ column_index ][ depth_index ]);
			} 
}

void Input3DStaticArray (int my_3d_array[], int height, int width, int depth) 
{
	cout<<"Введите элементы динамического массива my_3d_array."<<endl<<endl;
	for (int row_index = 0; row_index < height; ++row_index) 
		for (int column_index = 0; column_index < width; ++column_index)
			for (int depth_index = 0; depth_index < depth; ++depth_index)
			{
				cout<<"Введите элемент my_3d_array["<<row_index<<"]["<<column_index<<"]["<<depth_index<<"]=";
				scanf_s ("%i", &my_3d_array[ ( row_index * width + column_index )*depth +depth_index] );
			}
}

void Output3DDynamicArray (int ***my_3d_array, int height, int width, int depth) 
{
	for (int row_index = 0; row_index < height; ++row_index)
	{
		for (int column_index = 0; column_index < width; ++column_index)
		{
			for (int depth_index = 0; depth_index < depth; ++depth_index) 
				cout<<my_3d_array[ row_index ][ column_index ][ depth_index ]<<"\t";
			cout<<endl;
		}
		cout<<endl<<endl;
	}
}

void Output3DStaticArray (int my_3d_array[], int height, int width, int depth) 
{
	for (int row_index = 0; row_index < height; ++row_index)
	{
		for (int column_index = 0; column_index < width; ++column_index)
		{
			for (int depth_index = 0; depth_index < depth; ++depth_index) 
				cout<<my_3d_array[ ( row_index * width + column_index )*depth +depth_index] <<"\t";
			cout<<endl;
		}
		cout<<endl<<endl;
	}
}

void FreeMemoryFor3DArray (int ***my_3d_array, int height, int width, int depth) 
{  
	for (int row_index = 0; row_index < height; ++row_index) 
	{   
		for (int column_index = 0; column_index < width; ++column_index)	    
			delete [] my_3d_array [ row_index ][ column_index ];	   
		delete [] my_3d_array [ row_index ];  
	}  
	delete [] my_3d_array;
}

void FreeLargeMemoryBlockFor3DArray (int ***my_3d_array, int height, int width, int depth) 
{
	int * large_memory_block = &my_3d_array [ 0 ][ 0 ][ 0 ];  
	delete [] large_memory_block; 
	for (int row_index = 0; row_index < height; ++row_index)   
		delete [] my_3d_array [ row_index ]; 
	delete [] my_3d_array;
}

void FreeAllMemoryBlocksFor3DArray (int ***my_3d_array, int height, int width, int depth) 
{
	int * large_memory_block = &my_3d_array [ 0 ][ 0 ][ 0 ];
	delete [] large_memory_block;
	int **first_level_pointers_memory_block = &my_3d_array [ 0 ][ 0 ]; 
	delete [] first_level_pointers_memory_block;
	delete [] my_3d_array;
}

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL,"Russian");
	int my_3d_array_height, my_3d_array_width,my_3d_array_depth;
	int ***my_3d_array;
	cout<<"Введите параметр height=";	
	cin>>my_3d_array_height;
	if(my_3d_array_height>0)
	{
		cout<<"Введите параметр width=";
		cin>>my_3d_array_width;
		if(my_3d_array_width>0)
		{
			cout<<"Введите параметр depth=";
			cin>>my_3d_array_depth;
			if(my_3d_array_depth>0)
			{
				cout<<endl;
				my_3d_array = AllocateMemoryFor3DArray (my_3d_array_height, my_3d_array_width, my_3d_array_depth);
				Input3DDynamicArray (my_3d_array, my_3d_array_height, my_3d_array_width, my_3d_array_depth);
				cout<<endl<<"Массив my_3d_array to dynamic type:"<<endl<<endl;	
				Output3DDynamicArray (my_3d_array, my_3d_array_height, my_3d_array_width, my_3d_array_depth);
				FreeMemoryFor3DArray (my_3d_array, my_3d_array_height, my_3d_array_width, my_3d_array_depth); 
				my_3d_array = AllocateLargeMemoryBlockFor3DArray (my_3d_array_height, my_3d_array_width, my_3d_array_depth);
				Input3DDynamicArray (my_3d_array, my_3d_array_height, my_3d_array_width, my_3d_array_depth);
				cout<<endl<<"Массив my_3d_array to dynamic type:"<<endl<<endl;	
				Output3DDynamicArray (my_3d_array, my_3d_array_height, my_3d_array_width, my_3d_array_depth);
				Input3DStaticArray (&my_3d_array[0][0][0],my_3d_array_height,my_3d_array_width, my_3d_array_depth);
				cout<<endl<<"Массив my_3d_array to static type:"<<endl<<endl;
				Output3DStaticArray (&my_3d_array[0][0][0],my_3d_array_height,my_3d_array_width, my_3d_array_depth);
				FreeLargeMemoryBlockFor3DArray (my_3d_array, my_3d_array_height, my_3d_array_width, my_3d_array_depth);
				my_3d_array = AllocateAllMemoryBlocksFor3DArray (my_3d_array_height, my_3d_array_width, my_3d_array_depth);
				Input3DDynamicArray (my_3d_array, my_3d_array_height, my_3d_array_width, my_3d_array_depth);
				cout<<endl<<"Массив my_3d_array to dynamic type:"<<endl<<endl;	
				Output3DDynamicArray (my_3d_array, my_3d_array_height, my_3d_array_width, my_3d_array_depth);
				Input3DStaticArray (&my_3d_array[0][0][0],my_3d_array_height,my_3d_array_width, my_3d_array_depth);
				cout<<endl<<"Массив my_3d_array to static type:"<<endl<<endl;
				Output3DStaticArray (&my_3d_array[0][0][0],my_3d_array_height,my_3d_array_width, my_3d_array_depth);
				FreeAllMemoryBlocksFor3DArray (my_3d_array, my_3d_array_height, my_3d_array_width, my_3d_array_depth);
			}
			else
				cout<<endl<<"Проверьте значение введенного параметра depth!!!"<<endl<<endl;
		}
		else
			cout<<endl<<"Проверьте значение введенного параметра width!!!"<<endl<<endl;
	}
	else
		cout<<endl<<"Проверьте значение введенного параметра height!!!"<<endl<<endl;
	_getch();
	return 0;
}

