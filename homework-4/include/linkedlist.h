#include <stdio.h>
#include <stdlib.h>

// Data members
typedef struct {
	void* item;
	struct Node* next;
}Node;

typedef struct {
	Node* head;
	Node* tail;
}List;

/***
 * Default method
 * Sets the value of the data members to null
 ***/
void initList(List* list_pointer){
	Node *newLinkList = (Node*)malloc(sizeof(Node));
	list_pointer->head = NULL;
	list_pointer->tail = NULL;
}

// Create node containing item, return reference of it.
Node* createNode(void* item){
	Node *createNode = (Node*)malloc(sizeof(Node));
	createNode->item = item;
	createNode->next = NULL;
	return createNode;
}

/***
 * Method insertAtTail(List* list_pointer, void* item)
 * Adds a void element to the end of the array
 * @param list_pointer for the reference to the data members
 * @param item for the item to be added
 * @return 1 for success or 0 for failure
 ***/
int insertAtTail(List* list_pointer, void* item){
	Node *tempNode = list_pointer->head;
	Node *newTailNode = createNode(item);
	int count = 0;
	while(count != 0){
		tempNode = tempNode->next;
		count = count + 1;
	}
	tempNode->next = newTailNode;
	return list_pointer->head;
}

/***
 * Method insertAtHead(List* list_pointer, void* item)
 * Adds a void element to the beginning of the array
 * @param list_pointer for the reference to the data members
 * @param item for the item to be added
 * @return 1 for success or 0 for failure
 ***/
int insertAtHead(List* list_pointer, void* item){
	Node *tempNode;
	tempNode = (List *)malloc(sizeof(List));
	tempNode->item = item;
	tempNode->next = list_pointer->head;
	list_pointer->head = tempNode;
}

/***
 * Method insertAtIndex(List* list_pointer, int index, void* item)
 * Adds a void element to a specified index given by the user
 * @param list_pointer for the reference to the data members
 * @param index for the location of the item to be added
 * @param item for the item to be added
 * @return 1 for success or 0 for failure
 ***/
int insertAtIndex(List* list_pointer, int index, void* item){
	Node *tempNode = list_pointer->head;
	Node *newNode = createNode(item);
	Node *insertNext;
	while(index-1 != 0){
		tempNode = tempNode->next;
		index = index - 1;
	}
	insertNext = tempNode->next;
	tempNode->next = newNode;
	tempNode->next->next = insertNext;
	return list_pointer->head;
}

/***
 * Method removeTail(List* list_pointer)
 * Removes an element from the end of the array
 * @param list_pointer for the reference to the data members
 * @return a reference to the removed item
 ***/
void* removeTail(List* list_pointer){
	int count = 0;
	Node *tempNode = list_pointer->head;
	Node *removeT;
	while(count < list_pointer->tail-1){
		tempNode = tempNode->next;
		count = count + 1;
	}
	removeT = tempNode->next;
	tempNode->next = NULL;
	free(removeT);
	return removeT;
}

/***
 * Method removeHead(List* list_pointer)
 * Removes an element from the beginning of the array
 * @param list_pointer for the reference to the data members
 * @return a reference to the removed item
 ***/
void* removeHead(List* list_pointer){
	int removeHead = -1;
	Node* nextNode = NULL;
	if(list_pointer->head == NULL){
		return -1;
	}
	nextNode = (list_pointer->head)->next;
	removeHead = (list_pointer->head)->item;
	free(list_pointer->head);
	list_pointer->head = nextNode;
	return removeHead;
}

/***
 * Method removeAtIndex(List* list_pointer, int index)
 * Removes an element from a specified index given by the user
 * @param list_pointer for the reference to the data members
 * @param index for the location of the item to be removed
 * @return a reference to the removed item
 ***/
void* removeAtIndex(List* list_pointer, int index){
	Node* tempNode = list_pointer->head;
	Node* removeNode;
	int count = 0;
	while(count < index-1){
		tempNode = tempNode->next;
		count = count + 1;
	}
	removeNode = tempNode->next;
	tempNode->next = tempNode->next->next;
	free(removeNode);
	return removeNode;
}

/***
 * Method itemAtIndex(List* list_pointer, int index)
 * Returns the item at the index from the user
 * @param list_pointer for the reference to the data members
 * @param index for the location of the item to be found
 * @return a reference to the item
 ***/
void* itemAtIndex(List* list_pointer, int index){
	int count = 0;
	Node* current = list_pointer->head;
	while(current != NULL){
		if(count == index){
			return (current->item);
		}
		count = count + 1;
		current = current->next;
	}
}

/***
 * Method printList(List* list_pointer)
 * Prints the linkedlist
 * @param list_pointer for the reference to the data members
 * @return a void method
 ***/
void printList(List* list_pointer){
	Node* current = list_pointer->head;
	while(current != NULL){
		printf("%d\n", current->item);
		current = current->next;
	}
}