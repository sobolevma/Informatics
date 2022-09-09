// ���� 1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include "conio.h"
#include <iostream>

class Vehicle { 
const char DefaultVehicleName[]    = "Untyped vehicle"; 
const double DefaultVehicleSpeed = -1.; 

friend void CommitRandomTrips (MyVector<Vehicle *> &vehicles);
public:  
//����������� �� �� ���������  
Vehicle () : totalDistance (0), totalTime (0), baseSpeed (DefaultVehicleSpeed) {   SetName (DefaultVehicleName);  }  
 //���������������� ���������� ��  
Vehicle (const char inNameCString[], double inBaseSpeed, int inBasePrice) : totalDistance (0), totalTime (0), baseSpeed (inBaseSpeed) {   SetName (inNameCString);  }  
 //���������� ��  
virtual ~Vehicle () {  }  
 //����� ��������� ���������� �� ����� ��  
const char * const GetName () const {   return nameCString;  }  
 
 //����� ��������� ���������� � �������� ��� �������  
double GetBaseSpeed () const {   return baseSpeed;  }  
 //����� ��������� ���������� � ������� �������  
double GetTotalDistance () const {   return totalDistance;  }  
 //����� ��������� ���������� � ������� ������� ������������  
double GetTotalTime () const {   return totalTime;  }  
 //����������� ����� ���������� �������  //���������� �� true, ���� ������ ������ � false, ���� ��������� ������.  
virtual bool MakeTrip (double distance) = 0;  
 //����������� ����� ��������� ���������� � ������� ��������  
virtual double GetSpeed () const = 0;  
 //�������� ��������� �� ���������  
bool operator< (Vehicle &rhs) const {   if (GetSpeed () < rhs.GetSpeed ()) {    return true;   }   return false;  }  
 //��������� - ����� ������������ ���������� �������� � ����� ��  
static const int MAX_NAME_LENGTH = 50;  
protected:  
	//������� ����������� ����������  
	double totalDistance; 
	//������� ������ ������� ������������  
	double totalTime;   
private:  //����� ��������� ����� ������������� ��������  
	void SetName (const char inNameCString[]) {   int i = 0;   for (i = 0; (inNameCString[i] != 0) && (i < MAX_NAME_LENGTH); ++i) 
	{    nameCString [i] = inNameCString [i];   }   nameCString [i] = 0;  }  
 //� - ������ ��� �������� �����  
	char nameCString [MAX_NAME_LENGTH];    
	//�������� ������ ������������� ��������  
	double baseSpeed;   };

template <class MyType> 
void MySwap (MyType &v1, MyType &v2) 
{   
	MyType v3 = v1;  
	v1 = v2;  
	v2 = v3; 
}  
template <class ArrayType, class LessFunctionType> 
int FindMinimumIndex (ArrayType &data_array, int beginIndex, int endIndex, LessFunctionType LessFunction) 
{  
	int minimumIndex = beginIndex;  
	for (int element_number = beginIndex + 1; element_number <= endIndex; ++element_number) 
	{   
		if (LessFunction (data_array[element_number], data_array[minimumIndex])) 
		    minimumIndex = element_number;   

	}  
	return minimumIndex; 
}   
template <class ArrayType, class LessFunctionType> 
void SelectionSort (ArrayType &data_array, int beginIndex, int endIndex, LessFunctionType LessFunction) 
{  
	for (int element_number = beginIndex; element_number < endIndex; ++element_number) 
	{   
		int minimumIndex = FindMinimumIndex (data_array, element_number, endIndex, LessFunction);   
		MySwap (data_array[minimumIndex], data_array[element_number]); 
	} 
} 
void CommitRandomTrips (const MyVector<Vehicle *> &vehicles)
{   
	for (int i = 0; i < vehicles.Length (); ++i) 
	{    
		double randomDistance = double(rand() % 20001) / 10.;    
		vehicles[i]->MakeTrip (randomDistance);   
	} 
}

void DisplayVehicles (const MyVector<Vehicle *> &vehicles) 
{  
	printf("%s     \t%s\t%s\t%s\n", "Name", "Speed", "Dist", "Time");  
	for (int i = 0; i < vehicles.Length (); ++i) 
	{ 
	printf("%s \t%6.2lf\t%7.2lf\t%6.2lf\n", vehicles[i]->GetName(), vehicles[i]->GetSpeed (),  vehicles[i]->GetTotalDistance (), vehicles[i]->GetTotalTime ());  
	} 
}  
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	
	srand(0);
	getch();
	return 0;
}

