# CSE 109 - Homework 4

**Due Date: 3/7/2022 EOD**

## Instructions 

**Read thoroughly before starting your project:**

1. Fork this repository into your CSE109 project namespace. [Instructions](https://docs.gitlab.com/ee/workflow/forking_workflow.html#creating-a-fork)
2. Clone your newly forked repository onto your development machine. [Instructions](https://docs.gitlab.com/ee/gitlab-basics/start-using-git.html#clone-a-repository) 
3. As you are writing code you should commit patches along the way. *i.e.* don't just submit all your code in one big commit when you're all done. Commit your progress as you work. **You should make at least one commit per function.**
4. When you've committed all of your work, there's nothing left to do to submit the assignment.

## Assignment

You will implement a linked list data structure in this assignment. The linked list will consist of a `head` pointer and a tail pointer. The head pointer will point to a `Node` struct, which will hold a data void pointer as well as a pointer to the next node in the list. The `tail` pointer will point to the final node in the linked list. The `next` pointer on the tail will point to `NULL`.


```
  ┌─────────┐    ┌─────────┐   ┌─────────┐    ┌─────────┐
  │     head│--->│  void*  │-->│  void*  │--->│  void*  │---> NULL
  │         │    └─────────┘   └─────────┘    └─────────┘
  │     tail│--------------------------------------^
  └─────────┘
```


The `List` and `Node` structs are declared in `linkedlist.h`, along with a number of functions you will need to implement.

```c
// Initialize an empty list. The head and tail pointers should point to NULL.
void initList(List* list_pointer);

// Create Node struct containing a void pointer to an item, return pointer to the newly created Node struct
Node* createNode(void* item);

// Insert new Node at the end of the list, containing a void pointer to item. The next pointer on this Node
// points to NULL. On success return 0. On failure, return 1.
int insertAtTail(List* list_pointer, void* item);

// Insert a Node at the head of the list, containing a void pointer to item. The next pointer on the
// newly created node points to the previous head of the list. On success return 0. On failure, return 1.
int insertAtHead(List* list_pointer, void* item);

// Insert a Node at the specified index, containing a void pointer to item. If the index is greater than
// the length of the list, the program should crash. On success return 0. On failure, return 1.
int insertAtIndex(List* list_pointer, int index, void* item);

// Remove Node from the end of list and return the void pointer it contains. The preceeding Node should
// point to NULL after this operation. On failure return a NULL pointer.
void* removeTail(List* list_pointer);

// Remove Node from start of list and return return the void pointer it contains. The following Node should 
// be the new head of the list. On failure return a NULL pointer.
void* removeHead(List* list_pointer);

// Insert Node item at a specified index and return return the void pointer it contains. The Node at the specified
// index before this function is called should be the next Node following the newly inserted Node.
// On failure return a NULL pointer.
void* removeAtIndex(List* list_pointer, int index);

// Return the pointer stored in the Node at the specified index. On failure return a NULL pointer. 
void* itemAtIndex(List* list_pointer, int index);
```

There is a print function that is already implemented for you. This will help you inspect the list as you write the above functions.

## Build Instructions

Write build instructions here. Explain to the user all the steps necessary to build this project including:

- What software (including versions) are needed?
You will need to install the latest versions of these softwares:
Windows Terminal from the Windows Store (ver. 1.11.3471.0)
Ubuntu on Windows Subsystem for Linux(ver. 2004.2021.825.0) https://docs.microsoft.com/en-us/windows/wsl/install
Git (ver. 2.35.0) https://git-scm.com/downloads
Visual Studio Code (only if you want to edit the code) (ver. 1.65.0) https://code.visualstudio.com/
- What system architectures and operating systems are supported?
Any x32 or x64 based computer architecture. Both Windows and Mac are supported.
- What commands need to be entered to build the project?
Once you have the repository cloned onto your personal computer, use the command 'cd' and 'ls' in your terminal to navigate to the location of your cloned repository. Type this command: make


## Usage

Write usage instructions here. Explain to the user how they can integrate your library into their project. Usage instructions might include:

- What the user should `#include` into their project and where.
Make sure to #include linkedlist.h into the project's main.c
- An example command of how the user might build their project to link to your library.
The -L flag tells the compiler where to find library files. So use the -L flag along with the name of the library you want to include,
and the library will be added to the compiled program
- How to create a linked list using your library.
- How to use the linked list.
- How to clean up the linked list to avoid leaking memory.
A memory leak is when the user allocates memory without regard for deallocation. This is similar to filling a glass of water without stopping when the glass is full, leading to an overflow. It is best practice to write a delete pointer for matching of a new pointer, delete(pointer), similar to the way in Java, when you want to close a Scanner you use keyboard.close(). 
https://www.geeksforgeeks.org/memory-leak-in-c-and-how-to-avoid-it/

## Examples

Write two examples demonstrating how to use your linked list library. These example should be complete in the sense that the user can just copy and paste them into their code and everything should work as long as they follow the build and usage instructions you gave them.

Example 1:
  List *linkedList;
  void* item;
  linkedList = (List *) malloc(sizeof(List));
  initList(linkedList);
  int first = 0x78ff10;
  int second = 0xbread5;
  insertAtHead(linkedList,&first);
  insertAtTail(linkedList,&second);