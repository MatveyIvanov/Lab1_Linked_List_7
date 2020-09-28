#include "Linked_List.h"


void LinkedList::push_back(const int data) {
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
		this->size++;
	}
	catch (exception& e) {
		cout << e.what();
	}
}

void LinkedList::push_front(const int data) {
	try {
		LinkedListNode* new_node = new LinkedListNode(data);
		if (this->isEmpty()) {
			this->head = new_node;
		}
		else {
			new_node->next = this->head;
			this->head = new_node;
		}
		this->size++;
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
		if (this->last == this->head) {
			this->clear();
		}
		else {
			LinkedListNode* cur = this->head;
			while (cur->get_next() != this->last) // Searching for penultimate element to make it last
				cur = cur->next;
			delete this->last;
			cur->next = NULL;
			this->last = cur;
			this->size--;
		}
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
	this->size--;
}

void LinkedList::insert(const int data, const size_t i) {
	if ((this->get_size() < i)) {
		throw out_of_range("Index is out of range");
	}
	else if (i == 0) {
		this->push_front(data);
	}
	else if (i == this->get_size()) {
		this->push_back(data);
	} 
	else {
		size_t temp_index = 0;
		LinkedListNode* new_node = new LinkedListNode(data);
		LinkedListNode* cur = this->head;
		while (temp_index != i - 1) { // Searching for i - 1 element. Then insert new element after it
			temp_index++;
			cur = cur->next;
		}
		LinkedListNode* temp = cur->next;
		cur->next = new_node;
		new_node->next = temp;
		this->size++;
	}
}

int LinkedList::at(const size_t i) {
	if ((this->get_size() < i + 1) || (i < 0)) {
		throw out_of_range("Index is out of range");
	}
	else if (i == 0) {
		return this->head->get_data();
	}
	else {
		LinkedListNode* cur = this->head;
		size_t temp_index = 0;
		while (temp_index != i) { // Searching for i element
			temp_index++;
			cur = cur->next;
		}
		return cur->get_data();
	}
}

void LinkedList::remove(const size_t i) {
	if ((this->get_size() < i) || (i < 0)) {
		throw out_of_range("Index is out of range");
	}
	else if (i == 0) {
		this->pop_front();
	}
	else if (i == this->get_size()) {
		this->pop_back();
	} 
	else {
		size_t temp_index = 0;
		LinkedListNode* cur = this->head;
		while (temp_index != i - 1) { // Searching for i - 1 element
			temp_index++;
			cur = cur->next;
		}
		LinkedListNode* temp = cur->next;
		cur->next = cur->next->next;
		delete temp;
		this->size--;
	}
}

size_t LinkedList::get_size() {
	return this->size;
}

void LinkedList::print_to_console() {
	if (this->isEmpty()) {
		throw exception("List is empty");
	}
	else {
		LinkedListNode* cur = this->head;
		while (cur != NULL) {
			cout << cur->get_data() << ' ';
			cur = cur->next;
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

void LinkedList::set(const size_t i, const int data) {
	if ((this->get_size() < i + 1) || (i < 0)) {
		throw out_of_range("Index is out of range");
	}
	else {
		size_t temp_index = 0;
		LinkedListNode* cur = this->head;
		while (temp_index != i) { // Searching for i element to change his data
			temp_index++;
			cur = cur->next;
		}
		cur->set_data(data);
	}
}

bool LinkedList::isEmpty() {
	if (this->head == NULL)
		return true;
	else
		return false;
}

void LinkedList::push_front(LinkedList* list) {
	if (list->isEmpty()) {
		throw exception("List you want to insert is empty");
	}
	else {
		LinkedList* copy = new LinkedList(list);
		if (this->isEmpty()) {
			this->head = copy->head;
		}
		else {
			copy->last->next = this->head;
			this->head = copy->head;
		}
		this->size += list->size;
	}
}