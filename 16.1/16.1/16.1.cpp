// 16.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;


int main()
{
	setlocale(LC_ALL,"russian");
	//SetConsoleCP(1251);
	//SetConsoleOutPutCP(1251);
	//fstream(універсальний)
	//ifstream(читання файлу)
	//ofstream(ввід у файл)
	ofstream fout;
	ifstream fin;
	string path = "g.txt",path2="g2.txt",textn; //textn;
	
	fout.open(path);

	if (!fout.is_open()) {
		cout << "Файл не вдалося вiдкрити";
		return 0;

	}
	else {
		
		//SetConsoleCP(1251);
		cout << "Файл вiдкритий успiшно" << endl;
		cout << "Введiть вашi даннi" << endl;
		//fout << "чикі брикі в дамки";
		SetConsoleCP(1251);
		getline(cin, textn);
		
		fout << textn;
		SetConsoleCP(866);
		
	}
	fout.close();
	fin.close(); 


	fin.open(path);
	if (!fin.is_open()) {
		cout << "Не вдалося скопiювати контент файлу";
	}
	else {
		
		fout.open(path2);
		while (getline(fin,textn)) {//зчитує твій стрінг
			fout << textn << "\n";

		
		
		}
		cout << "Копiювання пройшло успiшно";
	}
	fout.close();
	fin.close();


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
