// ���� 6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "conio.h"
#include <iostream>

using namespace std;


struct list
{
int x;
int y;
double znach;
struct list *Next,*Prior;
};
struct list *Head, *Current;

struct list2{
double znach;
int x;
list2 *next;  
};




//�������� ���������������� ������ (���������� � �����)
void Make_list(int n,list** Head,
         list* Prior){
  if (n > 0) {
    (*Head) = new list();
     //�������� ������ ��� ����� �������
    cout << "������� �������� ���������� X ";
    cin >> (*Head)->x;
	cout << "������� �������� ���������� Y ";
	cin >> (*Head)->y;
	cout << "������� �������� �������� ������� � ��������� ������������ ";
	cin >> (*Head)->znach;
    //������ �������� ��������������� ����
    (*Head)->Prior = Prior;
    (*Head)->Next=NULL;//��������� ��������� ����
   Make_list(n-1,&((*Head)->Next),(*Head));
  }
  else (*Head) = NULL;
}

//������ ���������������� ������
void Print_List(list* Head) {
  if (Head != NULL) {
    cout << Head->x << "\t";
	cout << Head->y << "\t";
	cout << Head->znach << endl;	
    Print_List(Head->Next);
    //������� � ���������� ��������
  }
  else cout << "\n";
}



									


int R=0;
int Y1=-1;
void My_sum(int n, list2 **head)
{
	if(n>0)
	{
					(*head) =new list2();
					(*head)->znach=0;
					(*head)->x=R;
					R++;
					(*head)->next=NULL;
					My_sum	(n-1,&((*head)->next));
	}
}

void Prov(list* Head,list2 *head) {
  if(head!=NULL)
  {
	if (Head != NULL) 
	{
    if(Head->x!=head->x)
	{	
		Prov(Head->Next,head);		
	}
	if(Head->x==head->x)
	{
		head->znach+=Head->znach;
		Prov(Head->Next,head);
	}     
  }
	
  }
}

void Provn(list* Head,list2 *head) {
  if(head!=NULL)
	 {
		Prov(Head,head);
		 struct list *start=NULL;
	  Provn(start,head->next);
	}  
  }


void Show_MY_list2( list2 *head)
{
   		if(head!=NULL)
		{
			cout<<head->x<<"\t";
			cout<<head->znach<<"\t";
			cout<<endl;
			Show_MY_list2(head->next);
		}
		   
}



int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL,"Russian");
	int X,Y,kolichestvo;
	struct list *start=NULL;
	struct list2 *start1=NULL;
	cout<<"������� ������ �������."<<endl;
	cin>>X;
	cout<<"������� ����� �������."<<endl;
	cin>>Y;
	cout<<"������� ���������� �� ������� ��������� �������."<<endl;
	cin>>kolichestvo;
	if((X>0)&&(Y>0)&&(kolichestvo<=X*Y))
	{
	Make_list(kolichestvo,&start,start);	
	Print_List(start);
	My_sum(X,&start1);
	list* Head;list2 *head;
	head=start1;
	while(head!=NULL)
	{
	Prov(start,head) ;
	head=head->next;
	}
	Show_MY_list2(start1);
	
	}
	else
		cout<<"Build an error!";
	
	getch();
	return 0;
}

