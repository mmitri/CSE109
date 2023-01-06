# CSE 109 - Systems Software - Spring 2022 - Quiz 8

**Due: 4/25/2022 End of Day**

Make at least one commit per question. You can write your answers in this file, `README.md`. You can use the Gitlab interface to edit this file if you prefer.

## Question 1

Name the following operators and describe what they do:

```
<< - Bitwise left shift inserts a 0 bit at the least significant bit and shift the subsequent bits to the left.
>> - Bitwise right shift inserts a 0 bit at the most significant bit and shift the subsequent bits to the left.
| - Bitwise OR compares two bits and returns 1 if any of them or both bits are 1, otherwise returns a 0.
& - Bitwise AND compares two bits and returns 1 if both bits are 1, otherwise returns a 0.
^ - Bitwise XOR compares two bits and returns 1 if either of the bits are 1, otherwise returns a 0.
~ - Bitwise complement takes single operand and inverts all the bits of the operand.
```

## Question 2

Why do we have to serialize data before we can send it to another computer?

Serializing data allows for the transfer of information through a neutral format byte structure that all computers can read and decode.

## Question 3

How are sockets and files similar on Unix-like systems?

Sockets are files in a Unix-based system. When a socket is creared, an entry is made in the file descriptor table, which acts as a pointer to the File Table that houses information about the type of action i.e. read, write. [1](https://stackoverflow.com/questions/13378035/socket-and-file-descriptors)




