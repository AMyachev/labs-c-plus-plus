#pragma once
#include <iostream>
template <typename T>  class ciclestack
{
	
	typedef struct Node
	{
		Node* nextnode;
		T info;
		Node(T info) {
			this->info = info;
		}
		
	};
private:
	Node *first;
	int length;
	Node* get_node(int index) {
		if (index >= 0) {
			Node *last = first;
			for (int i = 0; i != index; i++) {
				last = last->nextnode;
			}
			return last;
		}
		else return nullptr;
	}
public:
	int get_length() { return length; }
	T* get_elem(int index) {
		return &(get_node(index)->info);
	}
	void push_first(const T &info) {
		Node *node = new Node(info);
		if (length == 0) {
			first = node;
			first->nextnode = first;
		}
		else {
			node->nextnode = first;
			first = node;
			get_node(length)->nextnode = first;
		}
		length++;
	}
	T* pop_first() {
		T* firstinfo;
		Node *myfirst;
		if (length > 0) {
			firstinfo = new T(first->info);
			peek();
			return firstinfo;
		}
		else return nullptr;
	}
	void peek() {
		if (length > 0) {
			Node *myfirst;
			myfirst = first;
			get_node(length)->nextnode = first->nextnode;
			length--;
			first = first->nextnode;
			delete myfirst;
		}
	}
	void deleteelem(int index) {
		if (index >= 0) {
			if (index == 0) {
				peek();
			}
			else {
				Node *predsearch;
				Node *search;
				predsearch = get_node(index - 1);
				search = predsearch->nextnode;
				length--;
				predsearch->nextnode = search->nextnode;
				delete search;
			}
		}
		else return;
	}
	ciclestack() {
		first = nullptr;
		length = 0;
	};
	~ciclestack() {
		while (length > 0) {
			deleteelem(0);
		}
	}
};

