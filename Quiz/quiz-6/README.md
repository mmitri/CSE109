# CSE 109 - Systems Software - Spring 2022 - Quiz 6

**Due: 3/30/2022 End of Day**

Make at least one commit per question. You can write your answers in this file, `README.md`. You can use the Gitlab interface to edit this file if you prefer.

## Question 1

What is a constructor? What is a destructor?

Constructors are a method within a library that initializes objects in the class; It constructs the values of data members in the class.

Destructors are a method within a library that destroyes objects in the class; It calls on the compiler that cleans up the storage the constructor method used.

## Question 2

How are C structs and C++ objects the different? How are they the same?

C++ objects are more similar to objects in Java, where you can create a generalized method that can be called on in the main method. Objects can have some data behind it; It holds functionality such as inheritance, methods, data, virtual functions. 
[1](https://stackoverflow.com/questions/4514582/whats-the-difference-between-an-object-and-a-struct-in-oop). Structs are just organized memory.

## Question 3

How is object oriented programming, which is the style of C++; different from procedural programming, which is the style of C?

Both styles are high-level languages, where you can create applications without thinking about the memory allocation, linking, etc. 

POP methods get divided into parts on the definition of functions; They are separate programs. Data can move freely between functions. POP is more like a top-down approach.

OOP involves classes and objects, which divides the program into instances of the classes. Instead of memory moving around, objects can move and communicate with each other through member functions