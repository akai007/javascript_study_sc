#include <stdio.h>
#include <stdlib.h>

struct Queue
{
  int size;
  int front;
  int rear;
  int *Q;
};

void create(struct Queue *q, int size)
{
  q->size = size;
  q->front = q->rear = -1;
  q->Q = (int *)malloc(q->size * sizeof(int));
}

void enqueue(struct Queue *q, int x)
{
  if (q->rear == q->front && q->rear != -1)
  {
    printf("Queue is Full");
  }
  else
  {
    q->rear++;
    q->Q[q->rear] = x;
  }
}

int dequeue(struct Queue *q)
{
  int x = -1;
  if (q->rear == q->front)
  {
    printf("Queue is Empty");
  }
  else
  {
    q->front++;
    x = q->Q[q->front];
  }

  return x;
}

void printQueue(struct Queue *q)
{
  for (int i = q->front+1; i <= q->rear; i++)
  {
    printf("%d ", q->Q[i]);
  }
  printf("\n");

}

int main(int argc, char const *argv[])
{
  struct Queue q;
  create(&q, 6);

  enqueue(&q, 2);
  enqueue(&q, 3);
  enqueue(&q, 5);
  enqueue(&q, 7);
  printQueue(&q);

  dequeue(&q);
  printQueue(&q);
  
  return 0;
}