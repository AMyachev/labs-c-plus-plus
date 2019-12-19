#pragma once
#include <iostream>
template <typename T>  class ciclestack
{	typedef struct Node
	{
		Node* nextnode;
		T info;
		T infoout() {
			return info;
		}
		int a;
	};
private:
	int i;
	Node *first;
public:
	T* get_first() {
		return &(first->info);
	}
	int length;
	T* get_elem(int index) {
		Node *search=first;

		if (index >= length && index < 0) {
			std::cout << "INDEX ERROR";
			
			return NULL;
		}
		for (i = 0; i!=index; i++) {
			search = search->nextnode;
		}
		return &(search->info);
	}
	void push_first(const T &info) {
		
		T newt = info;
		Node *stakan;
		Node *node = new Node();
		if (length == 0) {
		//	last = node;
			first = node;
		}
		node->nextnode = first;
		node->info = info;
		first = node;
		stakan = first;
		for (i = 0; i < length; i++) {
			stakan = stakan->nextnode;
		}
		stakan->nextnode = first;
		//last->nextnode=first;
		length++;
		//std::cout << node.info;
		
	}
	T* pop_first() {
		T firstinfo;
		Node *stakan;
		if (length > 0) {
			firstinfo = first->info;
			first = first->nextnode;
			length--;
			//this->get_elem(length)->nextnode = first;
			stakan = first;
			for (i = 0; i < length; i++) {
				stakan = stakan->nextnode;
			}
			stakan->nextnode = first;
			//last->nextnode = first;
			return &firstinfo;
		}
		else return NULL;
	}
	void deleteelem(int index) {
		Node *predsearch=first;
		Node *search = first;
		if (i == 0) {
			pop_first();
		}
		else {
			if (index >= length && index < 0) {
				std::cout << "INDEX ERROR";
			}
			for (i = 0; i != index; i++) {
				predsearch = search;
				search = search->nextnode;
			}
			length--;
			predsearch->nextnode = search->nextnode;
		}
	}
	ciclestack() {
		first = nullptr;
		//last = nullptr;
		length = 0;
	};
	~ciclestack();
};

