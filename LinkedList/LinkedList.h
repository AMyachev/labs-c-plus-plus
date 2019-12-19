#pragma once
template<typename T> class LinkedList
{
	int size;
	typedef struct list {
		list* left;
		T* value;
		list* right;
		list() {

		}
	};
	list* first_element;
	list* last_element;
	list* pointer;
	list* get_elem(int index) {
		if (index == 0) {
			list* value = pointer;
			pointer = first_element;
			return value;
		}
		else if (index < 0) {
			pointer = pointer->left;
			return get_elem(index+1);
		}
		else {
			pointer = pointer->right;
			return get_elem(index-1);
		}
	}
public:
	LinkedList() {
		first_element = new list();
		first_element->left = first_element;
		first_element->right = first_element;
		last_element = first_element;
		pointer = first_element;
		size = 0;
	}
	void push_back(T* value) {
		if(size==0)
		last_element->value = value;
		else {
			last_element->right = new list();
			list* temp = last_element;
			last_element = last_element->right;
			last_element->value = value;
			last_element->left = temp;
			last_element->right = first_element;
			first_element->left = last_element;
		}
		size++;
	}
	void push(T* value) {
		if (size == 0)
			first_element->value = value;
		else {
			first_element->left = new list();
			list* temp = first_element;
			first_element = first_element->left;
			first_element->value = value;
			first_element->right = temp;
			first_element->left = last_element;
			last_element->right = first_element;
			pointer = first_element;
		}
		size++;
	}
	void insert(int pos, T* value) {
		list* new_list = new list();
		list* temp = get_elem(pos);
		list* temp_left = temp->left;
		temp->left = new_list;
		temp->left->value = value;
		temp->left->left = temp_left;
		temp->left->right = temp;
		temp_left->right = temp->left;
	}
	void erase(int index) {
		if (size == 0)return;
		list* searching_elem = get_elem(index);
		list* temp = searching_elem;
		temp->left->right = temp->right;
		temp->right->left = temp->left;
		if (temp == first_element) {
			first_element = temp->right;
			pointer = first_element;
		}
		if (temp == last_element) {
			last_element = temp->left;
		}
		delete(temp);
		size--;
	}
	T* operator [](int index) {
		return(get_elem(index)->value);
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
