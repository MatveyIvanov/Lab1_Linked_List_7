#include <iostream>
#include "Linked_List.h"

using namespace std;

const int N = 5;

int main()
{
    setlocale(LC_ALL, "ru");

    int arr[N] = { 1,4,9,16,25 };
    LinkedList* list = new LinkedList(arr, N);
    cout << "Элементы списка: ";
    list->print_to_console();
    list->push_back(36);
    cout << "Элементы списка после вставки 36 в конец: ";
    list->print_to_console();
    list->push_front(0);
    cout << "Элементы списка после вставки 0 в начало: ";
    list->print_to_console();
    list->pop_back();
    cout << "Элементы списка после удаления последнего элемента: ";
    list->print_to_console();
    list->pop_front();
    cout << "Элементы списка после удаления первого элемента: ";
    list->print_to_console();
    list->insert(21, 4);
    cout << "Элементы списка после вставки 21 перед 4 элементом: ";
    list->print_to_console();
    cout << "Элемент по индексу 4: " << list->at(4) << endl;
    list->remove(2);
    cout << "Элементы списка после удаления элемента по индексу 2: ";
    list->print_to_console();
    cout << "Текущий размер списка: " << list->get_size() << endl;
    list->set(0, -10);
    cout << "Элементы списка после замены элемента по индексу 0 на -10: ";
    list->print_to_console();
    
    LinkedList* temp = new LinkedList(arr, N);
    list->push_front(temp);
    cout << "Элементы списка после вставки другого списка в начало: ";
    list->print_to_console();
    cout << "Список " << (list->isEmpty() ? "пуст" : "не пуст") << endl;
    list->clear();
    cout << "Опустошение списка... Список " << (list->isEmpty() ? "пуст" : "не пуст") << endl;

    return 0;
}

