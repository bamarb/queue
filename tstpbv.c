#include <stdio.h>
#include <stdlib.h> 


struct node {
  int n;
  struct node *next;
};

void displayNode(struct node n) {
  printf("Received Node: val=%d, next=%p\n",n.n,n.next);
}

int main() {
   struct node n1 = { 1 , NULL};
   struct node n0 = { 0 , &n1};
   printf("Addr of n1 = %p\n",n0.next);
   displayNode(n0);
}
