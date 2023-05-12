

#include "pch.h"
#include <iostream>
#include<string.h>
#include<Windows.h>

using namespace std;

const int n = 6;

template<typename T>
class list {
public:
	list() {
		size = 0;
		head = nullptr;
	}
	~list() {
		cout << "��������� �������� � ������",
			clear(),
			cout << endl << "�������� � ������  " << GetSize() << endl;
	}
	void pop_front() {
		node<T>*temp = head;
		head = head->pnext;
		delete temp;
		size--;
	}
	void push_back(T data)
	{
		if (head == nullptr) {
			head = new node<T>(data);
		}
		else {
			node<T> *current = this->head;
			while (current->pnext != nullptr) {
				current = current->pnext;

			}
			current->pnext = new node<T>(data);
		}
		size++;
	}
	void clear() {
		while (size) {//���� ����� ��� ����� ���� �� ���, ���� ���� �� ���� 
			pop_front();
		}
	}
	int GetSize() { return size; }

	T& operator[](const int index) {//& - ��� ����� �� ��������� (�����)
		int counter = 0;
		node<T> *current = this->head;
		while (current != nullptr) {
			if (counter == index) {
				return current->data;
			}
			current = current->pnext;
			counter++;
		}
	}

private:
	template<typename T>
	class node {
	public:
		node *pnext;
		T data;
		node(T data = T(), node *pnext = nullptr) {
			this->data = data;
			this->pnext = pnext;
		}
	};

	node<T> *head;
	int size;
};

struct pupil {
	
	char name[20];
	int mat=rand() % 3 + 3;
	int fiz = rand() % 3 + 3;
	int mova = rand() % 3 + 3;
	int lit = rand() % 3 + 3;
	int poz = 0;
}st[n];


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	
	strcpy_s(st[0].name, "������ �.�.");
	strcpy_s(st[1].name, "������ �.�.");
	strcpy_s(st[2].name, "���� �.�.");
	strcpy_s(st[3].name, "����� �.I.");
	strcpy_s(st[4].name, "������ �.�.");
	strcpy_s(st[5].name, "������ �.I.");

	list <pupil> studentlist;
	for (int i = 0; i < n; i++)
	{
		studentlist.push_back(st[i]);
	}

	cout << "�" << " "
		<< "��i�����" << "\t"
		<< "����������" << "\t    "
		<< "�i����" << "\t      "
		<< "����" << "\t  "
		<< "�i��������" <<endl;
	for (int i = 0; i < n; i++) {
		pupil student = studentlist[i];
		if (student.mat > 3) student.poz++;
		if (student.fiz > 3) student.poz++;
		if (student.mova > 3) student.poz++;
		if (student.lit > 3) student.poz++;
		cout << i + 1 << " " << student.name << "\t\t" << student.mat << "\t\t" << student.fiz << "\t\t" << student.mova << "\t\t" << student.lit  << "\n";
	}
	cout << "\n�������� � ���� �������� ���� � ��� ��������:\n";
	for (int i = 0; i < n; i++) {
		pupil student = studentlist[i];
		if (student.mat > 3) student.poz++;
		if (student.fiz > 3) student.poz++;
		if (student.mova > 3) student.poz++;
		if (student.lit > 3) student.poz++;
		if (student.poz == 4) {
			cout << student.name << endl;
		}
		
	}
	
	

	

	
}

