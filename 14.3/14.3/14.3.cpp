// 14.3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;
#include <math.h>

int main()
{
	setlocale(LC_ALL, "ukr");


	const int n = 4,k=16;
	float*b = new float[k] { 1, 3, 8, 6, 4, 2, 7, 9, 8, 5, 5, 7, 1, 3, 1, 6  };
	float**a = new float*[n];
	for (int i = 0; i < n; i++) {
		a[i] = new float[n];
	}
	

	for (int g = 0, i = 0; g < k, i < n; i++)
		for (int j = 0; j < n; j++, g++)
			a[i][j] = b[g];

	cout << "Наша матриця:" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}

		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				int tran = a[i][j];
				a[i][j] = a[j][i];
				a[j][i] = tran;
			}
		}
		cout << "Матриця де елементи симетричнi головної дiагоналi замiнено один на одного:" << endl;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				cout << a[i][j] << " ";
			cout << endl;
		}
		for (int i = 0; i < n; i++)
			delete[] a[i];
		delete[] a;
		delete[] b;

	
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
