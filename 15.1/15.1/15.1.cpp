// 15.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;
#include <string.h>

const int n = 4;

struct pupil {
	char name[20];
	int mat[n]{ 2,3,4,3 }, fiz[n]{ 4,2,3,5 }, mova[n]{ 5,5,4,4 }, lit[n]{ 4,4,3,5 };
}st[n], *sp = &st[0];

int main()
{
	
	int s[n]{ 0,0,0,0 };

	setlocale(LC_ALL, "ukr");

	strcpy_s(st[0].name, "Iванчук С.О.");
	strcpy_s(st[1].name, "Панченко I.А.");
	strcpy_s(st[2].name, "Заєць О.М.");
	strcpy_s(st[3].name, "Кравець З.I.");
	

	cout <<"№"<<" "<< "Прiзвище" <<"\t"<< "Математика"<<"\t    " << "Фiзика"<<"\t      " <<"Мова"<<"\t" << "Лiтература"<<"\t"<<"Позитивнi оц."<<endl;
	for (int i = 0; i < n; i++) {
		if (st[i].mat[i] > 3) s[i]++;
		if (st[i].fiz[i] > 3) s[i]++;
		if (st[i].mova[i] > 3) s[i]++;
		if (st[i].lit[i] > 3) s[i]++;
		cout <<i+1<<" "<< st[i].name << "\t\t" << st[i].mat[i] << "\t\t" << st[i].fiz[i] << "\t\t" << st[i].mova[i] << "\t\t" << st[i].lit[i] << "\t\t" << s[i] << "\n";
	}
	
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
