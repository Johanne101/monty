Stacks, Queues - LIFO, FIFO
============================

General
---------
* What do **LIFO** and **FIFO** mean?

  * The **Last-In, First-Out (LIFO)** method assumes that the last unit to arrive in inventory or more recent is sold first.
  * The **First-In, First-Out (FIFO)** method assumes that the oldest unit of inventory is the sold first.

FIFO vs LIFO approach in Programming

* What is a stack, and when to use it | Stack Definition
  * a Stack is a data structure used to store a collection of objects. Individual items can be added and stored in a stack using a push operation. ... LIFO stacks, for example, can be used to retrieve recently used objects, from a cache.
Stacks are particularly useful when the computation has to go back in reverse order. This happens often in artificial intelligence applications
In computing, stacks being the backbone of data structures have been well applied in memory management and backtracking (games, searching for paths)

Usefulness of the concept to the current world
Stacks are used in reversing a string. In a word, this is done letter by letter and then pop the letters from the stack
They are also used in parsing in natural language processing
The most important applications in programs are for stacks are balancing of symbols, postfix expression or reverse polish notation and Infix to postfix conversion. All these are discussed in detail by Mark A. Weiss (2013) in his book entitled “Algorithm Analysis in C”
Stacks are useful keeping information about the active functions or subroutines.


* What is a queue, and when to use it  Stacks And Queues
A queue in C is basically a linear data structure to store and manipulate the data elements.
An example of programming queue is followed:
The tickets are distributed on the first-come-first-serve basis
i.e. the first one to enter is the first one to be served with the tickets.
A queue is open at both ends.

* What are the common implementations of stacks and queues
  * Array Implementation of Stack in C
    * Insertion
    * Deletion
    * Display
    * Stack Overflow
    * Stack Underflow

* What are the most common use cases of stacks and queues | Dirty plates example
Applications of Queue Data Structure | Common cases
* What is the proper way to use global variables
C - Scope Rules | Global Variables
Global variables should be used when multiple functions need to access the data or write to an
object.
For example, if you had to pass data or a reference to multiple functions such as a single log
file, a connection pool, or a hardware reference that needs to be accessed across the application.

Applications of Stacks and Queues
data structures flesh out what they are and their use-cases
  * Stacks
  * *What are they?*
Stacks are an abstract data type which are usually built on top of another data type making it an
adapter class. They can be implemented using arrays or linked lists. What makes a stack different
from a standard array and a linked list is that a stack follows the Last In, First Out (LIFO)
principle. This says that last thing added to the stack is the first thing that is going to be
removed since a stack only has two basic operations push and pop. Push adds an element to the
end of a stack and pop removes an element from the end of the stack. A good analogy is a stack
of books. You stack one book on top of another (pushing). In order to reach the first book placed
down you have to start at the last book stacked and removed every other book placed down before
it (popping).

  * *What are they used for?*
The simplest task a stack could be used for is reversing a string. Each letter in a string is
pushed in and then popped off thus reversing the string.
A more complex task is recursive descent (top-down depth first) parsing in Natural Language
Processing. The program traverses a tree following a path starting from the top most node all
the way down to a terminal node trying to match a path in a given grammar. As it traverses,
the tree the path is saved in a stack which records each movement that is made. Another task,
not too dissimilar from the one outlined above, is backtracking. Imagine a program that has to
find its way through a maze. The program comes to an intersection and chooses one direction and
continues down that path to another intersection and until it hits a dead end. How does it know
what to do next? Each decision point that is saved in the stack and if the outcome is not the
expected one the last decision point can be popped off and another path can be tried.

* Queues
  * What are they?
A queue is also an abstract data type and part of the adapter class. They are usually built on top
of the array or linked list data types as well.
Queues follow the First In First Out principle(FIFO).
Queues function exactly the same way a line at a supermarket does where someone enters the line
and the first person gets served first and everyone gets in line behind the first one
The method of adding an element to the end of a queue is called enqueue and the method
of removing an element from the beginning is called dequeue

  * What are they used for?
Queues are used in breadth-first search.

In breadth-first search, the program starts at the top node then moves down a level in the tree
and searches across all sister nodes before continuing to the next level of depth.


Requirements
-------------
### General:
-----------
* Allowed editors: `vi`, `vim`, `emacs`
* All your files will be compiled on Ubuntu 20.04 LTS using `gcc`, using the options `-Wall` `-Werror` `-Wextra` `-pedantic` `-std=c90`
* All your files should end with a new line
* A `README.md` file, at the root of the folder of the project is mandatory
* Your code should use the `Betty` style.
* You allowed to use a maximum of one global variable
* No more than 5 functions per file
* You are allowed to use the C standard library
* The prototypes of all your functions should be included in your header file called `monty.h`
* Don’t forget to push your header file
* All your header files should be include guarded

## The Monty language
--------------------
Monty 0.98 is a scripting language that is first compiled into Monty byte codes
(Just like Python). It relies on a unique stack, with specific instructions to manipulate it.
The goal of this project is to create an interpreter for Monty ByteCodes files.
### Monty byte code files

Files containing Monty byte codes usually have the `.m` extension.
Most of the industry uses this standard but it is not required by the specification
of the language. There is not more than one instruction per line. There can be any
number of spaces before or after the opcode and its argument:

```
example@ubuntu:~/monty$ cat -e bytecodes/000.m
push 0$
push 1$
push 2$
  push 3$
                   pall    $
push 4$
    push 5    $
      push    6        $
pall$
example@ubuntu:~/monty$
```

### Compilation & Output
------------------------
```
$ gcc -Wall -Werror -Wextra -pedantic -std=c90 *.c -o monty
```

### More Info
---------------
Data structures
These are the following data structures we are utilizing for this project.
You will find it in the header file.
```
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;
```

```
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
```
