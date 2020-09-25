#pragma once
#include <stdexcept>
#include <iostream>

using namespace std;

class LinkedListNode {
public:
	LinkedListNode* next; // Pointer to the next element in list
	LinkedListNode(int d): data(d), next(NULL) {}
	int getData();
	void setData(int);
private:
	int data; // Data of the element
};

class LinkedList {
public:
	LinkedListNode* head; // Pointer to the head element of the list
	LinkedListNode* last; // Pointer to the last element of the list
	LinkedListNode* cur; // Pointer to the current element of the list
	LinkedList(): head(NULL), last(NULL), cur(NULL) {}
	LinkedList(int* arr, size_t n) {
		for (size_t i = 0; i < n; i++) {
			this->push_back(arr[i]);
		}
	}
	void push_back(int); // Add element to the end of the list
	void push_front(int); // Add to the beginning of the list
	void pop_back(); // Delete last element
	void pop_front(); // Delete first element
	void insert(int, size_t); // Add an element by index
	int at(size_t); // Get an element by index
	void remove(size_t); // Delete an element by index
	size_t get_size(); // Get size of the list
	void print_to_console(); // Output of list elements to the console
	void clear(); // Delete all elements of the list
	void set(size_t, int); // Replace the element by index with the passed element
	bool isEmpty(); // Check if the list is empty
	void push_front(LinkedList*); // Insert another list at the beginning of current list

	~LinkedList() {
		LinkedListNode* temp;
		while (this->head != NULL) {
			temp = this->head->next;
			delete this->head;
			this->head = temp;
		}
		this->last = this->head;
	}
};

int LinkedListNode::getData() {
	return this->data;
}

void LinkedListNode::setData(int d) {
	this->data = d;
}

void LinkedList::push_back(int data) {
	try {
		LinkedListNode* new_node = new LinkedListNode(data);
		if (this->isEmpty()) {
			this->head = new_node;
			this->last = this->head;
		}
		else {
			this->last->next = new_node;
			this->last = new_node;
		}
	}
	catch (exception& e) {
		cout << e.what();
	}
}

void LinkedList::push_front(int data) {
	try {
		LinkedListNode* new_node = new LinkedListNode(data);
		if (this->isEmpty()) {
			this->head = new_node;
		}
		else {
			new_node->next = this->head;
			this->head = new_node;
		}
	}
	catch (exception& e) {
		cout << e.what();
	}
}

void LinkedList::pop_back() {
	if (this->isEmpty()) {
		throw exception("List is empty before pop");
	}
	else {
		this->cur = this->head;
		while (this->cur->next != this->last) // Searching for penultimate element to make it last
			this->cur = this->cur->next;
		delete this->last;
		this->cur->next = NULL;
		this->last = this->cur;
	}
}

void LinkedList::pop_front() {
	if (this->isEmpty()) {
		throw exception("List is empty before pop");
	}
	else {
		LinkedListNode* temp = this->head->next;
		delete this->head;
		this->head = temp;
	}
}

void LinkedList::insert(int data, size_t i) {
	if (this->get_size() < i + 1) {
		throw out_of_range("Index is out of range");
	}
	else if (i == 0) {
		this->push_front(data);
	}
	else {
		size_t temp_index = 0;
		LinkedListNode* new_node = new LinkedListNode(data);
		this->cur = this->head;
		while (temp_index != i - 1) { // Searching for i - 1 element. Then insert new element after it
			temp_index++;
			this->cur = this->cur->next;
		}
		LinkedListNode* temp = this->cur->next;
		this->cur->next = new_node;
		new_node->next = temp;
		if (new_node->next == NULL)
			this->last = new_node;
	}
}

int LinkedList::at(size_t i) {
	if (this->get_size() < i + 1) {
		throw out_of_range("Index is out of range");
	}
	else if (i == 0) {
		return this->head->getData();
	}
	else {
		this->cur = this->head;
		size_t temp_index = 0;
		while (temp_index != i) { // Searching for i element
			temp_index++;
			this->cur = this->cur->next;
		}
		return this->cur->getData();
	}
}

void LinkedList::remove(size_t i) {
	if (this->get_size() < i + 1) {
		throw out_of_range("Index is out of range");
	}
	else if (i == 0) {
		this->pop_front();
	}
	else {
		size_t temp_index = 0;
		this->cur = this->head;
		while (temp_index != i - 1) { // Searching for i - 1 element
			temp_index++;
			this->cur = this->cur->next;
		}
		if (this->cur->next->next == NULL) { // If i element is last
			this->pop_back();
		}
		else {
			LinkedListNode* temp = this->cur->next;
			this->cur->next = this->cur->next->next;
			delete temp;
		}
	}
}

size_t LinkedList::get_size() {
	if (this->isEmpty())
		return 0;
	else {
		this->cur = this->head;
		size_t size = 1;
		while (this->cur->next != NULL) {
			size++;
			this->cur = this->cur->next;
		}
		return size;
	}
}

void LinkedList::print_to_console() {
	if (this->isEmpty()) {
		throw exception("List is empty");
	}
	else {
		this->cur = this->head;
		while (this->cur != NULL) {
			cout << this->cur->getData() << ' ';
			this->cur = this->cur->next;
		}
		cout << endl;
	}
}

void LinkedList::clear() {
	if (this->isEmpty()) {
		return;
	}
	else {
		this->~LinkedList();
	}
}

void LinkedList::set(size_t i, int d) {
	if (this->get_size() < i + 1) {
		throw out_of_range("Index is out of range");
	}
	else {
		size_t temp_index = 0;
		this->cur = this->head;
		while (temp_index != i) { // Searching for i element to change his data
			temp_index++;
			this->cur = this->cur->next;
		}
		this->cur->setData(d);
	}
}

bool LinkedList::isEmpty() {
	if (this->head == NULL)
		return true;
	else
		return false;
}

void LinkedList::push_front(LinkedList* list) {
	if (this->isEmpty()) {
		this->head = list->head;
	}
	else if (list->isEmpty()) {
		throw exception("List you want to insert is empty");
	}
	else {
		list->last->next = this->head;
		this->head = list->head;
	}
}