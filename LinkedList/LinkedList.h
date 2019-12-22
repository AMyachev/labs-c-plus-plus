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
	void addNode(list* left, list* right, T* value) {
		list* new_list = new list();
		new_list->value = value;
		new_list->left = left;
		new_list->right = right;
		left->right = new_list;
		right->left = new_list;
	}
	void push(T* value) {
		if (size == 0)
			startElement->value = value;
		else {
			addNode(startElement->left, startElement, value);
		}
		size++;
	}
	void insert(int pos, T* value) {
		list* new_list = new list();
		list* temp = get_elem(pos, startElement);
		addNode(temp, temp->right, temp->value);
		temp->value = value;
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
