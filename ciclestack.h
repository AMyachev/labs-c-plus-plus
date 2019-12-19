#pragma once
#include <iostream>
template <typename T>  class ciclestack
{	typedef struct Node
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
public:
	T* get_first() {
		return &(first->info);
	}
	
	int get_length() { return length; }
	T* get_elem(int index) {
		Node *search=first;
		try {
			if (length < 0) {
				throw;
			}
			for (int i = 0; i!=index; i++) {
			search = search->nextnode;
			}
		}
		catch (int e) {
			std::cout << "INDEX ERROR";
			return NULL;
		}
		
		return &(search->info);
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
			last_elem()->nextnode = first;
		}
		length++;
		
	}
	T* pop_first() {
		T* firstinfo;
		Node *myfirst;
		if (length > 0) {
			firstinfo = &(first->info);
			myfirst = first;
			first = first->nextnode;
			length--;
			last_elem()->nextnode = first;
			delete myfirst;
			return firstinfo;
		}
		else return NULL;
	}
	Node* last_elem() {
		Node *last = first;
		for (int i = 0; i < length; i++) {
			last = last->nextnode;
		}
		return last;
	}
	
	void deleteelem(int index) {
		Node *predsearch=first;
		Node *search = first;
		int i=0;
		if (index == 0) {
			pop_first();
		}
		else {
			try {
				if (length < 0) {
					throw;
				}
				for (i = 0; i != index; i++) {
				predsearch = search;
				search = search->nextnode;
				}
			}
			catch (int e) {
				std::cout << "INDEX ERROR";
				return;
			}
			
				length--;
				predsearch->nextnode = search->nextnode;
		}
	}
	ciclestack() {
		first = nullptr;
	
		length = 0;
	};
	~ciclestack() {
		Node *predsearch = first;
		Node *search = first;
		for (int i = 0; i < length-1; i++) {
			predsearch = search;
			search = search->nextnode();
			delete predsearch;
		}
		delete search;
	}
};
