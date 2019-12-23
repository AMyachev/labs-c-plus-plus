#pragma once
template<typename T> class LinkedList
{
	int size;
	typedef bool (*pred)(T*);
	typedef struct list {
		list* left;
		T* value;
		list* right;
	};
	list* startElement;
	list* get_elem(int index, list* pointer) {
		while (index != 0) {
			if (index < 0) {
			pointer = pointer->left;
			index++;
			}
			else {
			pointer = pointer->right;
			index--;
			}
		}
		return pointer;
	}
	void addNode(list* left, list* right, T* value) {
		list* new_list = new list();
		new_list->value = value;
		new_list->left = left;
		new_list->right = right;
		left->right = new_list;
		right->left = new_list;
	}
	void erase(list* searching_elem) {
		list* temp = searching_elem;
		temp->left->right = temp->right;
		temp->right->left = temp->left;
		if (temp == startElement) {
			startElement = temp->right;
		}
		delete(temp);
		size--;
	}
public:
	LinkedList() {
		startElement = new list();
		startElement->left = startElement;
		startElement->right = startElement;
		startElement = startElement;
		size = 0;
	}
	LinkedList(const LinkedList& copylist):LinkedList() {
		list* pointer = copylist.startElement;
		push(pointer->value);
		pointer=pointer->right;
		while (pointer != copylist.startElement) {
			push(pointer->value);
			pointer=pointer->right;
		}
	}
	LinkedList& operator =(const LinkedList& copylist) {
		list* pointer=startElement;
		list* copypointer = copylist.startElement;
		if (copylist.size >= this->size) {
			for (int i = 0; i < this->size;i++) {
				pointer->value = copypointer->value;
				pointer = pointer->right;
				copypointer = copypointer->right;
			}
			for (int i = 0; i < copylist.size - this->size;i++) {
				push(copypointer->value);
				copypointer = copypointer->right;
			}
		}
		else
		{
			for (int i = 0; i < copylist->size;i++) {
				pointer->value = copypointer->value;
				pointer = pointer->right;
				copypointer = copypointer->right;
			}
			for (int i = 0; i < this->size - copylist.size;i++) {
				list* temp = pointer;
				pointer = pointer->right;
				erase(temp);
			}
		}
		return *this;
	}
	void erase_if(pred f) {
		list* pointer=startElement;
		for (int i = 0; i < size; i++) {
			if (pred(pointer->value)) {
				list* temp = pointer;
				pointer = pointer->right;
				erase(temp);
			}else
			pointer = pointer->right;
		}
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
		list* temp = get_elem(pos, startElement);
		addNode(temp, temp->right, temp->value);
		temp->value = value;
		size++;
	}
	void erase(int index) {
		if (size == 0)return;
		list* searching_elem = get_elem(index, startElement);
		erase(searching_elem);
	}
	T* operator [](int index) {
		if (size == 0)return nullptr;
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
