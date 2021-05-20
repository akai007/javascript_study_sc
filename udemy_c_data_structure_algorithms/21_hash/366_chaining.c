#include <stdio.h>
#include "_linked_list.h"

int hash(int key)
{
  return key % 10;
}

void hashInsert(struct Node *H[], int key)
{
  int index = hash(key);
  linkedList_sortedInsert(&H[index], key);
}

int main(int argc, char const *argv[])
{
  struct Node *HT[10];
  for (int i = 0; i < 10; i++)
  {
    HT[i] = NULL;
  }

  hashInsert(HT, 12);
  hashInsert(HT, 22);
  hashInsert(HT, 42);

  struct Node * t = linkedList_serch(HT[hash(22)], 22);

  printf("%d ",t->data);

  return 0;
}
