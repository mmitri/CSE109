#include "linkedlist.hpp"
#include <stdio.h>
#include <string>

template <class T>
class HashSet{
  private:
    // The backbone of the hash set. This is an array of Linked List pointers.
    LinkedList<T>** array;
    // The number of buckets in the array
    size_t size;
    int capacity;
    double loadFactor;
    int count = 0;
    // Generate a prehash for an item with a given size
    unsigned long prehash(T item);
  public:
    capacity = 1000;
    loadFactor = 0.70;
    // Initialize an empty hash set, where size is the number of buckets in the array
    HashSet(size_t size);
    // Free all memory allocated by the hash set
    ~HashSet();
    // Hash an unsigned long into an index that fits into a hash set
    unsigned long hash(T item);
    // Insert item in the set. Return true if the item was inserted, false if it wasn't (i.e. it was already in the set)
    // Recalculate the load factor after each successful insert (round to nearest whole number).
    // If the load factor exceeds 70 after insert, resize the table to hold twice the number of buckets.
    bool insert(T item);
    // Remove an item from the set. Return true if it was removed, false if it wasn't (i.e. it wasn't in the set to begin with)
    bool remove(T item);
    // Return true if the item exists in the set, false otherwise
    bool contains(T item);
    // Resize the underlying table to the given size. Recalculate the load factor after resize
    void resize(size_t new_size);
    // Returns the number of items in the hash set
    size_t len();
    // Returns the number of buckets that can be filled before reallocating
    size_t capacity();
    // Print Table. You can do this in a way that helps you implement your hash set.
    void print();
};

/* Modify this prehash function to work with a template type T instead of a char*/
template <class T>
unsigned long prehash(T item){
    unsigned long h = 5381;
    unsigned char *str = (char) item;
    int c;
    while (c = *str++) { 
	    h = ((h << 5) + h) + c;
    }
    return h;
}

template <class T>
unsigned long hash(T item){
    
}

template <class T>
bool insert(T item){
    LinkedList<T>** array = head;
    while(this != NULL){
        if(this->val==item){
            return true;
        }
        this = this->next;
    }
    if(head == NULL){
        head = new LinkedList<T>(key);
        return true;
    }else{
        this = new LinkedList<T>(key);
        this->next = head;
        head = this;
        return true;
    }
    return false;
}

template <class T>
bool remove(T item){
    if(this->head != NULL && this->head->item = item){
        this->head = head->next;
        return true;
    }
    LinkedList<T>** array = this->head;
    while(array != NULL && array->next != NULL){
        if(array->next->item = item){
            array->next = array->next->next;
            return true;
        }
        array = array->next;
    }
    return false;
}

template <class T>
bool contains(T item){
    LinkedList<T>** temp = this->head;
    temp = this->head;
    while(temp != NULL){
        if(temp->val == item){
            return true;
        }
        temp = temp->next;
    }
    return false;
}
