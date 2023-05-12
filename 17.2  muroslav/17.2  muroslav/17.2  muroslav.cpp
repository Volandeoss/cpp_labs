// 17.2  muroslav.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <Windows.h>
#include <string>
#include <queue> 
using namespace std;



void Cherga(queue<char> k) {
	cout << "\nНаша черга:\n";
	while (!k.empty())
	{
		
		cout << k.front()<<endl;
		k.pop();
	}
	cout << endl;

}

void Task(queue<char> k) {
	queue <char> T;
	string x;
	while (!k.empty())
	{
		if (isdigit(k.front()))
		{
			x.push_back(k.front());
		}
		else if (isalpha(k.front())) 
		{
			T.push(k.front());
		}
		k.pop();
	}

	for (int i = 0; i < x.length(); i++) {
		T.push(x[i]);
	
	}
	cout << "Рядок де усі цифри переносяться у кінець рядка\n";
	while (!T.empty())
	{

		cout << T.front();
		T.pop();
	}
	cout << endl;

}




int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	queue <char> g;
	string x;
	

	cout << "Введіть ваш текстовий рядок:\n";
	getline(cin, x);
	for (int i = 0; i < x.length(); i++)
	{
		g.push(x[i]);
	}
	
	Task(g);
	
	
	
}

// Run program: Ctrl + F5 or Debug > Scintart Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
