#pragma once
#include <stdexcept>
#include <iostream>

using namespace std;

class LinkedListNode {
public:
	LinkedListNode(int d): data(d), next(NULL) {}
	int get_data() { return this->data; }
	void set_data(int d) { this->data = d; }
	LinkedListNode* get_next() { return this->next; }

	friend class LinkedList; // Make LinkedListNode friend of LinkedList
private:
	int data; // Data of the element
	LinkedListNode* next; // Pointer to the next element in list
};

class LinkedList {
public:
	LinkedList(): head(NULL), last(NULL), size(0) {}
	LinkedList(int* arr, size_t n) {
		for (size_t i = 0; i < n; i++) {
			this->push_back(arr[i]);
		}
		this->size = n;
	}
	LinkedList(LinkedList* list) {
		LinkedListNode* cur = list->head;
		while (cur != NULL) {
			this->push_back(cur->data);
			cur = cur->next;
		}
		this->size = list->size;
	}
	LinkedListNode* get_head() { return this->head; }
	LinkedListNode* get_last() { return this->last; }
	void push_back(const int); // Add element to the end of the list
	void push_front(const int); // Add to the beginning of the list
	void pop_back(); // Delete last element
	void pop_front(); // Delete first element
	void insert(const int, const size_t); // Add an element by index
	int at(const size_t); // Get an element by index
	void remove(const size_t); // Delete an element by index
	size_t get_size(); // Get size of the list
	void print_to_console(); // Output of list elements to the console
	void clear(); // Delete all elements of the list
	void set(const size_t, const int); // Replace the element by index with the passed element
	bool isEmpty(); // Check if the list is empty
	void push_front(LinkedList*); // Insert another list at the beginning of current list

	~LinkedList() {
		LinkedListNode* temp;
		while (this->head != NULL) {
			temp = this->head->next;
			delete this->head;
			this->head = temp;
		}
		this->head = NULL;
		this->last = this->head;
		this->size = 0;
	}
private:
	LinkedListNode* head; // Pointer to the head element of the list
	LinkedListNode* last; // Pointer to the last element of the list
	size_t size;
};