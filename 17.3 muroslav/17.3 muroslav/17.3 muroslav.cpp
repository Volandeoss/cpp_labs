// 17.3 muroslav.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string.h>
#include <Windows.h>
#include <ctime>
using namespace std;

template<typename T>
class list {
public:
	list() {
		size = 0;
		head = nullptr;
	}
	~list() {
		cout << "видалення елементів з списку",
			clear(),
			cout << endl << "елементів в списку  " << GetSize() << endl;
	}
	void pop_front() {//функція яка видаляє перший елемент у однонапрямленому списку
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
		while (size) {//якщо більше або менше нуля то тру, якщо нуль то фалс 
			pop_front();
		}
	}
	int GetSize() { return size; }

	T& operator[](const int index) {//& - щоб міняти та повертати (адрес)
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



int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	list<int> L;
	cout << "Введіть цифри для однозв'язного списку:\n";
	for (int i = 0; i < 5; i++) {
		int c;
		cout << i + 1 << "-е число ";
		cin >> c;
		L.push_back(c);
	}
	
	L.pop_front();
	cout << "Елементи списку після видалення першого елементу\n";
	for (int i = 0; i < L.GetSize(); i++) {
		
		cout << i + 1 << "-е число: "<<L[i]<<endl;
		
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
