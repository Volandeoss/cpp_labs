

#include "pch.h"
#include <locale>
#include <iostream>
using namespace std;


const int  n = 5;


struct people {
	char sur[20], adr[20];
	int bir, sal;
	char sex;
	char marr[4];
	union {
		char war[4];
		int kid;
	};
}man[n];

int main()
{
	
	
	setlocale(LC_ALL, "ukr");
	strcpy_s(man[0].sur, "I������ �.�.");
	strcpy_s(man[1].sur, "�������� I.�.");
	strcpy_s(man[2].sur, "���� �.�.");
	strcpy_s(man[3].sur, "������� �.I.");
	strcpy_s(man[4].sur, "�������� �.M.");

	strcpy_s(man[0].adr, "��������� 35�");
	strcpy_s(man[1].adr, "������� 3");
	strcpy_s(man[2].adr, "��������� 7");
	strcpy_s(man[3].adr, "�������� 5");
	strcpy_s(man[4].adr, "����������� 57");
	for (int i = 0; i < n; i++) {
		cout << man[i].sur << " ������ �����(b/g)" << endl;
		cin >> man[i].sex;
		cout << "������ �� ����������:" << endl;
		cin >> man[i].bir;
		//cout << man[i].sur << "������ ���� ������:" << endl;
		//cin >> man[i].adr;
		cout << man[i].sur << "������ �������� �����:" << endl;
		cin >> man[i].sal;
		if (man[i].sex == 'b') {
			cout << "�� ��������-�����'������?  (yes/no) " << endl;
			cin>>man[i].war;
		}
		else {
			cout << "�� ������?  (yes/no) " << endl;
			cin>>man[i].marr;
			if (man[i].marr[0] == 'n') {
				man[i].kid = 0;
			        

			}
			if (man[i].marr[0] == 'y'){
				cout << "ʳ������ ����:" << endl;
				cin >> man[i].kid;
				
			}
		}
	}
	//cout << man[i].sur << "\t" << man[i].sex << "\t" << man[i].bir << "\t" << man[i].adr << "\t" << man[i].sal << "\t" << man[i].war << "\t" << man[i].marr << "\t" << man[i].kid << "\n";
	cout << "�������    �����    г� ����������     �������             �������� �����    ³�������-���������    ������    ĳ��" << endl;
	for (int i = 0; i < n; i++) {
		if (man[i].sex == 'b') {
			cout << man[i].sur << "\t" << man[i].sex << "\t" << man[i].bir << "\t         " << man[i].adr << "\t       " << man[i].sal << "\t                  " << man[i].war  << "\n";
		}
		else {
			cout << man[i].sur << "\t" << man[i].sex << "\t" << man[i].bir << "\t         " << man[i].adr << "\t       " << man[i].sal << "\t" << "                           " << "\t" << man[i].marr << "\t" << man[i].kid << "\n";
		}
		//cout << man[i].sur << "\t" << man[i].sex << "\t" << man[i].bir << "\t" << man[i].adr << "\t" << man[i].sal << "\t" << "   "<< "\t" << man[i].marr << "\t" << man[i].kid << "\n";
	}
	int c = 0;
	for (int i = 0; i < n; i++) {
		if (man[i].sex == 'g') {
			c += man[i].sal;
		}
		
	}
	for (int i = 0; i < n; i++) {
		if (man[i].sex=='b' && man[i].sal < c) {
			cout << "��������" << man[i].sur << "�� �������� ������� �������� ����� ����"<<endl;
		}
		
	}
	return 0;
}


