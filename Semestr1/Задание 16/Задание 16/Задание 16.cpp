// Задание 16.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "conio.h"
#include <iostream>
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{	
	int m,n,L,A[10][12],Max,Min,Max_Min2,i,j,i_max,j_max,i_min,j_min,i_max2,j_max2,P,M,N;		
	bool a,b;
	setlocale(LC_ALL,"Russian");	
	cout<<" Введите число строк m=";
	cin>>m;
	cout<<" Введите число столбцов n=";
	cin>>n;
	cout<<" Введите число L=";
	cin>>L;
	cout<<endl;
	N=M=0;
	if((m>0)&&(n>0)&&(L!=0))
	{
		int **A1=new int *[m];
		cout<<" Введите элементы матрицы А:"<<endl;				
		for(i=0;i<m;i++)
		{	
			A1[i]=new int[n];		
			for(j=0;j<n;j++)
			{
				cout<<" Введите элемент A["<<i<<"]["<<j<<"]=";
				cin>>A[i][j];
				A1[i][j]=A[i][j];
				if(A[i][j]%L==0)
					if(A[i][j]>=0)
						M++;
					else N++;
			}	
		}
		a=b=false;
		cout<<endl;
		cout<<" Начальная матрица A:"<<endl;
		for(i=0;i<m;i++)
		{
			cout<<" ";
			for(j=0;j<n;j++)
			{
				cout<<A[i][j]<<"\t";					
				if((M>0)&&(N==0))
				{
					if(A[i][j]%L==0)
					{					
						if(a)
						{
							if (A[i][j]>=Max)
							{
								i_max=i;
								j_max=j;				
								Max=A[i][j];
							}
						}
						else 
						{
							a=true;
							i_max2=i_max=i;
							j_max2=j_max=j;
							Max_Min2=Max=A[i][j];
						}					
						if(b)
						{
							if (A[i][j]<=Min)
							{
								i_min=i;
								j_min=j;
								Min=A[i][j];
							}
						}
						else if(a)
								if(Max_Min2<Max)
								{
									i_min=i_max2;
									j_min=j_max2;
									Min=Max_Min2;
									b=true;
								}			
					}
				}
				else if((N>0)&&(M==0))
				{
						if(A[i][j]%L==0)
						{					
							if(b)
							{
								if (A[i][j]<=Min)
								{
									i_min=i;
									j_min=j;				
									Min=A[i][j];
								}
							}
							else 
							{
								b=true;
								i_max2=i_min=i;
								j_max2=j_min=j;
								Max_Min2=Min=A[i][j];
							}					
							if(a)
							{
								if (A[i][j]>=Max)
								{
									i_max=i;
									j_max=j;
									Max=A[i][j];
								}
							}
							else if(b)
								if(Max_Min2>Min)
								{
									i_max=i_max2;
									j_max=j_max2;
									Max=Max_Min2;
									a=true;
								}			
					}	
				
				}
				else
						if(A[i][j]%L==0)
						{					
							if(b)
							{
								if (A[i][j]<=Min)
								{
									i_min=i;
									j_min=j;				
									Min=A[i][j];
								}
							}
							else 
							{
								b=true;
								i_min=i;
								j_min=j;
								Min=A[i][j];
							}					
							if(a)
							{
								if (A[i][j]>=Max)
								{
									i_max=i;
									j_max=j;				
									Max=A[i][j];
								}
							}
							else 
							{
								a=true;
								i_max=i;
								j_max=j;
								Max=A[i][j];
							}		
					}	
				
				}
					
			cout<<endl;
			}
		cout<<endl;		
		if((a==true)&&(b==true))
		{
			cout<<" Максимальный элемент матрицы A равен "<<Max<<" с индексом i="<<i_max<<"\n и индексом j="<<j_max<<endl;
			cout<<" Минимальный элемент матрицы A равен "<<Min<<" с индексом i="<<i_min<<"\n и индексом j="<<j_min<<endl;			
			if(i_max!=i_min)
				for(j=0;j<n;j++)
				{
					P=A[i_max][j];
					A[i_max][j]=A[i_min][j];
					A[i_min][j]=P;			
				}
			else
				for(i=0;i<m;i++)
				{
					P=A[i][j_max];
					A[i][j_max]=A[i][j_min];
					A[i][j_min]=P;			
				}	
		}
		else
		{
			if((a==true)||(b==true))
			{
				if(b==true)
				{
					Max=Min;
					i_max=i_min;
					j_max=j_min;
				}
				cout<<" Максимальный элемент матрицы A равен "<<Max<<" с индексом i="<<i_max<<"\n и индексом j="<<j_max<<endl;
				cout<<" Минимального элемента матрицы A, удовлетворяющему данному\n условию, не существует"<<endl;
			}
			else
			{
				cout<<" Максимального элемента матрицы A, удовлетворяющему данному\n условию,не существует"<<endl;
				cout<<" Минимального элемента матрицы A, удовлетворяющему данному\n условию, не существует"<<endl;
			}
			for(j=0;j<n;j++)
			{
				P=A[0][j];
				A[0][j]=A[m-1][j];
				A[m-1][j]=P;			
			}
		}
		cout<<endl;
		cout<<" Новая матрица A:"<<endl<<endl;
		for(i=0;i<m;i++)
		{
			cout<<" ";
			for(j=0;j<n;j++)		
				cout<<A[i][j]<<"\t";
			cout<<endl;			
		}
		a=b=false;
		cout<<endl;		
		cout<<" Начальная динамическая матрица A1:"<<endl;		
		for(i=0;i<m;i++)
		{
			cout<<" ";
			for(j=0;j<n;j++)
			{
				cout<<A1[i][j]<<"\t";
				if((M>0)&&(N==0))
				{
					if(A1[i][j]%L==0)
					{
						if(a==true)
						{
							if (A1[i][j]>=Max)
							{
								i_max=i;
								j_max=j;				
								Max=A1[i][j];
							}
						}
						else 
						{
							a=true;
							i_max2=i_max=i;
							j_max2=j_max=j;
							Max_Min2=Max=A1[i][j];
						}					
						if(b==true)
						{
							if (A1[i][j]<=Min)
							{
								i_min=i;
								j_min=j;
								Min=A1[i][j];
							}
						}
						else if(a==true)
								if(Max_Min2<Max)
								{
									i_min=i_max2;
									j_min=j_max2;
									Min=Max_Min2;
									b=true;
								}			
					}			
				}
				else if((N>0)&&(M==0))
				{
						if(A1[i][j]%L==0)
						{					
							if(b)
							{
								if (A1[i][j]<=Min)
								{
									i_min=i;
									j_min=j;				
									Min=A1[i][j];
								}
							}
							else 
							{
								b=true;
								i_max2=i_min=i;
								j_max2=j_min=j;
								Max_Min2=Min=A1[i][j];
							}					
							if(a)
							{
								if (A1[i][j]>=Max)
								{
									i_max=i;
									j_max=j;
									Max=A1[i][j];
								}
							}
							else if(b)
								if(Max_Min2>Min)
								{
									i_max=i_max2;
									j_max=j_max2;
									Max=Max_Min2;
									a=true;
								}			
						}
			}
			else
						if(A1[i][j]%L==0)
						{					
							if(b)
							{
								if (A1[i][j]<=Min)
								{
									i_min=i;
									j_min=j;				
									Min=A1[i][j];
								}
							}
							else 
							{
								b=true;
								i_min=i;
								j_min=j;
								Min=A1[i][j];
							}					
							if(a)
							{
								if (A1[i][j]>=Max)
								{
									i_max=i;
									j_max=j;				
									Max=A1[i][j];
								}
							}
							else 
							{
								a=true;
								i_max=i;
								j_max=j;
								Max=A1[i][j];
							}		
					}	
			}
			cout<<endl;
		}
		cout<<endl;
		if((a==true)&&(b==true))
		{
			cout<<" Максимальный элемент динамической матрицы A1 равен "<<Max<<" с индексом i="<<i_max<<"\n и индексом j="<<j_max<<endl;
			cout<<" Минимальный элемент динамической матрицы A1 равен "<<Min<<" с индексом i="<<i_min<<"\n и индексом j="<<j_min<<endl;			
			if(i_max!=i_min)
				for(j=0;j<n;j++)
				{
					P=A1[i_max][j];
					A1[i_max][j]=A1[i_min][j];
					A1[i_min][j]=P;			
				}
			else
				for(i=0;i<m;i++)
				{
					P=A1[i][j_max];
					A1[i][j_max]=A1[i][j_min];
					A1[i][j_min]=P;			
				}	
		}
		else
		{
			if((a==true)||(b==true))
			{
				if(b==true)
				{
					Max=Min;
					i_max=i_min;
					j_max=j_min;
				}				
				cout<<" Максимальный элемент динамической матрицы A1 равен "<<Max<<" с индексом i="<<i_max<<"\n и индексом j="<<j_max<<endl;
				cout<<" Минимального элемента динамической матрицы A1, удовлетворяющему\n данному условию, не существует"<<endl;
			}
			else
			{
				cout<<" Максимального элемента динамической матрицы A1, удовлетворяющему\n данному условию, не существует"<<endl;
				cout<<" Минимального элемента динамической матрицы A1, удовлетворяющему\n данному условию, не существует"<<endl;
			}
			for(j=0;j<n;j++)
			{
				P=A1[0][j];
				A1[0][j]=A1[m-1][j];
				A1[m-1][j]=P;			
			}
		}
		cout<<endl;
		cout<<" Новая динамическая матрица A1:"<<endl<<endl;
		for(i=0;i<m;i++)
		{
			cout<<" ";
			for(j=0;j<n;j++)		
				cout<<A1[i][j]<<"\t";
			cout<<endl;			
		}
		cout<<endl;	
		for(i=0;i<m;i++)
			delete[]A1[i];
		delete[]A1;	
	}
	else
		cout<<" Проверьте введенные значения m, n и A!"<<endl<<endl;	
	_getch();
	return 0;
}

