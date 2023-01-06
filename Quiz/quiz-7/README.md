# CSE 109 - Systems Software - Spring 2022 - Quiz 7

**Due: 4/6/2022 End of Day**

Make at least one commit per question. You can write your answers in this file, `README.md`. You can use the Gitlab interface to edit this file if you prefer.

## Question 1

What is generic programming? How is generic programming done in C?

Generic programming is a type of coding where the specific types (int, char, double) of methods or classes are left up to the end user to
implement/choose. Generic programming is done in C using template classes similar to the one below:

template <class T>
Node<T>::Node(T item){}

where the T represents the specific type the user wants to implement.

## Question 2

What is a C++ template class?

A C++ template class is similar to a generic in C, where the use of a template allows later users to specify the type (int, char, double) of the methods they want to use.

"a template class in C++ is a class that allows the programmer to operate with generic data types. This allows the class to be used on many different data types as per the requirements without the need of being re-written for each type." [1]https://www.educba.com/what-is-template-class-in-c-plus-plus/

## Question 3

Why might one want to implement a template class fully in a header rather than in a library?

I am thinking of homework-5 in the sense that we instanciated some of the template classes so that the end user doesn't have to re-compile the 
generic types: 

template class List<char>;
template class List<int>;
template class List<std::string>;
template class List<short>;

In this case, it expidites the process of compiling the program for generic types.