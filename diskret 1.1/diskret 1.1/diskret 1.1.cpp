// diskret 1.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream> 
#include <math.h>
#include <string>
#include<Windows.h>
#include<algorithm>
using namespace std;






void MyTask()
{
	cout << "ћоЇ завданн€:\n";
	cout << " (!a -> !c) ^ (!b V (!c->a))\n";
	cout << "використовуючи закон зам≥ни ≥мпл≥кац≥њ:\n";
	cout << "Ќаша формула:   (a V !с)^(!b V (c V a))\n";
	cout << "\n";
}

int Negativ( int a) {
	int x;
	if (a == 0) {
		x = 1;
	
	}
	else {
		x = 0;
	}
	return(x);
}

int Dis(int a,int b) 
{
	int x;
	if(a==1 && b==1 || a==1 && b==0 || a==0 && b==1)
	{
		x = 1;
	}
	else {
		x = 0;
	}
	return(x);
}

int Kon(int a,int b)
{
	int x;
	if (a == 1 && b == 1) {
		x = 1;
	}
	else
	{
		x = 0;
	}
	return(x);
}

void TruthTable1(int a,int b,int c)
{
	cout << "1.1" << endl;
	int F,count=0;
	MyTask();
	cout << "a\tb\tc\t!c    a V !c\t c V a\t\t!b\t   !b V (c V a)    (a V !с)^(!b V (c V a))\n";
	cout << "" << endl;
	for (int i = 0; i < 2; i++) {

		for (int j = 0; j < 2; j++) {

			for (int t = 0; t < 2; t++) {
				a = i;
				b = j;
				c = t;
				F =  Kon(Dis(Negativ(c), a), Dis(Negativ(b), Dis(c, a)));
				cout << a   << "\t" << b <<  "\t" << c << "\t"<<Negativ(c)<<"\t"<<Dis(Negativ(c),a)<<"\t   "<<Dis(c,a)<<"\t\t "<< Negativ(b)<<"\t       "<<Dis(Negativ(b), Dis(c, a))<<"\t\t\t"<<F<<"\n";
				if(F==1)
				{
					count++;
				
				
				}
				
			}
		}
	}
	if (count > 1 && count < 8) {
		cout << "‘ормула Ї нейтральна та виконувана\n";
	}
	else if (count == 0) {
		cout << "‘ормула Ї протир≥чч€м та не виконуваною\n";
	}
	else if (count == 8)
	{
		cout << "‘ормула Ї тавтолог≥Їю та виконуваною\n";

	}
}

void TruthTable2(int a, int b, int c)
{
	int F, count = 0;
	cout << "1.2\na\tb\tc\tF\n";
	string DKNF="  ",DDNF="  ";
	for (int i = 0; i < 2; i++) {

		for (int j = 0; j < 2; j++) {

			for (int t = 0; t < 2; t++) {
				a = i;
				b = j;
				c = t;
				cout << a << "\t" << b << "\t" << c << "\t";
				cin >> F;
				if (F == 0) {
					if (a == 1) {
						DKNF.append("(!a V ");
					}
					else {
						DKNF.append("(a V ");
					}
					if (b == 1) {
						DKNF.append("!b V ");
					}
					else {
						DKNF.append("b V ");
					}
					if (c == 1) {
						DKNF.append("!c)");
					}
					else {
						DKNF.append("c)");
					}
					DKNF.append("^");
				}
				else if(F == 1)
				{
					count++;
					if (a == 1) {
						DDNF.append("(a ^ ");
					}
					else {
						DDNF.append("(!a ^ ");
					}
					if (b == 1) {
						DDNF.append("b ^ ");
					}
					else {
						DDNF.append("!b ^ ");
					}
					if (c == 1) {
						DDNF.append("c)");
					}
					else {
						DDNF.append("!c)");
					}
					DDNF.append("V");
				
				
				
				}


			}
		}
	}
	if (count > 1 && count < 8) {
		cout << "‘ормула Ї нейтральна та виконувана\n";
	}
	else if (count == 0) {
		cout << "‘ормула Ї протир≥чч€м та не виконуваною\n";
	}
	else if (count == 8)
	{
		cout << "‘ормула Ї тавтолог≥Їю та виконуваною\n";

	}
	DKNF.pop_back();
	DDNF.pop_back();
	cout << "ƒ Ќ‘ функц≥њ:\n";
	cout << DKNF<<"\n";
	cout << "ƒƒЌ‘ функц≥њ:\n";
	cout << DDNF<<"\n";
}

void TruthTable3(int a, int b, int c) {
	string F = " (A+!B)(!A+C)(A+BC)";
	int X;
	cout <<"1.3\n"<< F<<endl;
	F.erase(remove(F.begin(), F.end(), '('), F.end());
	replace(F.begin(), F.end(), '+', 'v');
	replace(F.begin(), F.end(), ')', '^');
	F.pop_back();
	cout <<"формула алгебри висловлень:\n"<< F<<endl;
	cout << "a\tb\tc\tAv!B\t!AvC\tAvBC\tAv!B ^ !AvC^AvBC\n";
	for (int i = 0; i < 2; i++) {

		for (int j = 0; j < 2; j++) {

			for (int t = 0; t < 2; t++) {
				a = i;
				b = j;
				c = t;
				X = Kon(Kon(Dis(a, Negativ(b)), Dis(Negativ(a), c)), Dis(a, Dis(b, c)));
				cout << a << "\t" << b << "\t" << c << "\t"
					<< Dis(a, Negativ(b)) << "\t"
					<< Dis(Negativ(a), c) << "\t"
					<< Dis(a, Dis(b, c))<<"\t\t"
					<<X;
				if (X == 1) {
					cout << " -«≥мкнена\n";
				}
				else {
					cout << " -–оз≥мкнена\n";
				}
			}
		}
	}
	cout << "—хема:\n";
	cout << "       |ЦAЦЦЦ|     |Ц!AЦЦ|     |ЦAЦЦЦ|" << endl;
	cout << "       |     |     |     |     |     |\n";
	cout << "   ЦЦЦЦ       ЦЦЦЦЦ       ЦЦЦЦЦ       ЦЦЦЦЦ"<<endl;
	cout << "       |     |     |     |     |     |" << endl;
	cout << "       |Ц!BЦЦ|     |ЦCЦЦЦ|     |ЦBЦCЦ|" << endl;
}



int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int a=0,b=0,c=0;
	TruthTable3(a, b, c);
}


