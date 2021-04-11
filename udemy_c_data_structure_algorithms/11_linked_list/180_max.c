#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node * next;
} *first = NULL;

void create(int *arr, int n)
{
  struct Node *t, *last;
  first = (struct Node *)malloc(sizeof(struct Node));
  first->data = arr[0];
  first->next = NULL;
  last = first;

  int i = 1;
  while (i < n)
  {
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = arr[i];
    t->next = NULL;
    last->next = t;
    last = t;
    i++;
  }
}

int max(struct Node *p)
{
  int max = INT32_MIN;
  while (p != NULL)
  {
    if (p->data > max)
    {
      max = p->data;
    }
    p = p->next;
  }

  return max;
  
}

int maxR(struct Node *p)
{
  int x = 0;

  if (p == 0)
  {
    return INT32_MIN;
  }
  x = maxR(p->next);
  if (x > p->data)
  {
    return x;
  }
  else
    return p->data;
  
}

void printList(struct Node *p)
{
  while (p != NULL)
  {
    printf("%d ", p->data);
    p = p->next;
  }
  printf("\n");
}

int main(int argc, char const *argv[])
{
  int A[] = {2, 3, 5, 7, 11, 13, 17};
  create(A, 7);

  printList(first);
  // printf("max: %d \n", max(first));
  printf("max: %d \n", maxR(first));

  return 0;
}
