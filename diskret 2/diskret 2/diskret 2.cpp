// diskret 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <ctime>
#include <Windows.h>
using namespace std;


const int N = 15;
int A[N], B[N], C[N], Objed[N],S[N*2], ObjedC[N*3];


void ObjC(int C[]) 
{
	bool isMatch;
	int k = 0,n=0;
	for (int i = 0; i < N*2; i++)
	{
		n = 0;
		for (int j = 0; j < N; j++)
		{
			if (S[i] == C[j])
			{
				n++;
				
			}
		}
		if (n == 0 && S[i] != 0) {
			ObjedC[k] = S[i];
			k++;
		}
	}

	for (int i = 0; i < N; i++) {
		n = 0;
		for (int j = 0; j < N * 2; j++) {

			if (C[i] == S[j]) {
				n++;
			
			
			}
		}
		if (n == 0 && C[i] != 0) {
			ObjedC[k] = C[i];
			k++;
		}
	}
}

void Obj(int H[],int B[]) {//об'єднання
	int k = 0;
	for (int i = 0; i <N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (H[i] == B[j]) 
			{
				
				Objed[k] = H[i];
				k++;
			}
		
		}
	}
}


void SYM(int A[], int B[])
{
	int k = 0;
	
	Obj(A, B);
	
	for (int i = 0; i < N; i++) 
	{
		bool isMatch = false, isMatch1 = false;
		for (int j = 0; j < N; j++) 
		{
			if (A[i] == Objed[j]) {
				isMatch = true;
			}
			if (B[i] == Objed[j])
			{
				isMatch1 = true;
			}
		}

		if (!isMatch) {
			S[k] = A[i];
			k++;
		}
		if (!isMatch1) {
			S[k] = B[i];
			k++;
		}
	}
}


void Inout(){
	srand(time(NULL));
	for (int i = 0; i < N; i++) 
	{
		A[i] = rand() % 50 + 1;
		B[i] = rand() % 50 + 1;
		C[i] = rand() % 50 + 1;
	}

	for (int i = 0; i < N; i++) //перевірка на повторюваність
	{
		
		for (int j = 0; j < N; j++)
		{
			if (i == j) {
				j++;
			}
			if (A[i] == A[j]) {
				A[i] =(i+1) * 10;
			}
			if (B[i] == B[j]) {
				B[i] = (i+1) * 10;
			}
			if (C[i] == C[j]) {
				C[i] = (i+1) * 10;
			}
		}
	}
	//Obj(A, B);
	SYM(A, B);
	ObjC(C);
	cout << "Множина А:\tМножина B:\tМножина C:\tA U B:\t\tA ^ B:\t\t( А ^ В) U С:"<<endl;
	for (int i = 0; i < N; i++)
	{
		if (Objed[i] == 0&& ObjedC[i]!=0)
		{
			
			
			
			cout << A[i] << "\t\t" << B[i] << "\t\t" << C[i] << "\t\t\t\t" << S[i] << "\t\t" << ObjedC[i] << endl;
		}
		else if (Objed[i] == 0 && ObjedC[i] == 0) {
			cout << A[i] << "\t\t" << B[i] << "\t\t" << C[i] << "\t\t\t\t" << S[i] << endl;
		
		
		}
		else
		{
			cout << A[i] << "\t\t" << B[i] << "\t\t" << C[i] << "\t\t" << Objed[i]<<"\t\t"<<S[i]<<"\t\t"<<ObjedC[i]<< endl;
		
		}

	}
	for (int i = N; i < N * 3; i++) 
	{
		if (S[i] != 0 && ObjedC[i] != 0 && i != (N*2)) {
			cout << "\t\t\t\t\t\t\t\t" << S[i] << "\t\t" << ObjedC[i] << endl;
		}
		else if (i != (N * 2) && S[i] == 0 && ObjedC[i] != 0)
		{
			cout << "\t\t\t\t\t\t\t\t\t\t" << ObjedC[i] << endl;
		
		}
		if (i >= N * 2 &&ObjedC[i]!=0) {
			cout<<"\t\t\t\t\t\t\t\t\t\t"<< ObjedC[i] << endl;
		
		}
	
	}
	

	
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string ymova="\nНаша умова: ( А ^ В) U С\n";
	
	Inout();

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
