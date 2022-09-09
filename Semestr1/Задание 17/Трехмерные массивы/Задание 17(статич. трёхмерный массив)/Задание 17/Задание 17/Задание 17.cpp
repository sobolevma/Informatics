// Задание 17.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "conio.h"
#include <iostream>
#include <stdio.h>
using namespace std;

void Input3DStaticArray (int my_3d_array[], int height, int width, int depth) 
{
	for (int row_index = 0; row_index < height; ++row_index) 
		for (int column_index = 0; column_index < width; ++column_index)
			for (int depth_index = 0; depth_index < depth; ++depth_index)
			{
				cout<<"Введите элемент my_3d_array["<<row_index<<"]["<<column_index<<"]["<<depth_index<<"]=";
				scanf_s ("%i", &my_3d_array[ ( row_index * width + column_index )*depth +depth_index] );
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

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL,"Russian");	
	const int MY_3D_ARRAY_HEIGHT = 2;  
	const int MY_3D_ARRAY_WIDTH = 3;  
	const int MY_3D_ARRAY_DEPTH = 3;  
	int my_3d_array[ MY_3D_ARRAY_HEIGHT ][ MY_3D_ARRAY_WIDTH ][ MY_3D_ARRAY_DEPTH ];  
	cout<<"Введите элементы статического массива."<<endl<<endl;
	Input3DStaticArray ((int*) my_3d_array, MY_3D_ARRAY_HEIGHT, MY_3D_ARRAY_WIDTH, MY_3D_ARRAY_DEPTH);
	cout<<endl;
	Output3DStaticArray ((int*) my_3d_array, MY_3D_ARRAY_HEIGHT, MY_3D_ARRAY_WIDTH, MY_3D_ARRAY_DEPTH); 					
	_getch();
	return 0;
}





