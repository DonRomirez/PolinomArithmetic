#pragma once
#include <iostream>
#include "Monom.h"
using namespace std;
template <typename T>
struct Link {
	T val;
	Link<T>* next;
	Link(T _val = T(), Link* _next = NULL):val(_val), next(_next) {
	}
};
template <class T>
class List {
	Link<T>* pfirst;
	Link<T>* plast;
	int size;
public:

	List() {
		pfirst = new Link<T>;
		pfirst->next = pfirst;
		plast = pfirst;
		size = 0;
	}
	//~List()
	//{
	//	while (pfirst->next != pfirst)
	//	{
	//		Link<T>* t = pfirst->next;
	//		pfirst->next = t->next;
	//		delete t;
	//	}
	//	delete pfirst;
	//}
	//List(const List<T> &l) {
	//	size = l.size;
	//	pfirst = new Link<T>;
	//	Link<T>* t;
	//	t = l.pfirst;
	//	while (t->next != l.pfirst) {
	//		this->addlast(t->next->val);
	//		t=t->next;
	//	}
	//	plast = l.plast;
	//}

	List<T>& operator=(const List<T>& l) {
		if ((pfirst == l.pfirst) && (plast == l.plast) && (size == l.size))
			return *this;
		else size = l.size;
		Link<T>* t;
		t = l.pfirst;
		pfirst = t;
		plast = l.plast;
		return *this;
	}
	int getSize() { return size; }

	void addfirst(T val) {
		Link<T>* p = new Link<T>;
		p->val = val;
		p->next = pfirst->next;
		pfirst->next = p;
		if (p->next == pfirst)
			plast = p;
		size++;
	}
	Link<T>* GetFirst() {
		return pfirst;
	}
	Link<T>* GetLast() {
		return plast;
	}
	bool isEmpty() {
		return pfirst == plast;
	}

	void add(T val, int i) {
		Link<T>* t;
		t = pfirst;
		int j = 0;
		while ((j < i) && (t->next != pfirst)) {
			t = t->next;
			j++;
		}
		Link<T>* p;
		p = new Link<T>;
		p->val = val;
		p->next = t->next;
		t->next = p;
		if (p->next == pfirst)
			plast = p;
		size++;
	}

	void addlast(T val) {
		Link<T>* t;
		t = new Link<T>;
		t->val = val;
		t->next = pfirst;
		plast->next = t;
		plast = t;
		size++;
	}

	void PrintL() {
		Link<T>* t;
		t = pfirst;
		t = t->next;
		while (t != pfirst) {
			cout << t->val << ' ';
			t = t->next;
		}
		cout << endl;
	}

	void delEl(int i) {
		Link<T>* t;
		t = pfirst;
		int j = 0;
		while ((j < i) && (t->next != pfirst)) {
			j++;
			t = t->next;
		}
		Link<T>* p = t->next;
		t->next = t->next->next;
		delete p;
		if (t->next == pfirst) {
			plast = t;
		}
		size--;
	}
	




	//T& operator[](int i)
	//{
	//	int k = 0;
	//	Link<T>* t = pfirst;
	//	while ((t != NULL)&&(k<i))
	//	{
	//		k++;
	//		t = t->next;
	//	}
	//	if (t == NULL) throw - 1;
	//	return t->val;
	//}

};
template <class T>
class Iterator {
	Link<T>* h;
	Link<T>* t;
public:
	Iterator(Link<T>* _h) :h(_h) {
		t = h->next;
	}
	bool hasNext() {
		return t != h;
	}
	T next() {
		if (!hasNext()) throw "NO NEXT";
		T v = t->val;
		t = t->next; 
		return v;
	}

};
