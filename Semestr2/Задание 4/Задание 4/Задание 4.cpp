// Задание 4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "conio.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <sstream>
 using namespace std;
#define N 255
 int i,R,K=0,T=0,j=0;
  double Massiv[255];
 bool v=false;
 struct Polucheno{
char name[255] ;
} arr[N] ;
 class File_open_error{};
 class Perepolnenie_bufera{};
 class Previshena_razmernost{};
 class Nedopustimiy_simbol{};
 class Lishniy_znak{};
 class Dve_zapiatie{};
 class Net_podhod_chisel{};
 class Ne_sozdan_fail{};
 class File_write_error{};
 class Maliy_T{};

 void file_sent()
 {
	if(v==true)
	{
		ofstream MyFile2("F:\\Практика по информатике в Бауманке Лабы\\К лабе 4\\Файл 4_2.txt");
		if(MyFile2==false) throw File_write_error();
		MyFile2<<"Числа расположенные между наибольшим и наименьшим:"<<endl;
		double Max=Massiv[0];
		double Min;
		bool est=false;	
		if(T>2)
		{
			for(int i=0;i<T;i++)	
			 if((Massiv[i]>Max)&&(est==false))
				{
					Min=Max;
					Max=Massiv[i];
					est=true;
				}
			 else if((Massiv[i]<Max)&&(est==false))
				{
					Min=Massiv[i];
					est=true;
				}
			 else if(est)
				{
					if(Massiv[i]>Max)
						Max=Massiv[i];
					if(Massiv[i]<Min)
						Min=Massiv[i];			
				}		
		 if(est)
			{
				for(int i=0;i<T;i++)							
					if((Massiv[i]>Min)||(Massiv[i]<Max))
						MyFile2<<Massiv[i]<<endl;
				cout<<"Выполнена успешная пердача данных в файл!"<<endl;
			}
		else throw Net_podhod_chisel();
		}
		else throw Maliy_T();
		MyFile2.close(); 
	 }
	else throw Ne_sozdan_fail();
 } 
 
 
 void file_open()
{	
	ifstream MyFile1("F:\\Практика по информатике в Бауманке Лабы\\К лабе 4\\Файл 4_1.txt",ios::in);	
	if(MyFile1==false) throw File_open_error();	
	R=-1;
	i=0;		
	bool a=false;
	while(!MyFile1.eof())
	{	
		if(j>N) 
		{
			MyFile1.close();
			throw  Previshena_razmernost();
		}
		char symbol=MyFile1.get();		
		if((symbol!='\n')&&(symbol!='я'))
		{	
		
		 if(j>R)
		 {
			  if(i>255)
			{
				MyFile1.close();				
				a=false;				
				R=j;
				throw  Perepolnenie_bufera();
			} 
		arr[j].name[i]=symbol; 	
		i++; 
		a=true;
		 }
		}
		else						
		{
			if(j>R&&a)
			{
				R=j;				
				i=0;
				j++;
				a=false;
				}
	
		}
	}
	MyFile1.close();
}

bool Vizov1()
{
try {  
		 file_open(); 
 }
	catch (File_open_error) 
	{    
		cout << "Ошибка открытия исходного файла на чтение!!!" << endl;
		cout << "Программа завершает свою работу!!!!!!!!!!" << endl;
		exit(1); 
	} 
	catch ( Perepolnenie_bufera)
	{
		cout << "Непоместившиеси символы считываемой строки будут отброшены!!!" << endl;
		cout << "Будет осуществлено повторное чтение исходного файла!" << endl;
		return false;
	}
	catch (Previshena_razmernost)
	{
		cout << "Число записей превышает "<<N<<'.'<<endl;
		cout << "Лишние записи будут отброшены!!!" << endl;
		return true;
	}
	return true;
}
bool Sravnenie(char k)
{
if((k=='+')||(k=='-')||(k=='.')||(k==',')||(k=='0')||(k=='1')||(k=='2')||(k=='3')||(k=='4')||(k=='5')||(k=='6')||(k=='7')||(k=='8')||(k=='9'))
return true;
else return false;
}

bool Podpoisk(char k)
{
if((k=='.')||(k==',')||(k=='0')||(k=='1')||(k=='2')||(k=='3')||(k=='4')||(k=='5')||(k=='6')||(k=='7')||(k=='8')||(k=='9'))
return true;
else return false;
}

void Obrabotka()
{
	for(K;K<=R;K++)
	{
		int j=0,m=0;
		bool vstretilsia=false;
		char znak,chislo[255];
		memset(chislo,0,sizeof(chislo));
		znak='+';
		int v=strlen(arr[K].name);
		cout<<v;
		while(j<v)
		{
			if(arr[K].name[j]==' ') j++;
			else
			{
			bool a=Sravnenie(arr[K].name[j]);			
			if (a)
			{
				if(arr[K].name[j]=='-'&&!(arr[K].name[j-1]>='0'&&arr[K].name[j-1]<='9')&& vstretilsia==false) 
				{
					vstretilsia=true;
					znak=arr[K].name[j];
				}
				else if(arr[K].name[j]=='+'&&!(arr[K].name[j-1]>='0'&&arr[K].name[j-1]<='9')&& vstretilsia==false) 
				{
					vstretilsia=true; 					
				}
				else if((arr[K].name[j]=='+'||arr[K].name[j]=='-')&&(vstretilsia||arr[K].name[j-1]>='0'&&arr[K].name[j-1]<='9')) throw Lishniy_znak();
				bool b=Podpoisk(arr[K].name[j]);
				if(b) 
				{
				chislo[m]=arr[K].name[j];
				m++;
				}
			}
			else throw Nedopustimiy_simbol();
			
			if(j==v-1)
			{
			if(chislo[0]=='.'||chislo[0]==',') throw Dve_zapiatie();
			int Y1;
			bool vstrettzp=false;
			for(int i=0;i<m;i++)
			{
				Y1=i;
				if((chislo[i]=='.')&&(vstrettzp==false)&&(i>0))
				{
					chislo[i]=',';
					vstrettzp=true;
				}
				else if((chislo[i]==',')&&(vstrettzp==false)&&(i>0)) vstrettzp=true;
				else if((chislo[i]==','||chislo[i]=='.')&&(vstrettzp==true)) throw Dve_zapiatie();		
			}
			if(Y1==m-1) 
			{
				if(znak=='+')
				Massiv[T]=atof(chislo);
				else Massiv[T]=-atof(chislo);								
				cout << "Строка успешно передана далее!" << endl<<endl;
				T++;				
			}
			}
			j++;	
		}
	}		
	}
if(T>0)v=true;

}

  bool Vizov2() 
 {
 try {     
	 Obrabotka(); 
 }
 catch (Nedopustimiy_simbol) 
 {
	cout << "В записи строки есть недопустимый в числе символ!!!"<<endl;
	cout << "Строка будет проигнорирована!!!" << endl<<endl;
	K++;
	return false;	
 }
 catch (Lishniy_znak) 
 {
	cout << "В записи числа не может быть нескольео знаков + или - !!!"<<endl;
	cout << "Строка будет проигнорирована!!!" << endl<<endl;
	K++;
	return false;	
 }
  catch (Dve_zapiatie) 
 {
	cout << "Число не может начинаться с . или , и внутри числа не может быть несколько знаков . или ,"<<endl;
	cout << "Строка будет проигнорирована!!!" << endl<<endl;
	K++;
	return false;	
 }
 
 return true;
 }
 
bool Vizov3()
{
	try {     
	 file_sent(); 
	}
	catch (File_write_error) 
	{    
		cout << "Ошибка открытия файла назначения на запись!!!" << endl;
		cout << "Программа завершает свою работу!!!!!!!!!!" << endl<<endl;
		exit(1); 
	}
	catch (Net_podhod_chisel) 
	{    
		cout << "Все числа равны "<<Massiv[T]<<" и их не получится записать в файл!" << endl<<endl;
		return true;
	}
	 catch (Ne_sozdan_fail) 
	{    
		cout << "Файл на запись не надо создавать, так как не был заполнен массив!!!" << endl<<endl;
		return true;
	}
	 catch (Maliy_T) 
	{    
		cout << "Длина массива меньше 2!!!" << endl<<endl;
		return true;
	}
	
	return true;
}

int _tmain(int argc, _TCHAR* argv[])
{	
	setlocale(LC_ALL,"Russian");
	bool a=Vizov1();
	while (a==false)
		a=Vizov1();	
	bool b=Vizov2();
	while(b==false)
		b=Vizov2();	
	Vizov3();
	_getch();	
	return 0;
}

