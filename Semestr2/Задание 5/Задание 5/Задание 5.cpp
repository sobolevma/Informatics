// Задание 5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "conio.h"
#include "math.h"
#include <iostream>

using namespace std;
int A,B=0;
double Y0=0,Y1=0;
bool e=false;

struct Mnogoch{
double znach;
int pokaz;
Mnogoch *next;  
};

struct ProizvMnogoch{
double znach_pr;
int pokaz_pr;
ProizvMnogoch *next_pr;  
};

void Znachenie_v_tochke(ProizvMnogoch *head_1,double X)
{
	if(head_1!=NULL)
		{
			Y1+=(head_1->znach_pr)*pow(X,head_1->pokaz_pr);			
			Znachenie_v_tochke(head_1->next_pr,X);
		}
}

void Show_MY_Mnogoch1(  ProizvMnogoch *head_1)
{
   		if(head_1!=NULL)
		{						
			if(head_1->pokaz_pr==0)
				cout<<head_1->znach_pr;	
			else if(head_1->pokaz_pr==1)
				{	
					if(head_1->znach_pr<0)
						cout<<head_1->znach_pr<<"*x";	
					else
						cout<<"+"<<head_1->znach_pr<<"*x";	

					}
				else if(head_1->pokaz_pr>1)
				{	
					if(head_1->znach_pr<0)
						cout<<head_1->znach_pr<<"*x^"<<head_1->pokaz_pr;
					else
					 cout<<'+'<<head_1->znach_pr<<"*x^"<<head_1->pokaz_pr;
				}
			Show_MY_Mnogoch1(head_1->next_pr);
		}
		else
		cout<<'\n';   
}

void My_Proizvod_Mnogoch( int n, ProizvMnogoch **head_1,Mnogoch *head)
{
	 if(n>0)
		{			
			(*head_1) =new ProizvMnogoch();		
			if((head->znach!=0)&&((head)->pokaz>0))
			{				
					(*head_1)->znach_pr=(head)->znach*(head)->pokaz;					
					(*head_1)->pokaz_pr=(head)->pokaz-1;					
					(*head_1)->next_pr=NULL;				
					My_Proizvod_Mnogoch	(n-1,&((*head_1)->next_pr),head->next);
			}
			else				
				My_Proizvod_Mnogoch (n-1,&(*head_1),head->next);
			
	 }	 
}


void Znachenie_v_tochke(Mnogoch *head,double X)
{
	if(head!=NULL)
		{
			Y0+=(head->znach)*pow(X,head->pokaz);			
			Znachenie_v_tochke(head->next,X);
		}  		
}



void Znachenie_v_tochke2(Mnogoch *head,double X,double &Y4)
{
	if(head!=NULL)
		{
			Y4+=(head->znach)*pow(X,head->pokaz);			
			Znachenie_v_tochke2(head->next,X,Y4);
		} 
	
}


double Znachenie_v_tochke3(Mnogoch *head,double X)
{
	if(head!=NULL)
		{
			return (head->znach)*pow(X,head->pokaz) + Znachenie_v_tochke3(head->next,X);
		}
	else
		return 0;
	
}

void My_Mnogoch(int n, Mnogoch **head)
{	
	 if(n>0)
		{
			double a;			
			cout<<"Введите значение коэффициента при  X^"<<A-n<<", которое == ";
			cin>>a;
			if(a!=0)
			{
					(*head) =new Mnogoch();
					(*head)->znach=a;
					(*head)->pokaz=A-n;
					(*head)->next=NULL;
					My_Mnogoch	(n-1,&((*head)->next));
					e=true;
					B++;
			}
			else 
						My_Mnogoch (n-1,&(*head));
	 }	 
}

void Show_MY_Mnogoch( Mnogoch *head)
{
   		if(head!=NULL)
		{
			if(head->pokaz==0)				
				cout<<head->znach;
			else if(head->pokaz==1)				
				{	
				if(head->znach<0)
				cout<<head->znach<<"*x";
				else 
				 cout<<'+'<<head->znach<<"*x";
			}
			else 
			{	
				if(head->znach<0)
				cout<<head->znach<<"*x^"<<head->pokaz;
				else 
				 cout<<'+'<<head->znach<<"*x^"<<head->pokaz;
			}
			Show_MY_Mnogoch(head->next);
		}
		else
		cout<<'\n';   
}



int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL,"Russian");
	
	cout<<"Введите размерность многочлена ";
	cin>>A;		
	if(A>0)
	{
		struct Mnogoch *start=NULL;
		My_Mnogoch(A,&start);	
		if(e==true)
		{		
			cout<<endl<<endl;
			cout<<"Задан многочлен:"<<endl;
			cout<<"Y=";
			Show_MY_Mnogoch(start) ;
			cout<<endl;
			cout<<"Введите точку, в которой надо высчитать значение функции Y:  ";
			double X;
			cin>>X;
			cout<<endl;
			double Y5=0;
			Znachenie_v_tochke2(start,X,Y5);
			Znachenie_v_tochke(start,X);
			cout<<Znachenie_v_tochke3(start,X)<<endl;
			cout<<endl<<endl;
			cout<<"Значение функции в точке X равно:  ";
			cout<<"Y0="<<Y0<<endl;
			cout<<"Y5="<<Y5<<endl;
			struct ProizvMnogoch *start_1=NULL;
			My_Proizvod_Mnogoch(B,&start_1,start);
			cout<<endl<<endl;
			cout<<"Задана производная функции:"<<endl;
			cout<<"Y'=";
			Show_MY_Mnogoch1(start_1) ;
			cout<<endl;	
			cout<<endl;
			Znachenie_v_tochke(start_1,X);
			cout<<endl<<endl;
			cout<<"Производная равна:  ";
			cout<<"Y'="<<Y1<<endl<<endl;			
		}
		else
		{
		cout<<"Список пуст, так как все коэффициенты перед x^n равны нулю."<<endl;
		cout<<"Значение функции в любой точке равно "<<0<<", и производная в любой точке равна "<<0<<'.'<<endl;				
		}
	}
	return 0;
}

