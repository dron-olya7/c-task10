#include "pch.h"
#include <stdlib.h>
#include <iostream>
 


#ifndef __LINKEDLIST_CPP
#define __LINKEDLIST_CPP


// Структура представляющая один узел связанного списка
template <typename T>
struct node {
	T data;
	node<T> *next;
	node(T d, node* n) : data(d), next(n) {};
	~node() {}
};

template<typename T>
class LinkedList
{
private:
	node<T>* first;
public:
	LinkedList()
	{
		this->first = nullptr;
	}
	~LinkedList() {

	}
	// Добавить элемент
	void add(T data) {
		node<T> *n = new node<T>(data, nullptr);
		if (this->first == nullptr) { // Если голова листа не инициализирована
			this->first = n;
			return;
		}

		node<T> *cur = this->first;
		while (cur->next != nullptr) {
			cur = cur->next;
		}
		cur->next = n;
	}

	T get(int idx) {
		if (idx == 0) {
			return this->first->data;
		}

		node<T> *cur = this->first;
		while (idx-- > 0 && cur->next != nullptr) {
			cur = cur->next;
		}

		return cur->data;
	}

	void remove(int idx) {
		if (idx == 0) {
			node<T> *new_head = this->first->next;
			this->first = new_head;
			return;
		}

		node<T> *cur = this->first;
		while (idx-- > 1 && cur->next != nullptr) {
			cur = cur->next;
		}
		node<T> *next_next = cur->next->next;
		cur->next = next_next;
	}

	int length() {
		if (this->first == nullptr) {
			return 0;
		}
		int i = 1;
		node<T> *cur = this->first;
		while (cur->next != nullptr) {
			cur = cur->next;
			i++;
		}
		return i;
	}

};
#endif