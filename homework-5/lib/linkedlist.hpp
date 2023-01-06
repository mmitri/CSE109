#include <iostream>
#include <stdio.h>

template <class T>
class Node{
  public:
	  T item;
	  struct Node<T>*  next;
    Node(T item);
    ~Node();
	T createNode(T item);
};

template <class T>
class List{
	public:
        Node<T>* head;
	    Node<T>* tail;    
        List();           
        List(List<T>* list); 
        ~List();          
        int insertAtHead(T item);
		int insertAtTail(T item);
		T insertAtIndex(size_t index, T item);
        void print();
        T removeHead();
		T removeTail();
        T removeAtIndex(int index);
};

//Initialize List
template <class T>
List<T>::List() {
	this->head = NULL;
	this->tail = NULL;
}

template <class T>
List<T>::List(List<T> *list){
	this->head = list->head;
	this->tail = list->tail;
}

template <class T>
Node<T>::Node(T item){
	this->item = item;
	this->next = NULL;
}

template <class T>
T Node<T>::createNode(T item){
	Node<T>* nNode;
	nNode = (Node *) malloc(sizeof(Node));
	if (nNode == NULL) {
		return NULL;
	}
	nNode->item = item;
	nNode->next = NULL;
	return nNode;
}


template <class T>
int List<T>::insertAtHead(T item){
	Node<T>* node = new Node<T>(item);
	if(this->head == NULL){
		this->head = node;
		this->tail = node;
	}else{
		node->next 	= this->head;
		this->head 	= node;
	}		
	return 0;
}

template <class T>
int List<T>::insertAtTail(T item){
	Node<T>* node;
	node = createNode((void*)item);
	if (node == NULL) {
		return 1;
	}
	//if list is empty.
	if(this->head == NULL) {
		this->head = node;
		this->tail = node;
	} else {
		this->tail->next  = node;
		this->tail 	= this->tail->next;
	}	
	return 0;
}

template <class T>
T List<T>::insertAtIndex(size_t index, T item) {
	Node<T>* to_insert;
	to_insert = createNode(item);
	if (to_insert == NULL) {
		return 0;
	}
	int i = 0;
	Node<T>* prev;
	Node<T>* node = this->head;
	while (node != NULL) {
		if (i == index) {
			prev->next = to_insert;
			to_insert->next = node;
			return 0;
		} else if (i > index) {
			return 0;
		} else {
			i++;
			prev = node;
			node = node->next;
		}
	}	
	return	0; 
}

template <class T>
T List<T>::removeAtIndex(int index){
  int i = 0;
  Node<T>* prev;
  Node<T>* node = this->head;
  while(node != NULL){
    if(i == index){
        prev->next = node->next;
	    T item = node->item;
		delete node;
    	return item;
    }else if(i > index){
		return NULL;
    }else{
      i++;
      prev = node;
      node = node->next;
    }
  }	
}

template <class T>
T List<T>::removeHead(){
	T item;
	if(this->head == NULL){		
		return 0;
	}else{
		item = this->head->item;
		Node* old_head = this->head;
		this->head = this->head->next;	
        old_head->next = NULL;
		delete old_head;
	}	
	return item;
}

template <class T>
T List<T>::removeTail(){
	Node<T> * temp;
	int i = 0;
	T item;
	if(this->tail == NULL) {	
		// List is Empty	
		return NULL;
	}
	else {
		temp = this->head;
		// Iterate to the end of the list
		while(temp->next != this->tail) { 
			temp = temp->next;
		}
		item = this->tail->item;
		Node<T>* old_tail = this->tail;
		this->tail = temp;
		this->tail->next = NULL;	
		delete old_tail;	
	}	
	return item;
}

template <class T>
void List<T>::print(){
	Node<T>* node;
	if(this->head == NULL){
		printf("\nEmpty List");
		return;
	}
	node = (Node<T>*) this->head;
	printf("\nList: \n\n\t"); 
	while(node != NULL){
		printf("[ %x ]", node->item);
		node = (Node<T>*) node->next;
		if(node !=NULL){
			printf("-->");
        }
	}
	printf("\n\n");
}

template <class T>
Node<T>::~Node(){
	std::cout << "Node destructor" << std::endl;
  	if (this->next != NULL) {
   		delete this->next;
  	}
  	std::cout << "Done node destructor" << std::endl;
}

template <class T>
List<T>::~List(){
	std::cout << "List destructor" << std::endl;
  	delete this->head;
  	std::cout << "Done list destructor" << std::endl;
}

