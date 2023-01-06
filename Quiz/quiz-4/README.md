# CSE 109 - Systems Softare - Spring 2022 - Quiz 4

**Due: 2/21/2021 End of Day**

Make at least one commit per question. You can write your answers in this file, `README.md`. You can use the Gitlab interface to edit this file if you prefer.

## Question 1

Describe the purpose and usage of the following operators:

~~~
* | dereferences and returns the value at the address stored in the variable
& | references and returns the memory address of a variable
~~~

## Question 2

How are pointers and arrays equivalent in C?

In C, you can assign an array to a pointer. You can use the array notation [i] on pointers. Whenever you mention the name of an array in a context where the value of the array would be needed, C automatically generates a pointer to the first element of the array, as if you had written &array[0]. (10.5 ``Equivalence’’ between Pointers and Arrays. https://eskimo.com/~scs/cclass/notes/sx10e.html. Accessed 19 Feb. 2022.)

## Question 3

What is the difference between the following lines of code:

~~~
*foo + 1 | This dereferences the variable foo and then does math addition of one on the value.
*(foo + 1) | This dereferences the entire equation (foo + 1) to location of (foo + 1).
foo[1] | This is the same as *(foo+1)
~~~

## Homework 2 Extra Credit

If you had trouble with HW2, no worries! You now have an opportunity to make up some extra points, up to 25% (Maximum of 100% for the assignment). 

This part is due by Friday.

1. Answer the following question: what are the top 3 challenges you faced in completing HW2, and what is your plan for overcoming them for the future?

    [1] I didn't really wrap my mind on the task of HW2 for some reason. I was trying to play with the code we had after one lecture
    about HW2, but I didn't understand the steps I had to take to complete it.
    [2] Understanding the Terminal's commands. all the different flags for gcc and what they did to my code was very confusing.
    [3] All the segmentation faults felt like my code was useless and I was not confident enough to try and fix it.

    Obviously, learning a new coding language and the environment surrounding it will take some time, (and I think I have learned a lot after the struggle of HW2), but I think asking more questions during office hours on simple things like understanding weird functions like strtok() and makefiles.

2. Use the solution to HW2 to finish/correct your own submisison of the homework, but you can't use `strtok()`. Make at least 5 commits. 




