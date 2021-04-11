#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node * next;
} *first = NULL, *second = NULL;

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

void printList(struct Node *p)
{
  while (p != NULL)
  {
    printf("%d ", p->data);
    p = p->next;
  }
  printf("\n");
}

int isLoop(struct Node * p1)
{
  struct Node *cursor1, *cursor2;

  cursor1 = p1;
  cursor2 = p1;

  do
  {
    cursor1 = cursor1->next;
    cursor2 = cursor2->next;
    cursor2 = cursor2 ? cursor2->next : NULL;
  } while (cursor1 && cursor2 && cursor1 != cursor2);
  
  if (cursor1 == cursor2)
    return 1;
  else
    return 0;
}

int main(int argc, char const *argv[])
{
  int A[] = {2, 3, 5, 7, 11, 13, 17};
  create(A, 7);

  printf("%d \n", isLoop(first));

  free(first);
  first = NULL;
  int B[] = {2, 3, 5, 7, 11, 13, 17};
  create(B, 7);
  first->next->next->next->next->next->next = first->next->next->next;
  printf("%d \n", isLoop(first));

  return 0;
}
