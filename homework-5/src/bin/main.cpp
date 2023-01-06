#include "hashset.hpp"
#include "linkedlist.hpp"
#include <stdlib.h>
#include <string>

int main(){
    List<int>* list = new List<int>();


    List<std::string>* string_list = new List<std::string>();

    string_list->insertAtHead("Hello");
    string_list->insertAtHead("World");
    string_list->insertAtHead("!");
    std::string str = string_list->removeHead();
    string_list->print();

    delete list;
    delete string_list;
}