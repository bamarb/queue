#include <stdio.h>  /* required for printf */
#include <stdlib.h> /* needed for malloc */

/* NOTE: if you are using linux you need to run <gcc queue.c -o queue> */
/* You can then execute the program by running ./queue */

/* Define the linked list node struct having data (info) & a pointer to the next element */
struct node {
  int info;
  struct node *next;
};

/* Alias a pointer to struct node as NODEPTR */
typedef struct node* NODEPTR;

/* Define the queue struct aliased as QUEUE */
typedef struct queue {
  NODEPTR rear;
  NODEPTR front;
} QUEUE;

/* The assignment asks us to implement insert, delete and printQueue */
/* The prototypes for the functions provided already encapsulate the QUEUE struct */
/* i.e you are delaing with QUEUE not exposing the internals */

/* Creates the root/starting node of the linked list */
NODEPTR  createNode(int data) {
  /* We need to malloc memory since the stack gets destroyed after the function ends */
    NODEPTR nptr = (NODEPTR) malloc(sizeof(struct node));
    nptr->info = data;
    nptr->next = NULL;
    return nptr;
}

/* create a new (empty) Queue, and get a pointer to it*/
QUEUE* initQueue() {
   QUEUE *q = (QUEUE *) malloc(sizeof(QUEUE));
   q->front = NULL;
   q->rear = NULL;
   return q;
}

int isEmpty(QUEUE *q) {
  if ((q->rear == NULL) && (q->front == NULL)) return 1;
  return 0;
}

/* Get the length or number of items int the queue*/
int len(QUEUE *q) {
  /* n stores the number of items in the queue */
  int n = 0;
  NODEPTR node = q->front;
  while (NULL != node) {
    n = n + 1;
    node = node->next;
  }
  return n;
}


/* NOTE: The element type is not given in homework so assume int */

/* insert, inserts an element to the rear of the queue */
void insert(QUEUE *q,int elm) {
   /* Create the Linked List Node */
    NODEPTR node = createNode(elm);
   /* Check if the queue is Empty */
    if (isEmpty(q)) {
      q->rear = node;
      q->front = node;
      return;
    }
    q->rear->next = node;
    q->rear = node;
}


/* delete , remove an item from the front of the queue and return it's value */
/* We store items in the rear of the queue and remove items from the front */
void delete(QUEUE *q) {
  /* There is nothing to remove */
  if (q->front == NULL) {
     return;
  }
  NODEPTR node = q->front;
  /* The new front of the queue */
  q->front = node->next;
  if (NULL != node) {
    printf("Removing node with Data:%d\n",node->info);

  }
  /* If after removing the node the queue becomes empty reset rear pointer */
  if (NULL == q->front) {
    q->rear = NULL;
  }
  /* Clean up Memory allocated by the node */
  free(node);
}

void printQueue(QUEUE *q) {
  if (isEmpty(q)) {
    printf("Queue is empty nothing to print\n");
    return;
  }
  printf("Q->Rear:%p , Q->Front:%p\n",q->rear, q->front);

  NODEPTR node = q->rear;
  while(NULL != node) {
    printf("Node: Data->%d, next:%p\n",node->info,node->next);
    node = node -> next;
  }
}

int main() {
  printf("Queue program starting\n");

  printf("Creating a new  empty queue\n");
  QUEUE *q = initQueue();
  printf("Items in the Queue:%d\n",len(q));
  printQueue(q);

  printf("Insert Element 1 to the Queue\n");
  insert(q,1);
  NODEPTR root = q->rear;

  printf("Items in the Queue:%d\n",len(q));
  printQueue(q);

  printf("Insert Element 2 to the Queue\n");
  insert(q,2);
  printf("Items in the Queue:%d\n",len(q));
  printQueue(q);

  printf("Insert Element 3 to the Queue\n");
  insert(q,3);
  printf("Items in the Queue:%d\n",len(q));
  printQueue(q);
  /* Removing items from the queue */  

  delete(q);
  printQueue(q);

  delete(q);
  printQueue(q);

  delete(q);
  printQueue(q);

  printf("Queue program done\n");
  return 0;
}
