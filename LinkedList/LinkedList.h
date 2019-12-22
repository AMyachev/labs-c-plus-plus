#pragma once
template<typename T> class LinkedList
{
	int size;
	typedef struct list {
		list* left;
		T* value;
		list* right;
	};
	list* startElement;
	list* get_elem(int index, list* pointer) {
		if (index == 0) {
			return pointer;
		}
		else if (index < 0) {
			pointer = pointer->left;
			return get_elem(index+1,pointer);
		}
		else {
			pointer = pointer->right;
			return get_elem(index-1,pointer);
		}
	}
public:
	LinkedList() {
		startElement = new list();
		startElement->left = startElement;
		startElement->right = startElement;
		startElement = startElement;
		size = 0;
	}
	void push(T* value) {
		if (size == 0)
			startElement->value = value;
		else {
			list* temp = startElement->left;
			startElement->left = new list();
			startElement->left->value = value;
			startElement->left->right = startElement;
			startElement->left->left = temp;
			temp->right = startElement->left;
		}
		size++;
	}
	void insert(int pos, T* value) {
		list* new_list = new list();
		list* temp = get_elem(pos, startElement);
		new_list->value = temp->value;
		temp->value = value;
		new_list->right = temp->right;
		new_list->left = temp;
		temp->right = new_list;
		new_list->right->left = new_list;
		size++;
	}
	void erase(int index) {
		if (size == 0)return;
		list* searching_elem = get_elem(index, startElement);
		list* temp = searching_elem;
		temp->left->right = temp->right;
		temp->right->left = temp->left;
		if (temp == startElement) {
			startElement = temp->right;
		}
		if (temp == startElement) {
			startElement = temp->left;
		}
		delete(temp);
		size--;
	}
	T* operator [](int index) {
		return(get_elem(index, startElement)->value);
	}
	~LinkedList() {
		for (int i = 0; i < size; i++) {
			erase(i);
		}
	}
	int get_size() {
		return size;
	}
};
