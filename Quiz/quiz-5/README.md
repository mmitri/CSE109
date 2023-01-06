# CSE 109 - Systems Softare - Spring 2022 - Quiz 5

**Due: 2/28/2022 End of Day**

Make at least one commit per question. You can write your answers in this file, `README.md`. You can use the Gitlab interface to edit this file if you prefer.

## Question 1

Describe what the following functions do. What are their inputs and output?

~~~
malloc() : asks for a specific size of memory and returns a null pointer to the beginning of the memory; contect of the memory is not initialized.
    (from cplusplus.com) Allocates a block of size bytes of memory, returning a pointer to the beginning of the block. Takes in parameter size of the memory block, in bytes.
sizeof() : (from educba.com) returns the size of any data type, expression, array, etc. It takes the data type or expression as a part of argument, and returns the result which is size of that data type in bytes.
~~~

## Question 2

What is a struct? How are structs in C similar and different from Objects in Java?
    Structs are just a type of data structure, similar to objects in java, where you can
    declare it once, and reuse the variables under the struct. However, structs, in general,
    are just organized memory. They do not have the full functionality of inheritence or functions as Objects do in Java.

## Question 3

How are structs similar to arrays? How are they different?
    Structs are more similar to arrays than they are similar to objects. Both structs and arrays are a form of organizing memory, where you can initialize and access parts of the memory. However, arrays are homogeneous in their data type, while you can store both int and char in a struct. Arrays are pointers, while structs are not. Instantiation of a struct is possible, while array instantiation is not.
