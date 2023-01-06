# CSE 109 - Quiz 3

**Due: 2/14/2022 End of Day**

Make at least one commit per question. Write your answers in this file, README.md. You can use the Gitlab interface to edit this file if you prefer.

## Question 1

What do the following gcc flags do?

- `I` | adds directory to search paths. gcc main.c -I include -> a.out (output). include a path during compilation. tells the compiler where to find header files that are #include<>
- `L` | tells the compiler where to find library files. add directory to linker search paths
- `l` | tells the compiler which libraries to link. 
- `o` | names the output executable. gcc -o my_exe main.c -> my_exe (output)
- `c` | stops the compilation process after the compile phase, so it prevents the linking phase. gcc -c main.c -> main.o (output)

## Question 2

What is a compiler? What does it consume? What does it produce? What is the name of the C compiler we are using inside of gcc?

A compiler takes the written code in any language and translates it into machine code that the computer can execute. cc is the compiler within gcc.

## Question 3

What is a linker? What does it consume? What does it produce? What is the name of the linker we are using inside of gcc?

A linker is a program which helps to connect multiple object modules of program into a single object file that is simpler to execute.  ld is the linker within gcc.
