#include <stdio.h>
#include <stdlib.h>

struct Queue
{
  int front;
  int rear;
  int size;
  int *Q;
};

void create(struct Queue *q, int size)
{
  q->size = size;
  q->front = q->rear = 0;
  q->Q = (int *)malloc(q->size * sizeof(int));
}

int isEmpty(struct Queue *q)
{
  if (q->front == q->rear)
  {
    return 1;
  }
  return 0;
}

int isFull(struct Queue *q)
{
  if ((q->rear+1) % q->size == q->front)
  {
    return 1;
  }
  return 0;
}

void enqueue(struct Queue *q, int x)
{
  if (isFull(q))
  {
    printf("Queue is Full \n");
  }
  else
  {
    q->rear = (q->rear+1) % q->size;
    q->Q[q->rear] = x;
  }

}


int dequeue(struct Queue *q)
{
  int x = -1;
  if (isEmpty(q))
  {
    printf("Queue is Empty \n");
  }
  else
  {
    x = q->Q[q->front];
    q->front = (q->front+1) % q->size;
  }
  
  return x;
}

void printQueue(struct Queue *q)
{
  int i = q->front + 1;

  do
  {
    printf("%d ", q->Q[i]);
    i = (i+1) % q->size;
  } while (i!= (q->rear+1) % q->size);
  
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
