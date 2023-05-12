// 14.2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;
#include <math.h>



int main() {
	setlocale(LC_ALL, "ukr");
	/*float** ary = new float*[N];
	for (int i = 0; i < N; i++)
		ary[i] = new float[M];*/
	float** Matr= new float*[3];
	for (int i = 0; i < 3; i++) {
		Matr[i] = new float[4];
	}
	
	int i, j, nomer1, nomer2;
	float s1, k1, s2, k2, s3, k3;

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 4; j++) {
			nomer1 = i + 1;
			nomer2 = j + 1;
			cout << "матриця = [" << nomer1 << "][" << nomer2 << "]= ";
			cin >> Matr[i][j];

		}
	}
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 4; j++) {
			cout << Matr[i][j]<<"   ";
		}
		cout << endl;

	}
	
	s1 = 0;
	s2 = 0;
	s3 = 0;

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 4; j++) {
			if (i == 0) {
				s1 += Matr[i][j];

			}
			if (i == 1) {
				s2 += Matr[i][j];
			}
			if (i == 2) {
				s3 += Matr[i][j];
			}
		}
	}
	k1 = s1 / (i + 1);
	k2 = s2 / (i + 1);
	k3 = s3 / (i + 1);
	cout << "середнє арифметичне 1-го рядка= " << k1 << endl;
	cout << "середнє арифметичне 2-го рядка= " << k2 << endl;
	cout << "середнє арифметичне 3-го рядка= " << k3 << endl;
	for (int i = 0; i < 3; i++) {
		delete[] Matr[i];
	}
	delete[] Matr;
	return 0;
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
