// лаба 3 многочлени.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <math.h>
#include <string>
#include <Windows.h>
using namespace std;

class polynom {
	int *pol, *g, *c;
public:
	polynom() {
		pol = new int[7]{};//-11,1,5,5
		g = new int[7]{0,0,0,0,0};
		c = new int[7];//temporary
		
	}
	polynom(char x){
		this->pol = new int[7]{45,114,71,-20,-21,2,1};
		this->g = new int[7]{ 0,0,0,0,0,0,0};
		this->c = new int[7];//temporary
		fpol(pol, 7);
		kor();
	}

	void writep() {
		for (int i = 6; i >= 0; i--) {
			cout << "Введіть коеф." << i << "- степення ";
			cin >> pol[i];
			cout << endl;
			
		}
		fpol(pol, 7);
	}
	void fpol() {
		cout << "(";
		for (int i = 6; i >= 0; i--) {
			if (i == 0 && g[i] < 0) {
				cout << g[i];
			}
			else if (g[i] == 0) {
				cout << "";
			}
			else if (i == 0 && g[i] > 0) {
				cout << "+" << g[i];
			}
			else if (g[i] > 0 && i != 1 && i != 0) {
				cout << "+" << g[i] << "x^" << i;
			}
			else if (g[i] < 0 && i != 1 && i != 0) {
				cout << g[i] << "x^" << i;
			}
			else if (i == 1 && g[i] > 0) {
				cout << "+" << g[i] << "x";
			}
			else if (i == 1 && g[i] < 0) {
				cout << g[i] << "x";
			}
		}
		cout << ")";
	}
	void fpol(int arr[], int size) {
		
		cout << "(";
		for (int i = size - 1; i >= 0; i--) {

			if (i == 0 && arr[i] < 0) {
				cout << arr[i];
			}
			else if (arr[i] == 0) {
				cout << "";
			}
			else if (i == 0 && arr[i] > 0) {
				cout << "+" << arr[i];
			}
			else if (arr[i] > 0 && i != 1 && i != 0) {
				cout << "+" << arr[i] << "x^" << i;
			}
			else if (arr[i] < 0 && i != 1 && i != 0) {
				cout << arr[i] << "x^" << i;
			}
			else if (i == 1 && arr[i] > 0) {
				cout << "+" << arr[i] << "x";
			}
			else if (i == 1 && arr[i] < 0) {
				cout << arr[i] << "x";
			}
		}
		cout << ")";
		cout << endl;
	}
	void kor(){
		float x=0;
		int *ptr = &pol[0], h = 1;
		cout << "Введіть ваш корінь ";
		cin >> h;
		for (int i = 6; i >= 0; i--) {
			if (pol[i] == 0) {
				c[i] = 0;
			}
			if (i == 6) {
				c[i] = pol[i];
				
			}
			else{ c[i] = (h*c[i+1]) + pol[i]; }

		}
		for (int k=5, i = 6;k >= 0, i >= 1;k--, i--) {
			g[k] = c[i];
		}
		if (h > 0) {
			cout << "(x-" << h << ")";
		}
		else if (h < 0) {
			cout << "(x+" << -1 * h << ")";
		}
		for (int i = 0; i <= 6; i++) {
			if (i == 0) {
				x += *ptr;
			}
			else { x += pol[i] * pow(h, i); }
		}
		fpol();
		if (x >= 0) {
			cout << "+" << x<<endl;
		}
		else { cout << x+1<<endl; }
	}

	
	~polynom() {
			delete[]pol;
			delete[]g;
			delete[]c;
	}
};
	

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	polynom kek;
	kek.writep();
	kek.kor();
	polynom rek('g');
	
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
