// diskret 3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <math.h>
#include<Windows.h>
using namespace std;

int fact(int n)
{
	int factorial = 1;
	for (int i = 1; i <= n; i++) {
		factorial *= i;
	}
	return(factorial);
}
long long d(int s1, int s2) {
	long long sum = 0;
	for (int i = s1; i <= s2; i++) {
		sum *= i;

	
	
	}
	return(sum);

}
                       
float C(int k,int n)//-сполучення      
{                      
	float x = 0;
	x = fact(n) / (fact(k)*fact(n - k));
	return(x);
}

float P(int n, int n1, int n2, int n3)
{
	float x = 0;
	x = fact(n) / (fact(n1)*fact(n2)*fact(n3));
	return(x);

}

void Binom(int a,int b,int n)//n=5 
{
	if (b < 0) {
		cout << "(" << a << "x" << b << "y)^" << n << " = ";
	}
	else { cout << "(" << a << "x+" << b << "y)^" << n << " = "; }
	//cout << "(" << a << "x+(" << b << "y)^" << n << '=';
	for (int i = 0; i <= n; i++) {
		if (i == 0) {
			cout <<"("<< C(i, n)*pow(a, n-i) << "x^"<<n-i<<") + ";
		
		
		}
		else if ((n-i)==0)
		{
			cout <<"("<< C(i, n)*pow(a, n - i)*pow(b, i)<< "y^" << i << ") \n ";
		}
		else {
			cout <<"("<< C(i, n)*pow(a, n-i)*pow(b, i) << "x^"<<n-i<<'*'<<"y^"<<i<<") + " ;
		}
		
	
	
	}



}


void KofB(int a,int b,int n,int j) {//a, b- коефіціенти n-степінь

	int x = C(j, (j + (n - j)))*pow(a, j)*pow(b, (n - j));
	cout << x << "x^" << j <<"*"<< "y^" << n - j << "\n";


}

void KofP(int a,int b,int c,int n,int i,int j,int k) 
{
	cout<<P(n, i, j, k)*pow(a, i)*pow(b, j)*pow(c, k) << "x^" << i << "*" << "y^" << j <<"*z^"<<k<< "\n";





}

void Poly(int a, int b, int c, int n) 
{
	int u = 1;



	for (int i = 0; i <= n; i++) 
	{ 
		for (int j = 0; j <= n; j++)
		{
			for (int k = 0; k <= n; k++)
			{
				if (i + j + k == n) {

					//cout << u << ".|" << i << "|" << j << "|" << k << endl;
					//u++;
					if (i == 0 && j != 0 && k != 0) {
						cout <<"("<< P(n, i, j, k)*pow(a, i)*pow(b, j)*pow(c, k)<< "y^" << j << "*z^" << k << ") + ";
					}
					else if (j == 0 && i != 0 && k != 0) {
						cout <<"("<< P(n, i, j, k)*pow(a, i)*pow(b, j)*pow(c, k) << "x^" << i << "*z^" << k << ") + ";
					}
					else if (k == 0 && j != 0 && i != 0) {
						cout <<"("<< P(n, i, j, k)*pow(a, i)*pow(b, j)*pow(c, k) << "x^" << i << "*y^" << j << ") + ";
					}
					else if (i == 0 && j == 0 && k != 0) {
						cout <<"("<< P(n, i, j, k)*pow(a, i)*pow(b, j)*pow(c, k)<< "z^" << k << ") + ";
					}
					else if (i == 0 && j != 0 && k == 0) {
						cout <<"("<< P(n, i, j, k)*pow(a, i)*pow(b, j)*pow(c, k) << "y^" << j << ") + ";
					}
					else if (i != 0 && j == 0 && k == 0) {
						cout <<"("<< P(n, i, j, k)*pow(a, i)*pow(b, j)*pow(c, k) << "x^" << i << ")\n";
					}
					else 
					{
						cout <<"("<< P(n, i, j, k)*pow(a, i)*pow(b, j)*pow(c, k) << "x^" << i << "*y^" << j << "*z^" << k << ") + ";
					}
				}
				
			}
		}
	}




}


int main()
{
	
	//cout << fact(k-n);
	//(2x+3y)^3
	//Binom(-2, 1, 7);
	int z = 0.333;
	cout << d(981,1000);
	//KofB(2, -3, 7, 2);
	//Poly(1, 1, -1, 5);
	//KofP(1, 1, -1, 5, 1, 0, 4);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging men7

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
