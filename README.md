## Assignment: Queue
 To implement the Queue data structure using a Linked List.

```
typedef struct queue{
NODEPTR front, rear;
} QUEUE;
insert(QUEUE q, elm);
delete(QUEUE q);
printQueue(QUEUE q);
```
* Write a C program that will have a simple menu in main to execute the tasks insert, delete and print.
* The node pointers front and rear are to be encapsulated in a queue structure, i.e., front and rear won’t be
accessed while calling a function, only queue will be referred. The front and rear will only be accessed
inside the functions.
* Use pointers/addresses properly, i.e., the structure and the function prototypes written above may not work
exactly in the same form and you may need to modify them accordingly.
* The code should me commented.
* The output of at least two different runs should be provided.
