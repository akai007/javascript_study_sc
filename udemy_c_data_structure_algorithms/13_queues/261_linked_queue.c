#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
  int data;
  struct Node *next;
} *front=NULL, *rear=NULL;

bool isEmpty()
{
  return front == NULL;
}

void enqueue(int x)
{
  struct Node *t = (struct Node *)malloc(sizeof(struct Node));
  if (t == NULL)
  {
    printf("Queue is Full \n");
    return;
  }
  
  t->data = x;
  t->next = NULL;
  if (front == NULL)
  {
    front = rear = t;
  }
  else
  {
    rear->next = t;
    rear = t;
  }
  
}

int dequeue()
{
  struct Node *t;
  int x = -1;

  if (!isEmpty())
  {
    x = front->data;
    t = front;
    front = front->next;
    free(t);
  }
  
  return x;
}

void printQueue()
{
  struct Node *p = front;
  while (p != NULL)
  {
    printf("%d ", p->data);
    p = p->next;
  }
  printf("\n");
  
}

int main(int argc, char const *argv[])
{

  enqueue(2);
  enqueue(3);
  enqueue(5);
  enqueue(7);
  printQueue();

  dequeue();
  printQueue();
  
  return 0;
}
