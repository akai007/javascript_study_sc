#include <stdio.h>
#include <stdlib.h>

#define LIST_INIT_SIZE 100;

enum Status {OK = 1, FAIL = 0};

typedef int ElemType;

struct ArrayList {
  ElemType * list;
  int length;
  int size;
};

enum Status InitList(struct ArrayList *arrayList, ElemType arr[], int len)
{
  int size = LIST_INIT_SIZE;
  if (len > size)return FAIL;
  
  ElemType * list = (ElemType *)malloc(sizeof(ElemType)*size);
  for (int i = 0; i < len; i++)
  {
    list[i] = arr[i];
  }

  arrayList->list = list;
  arrayList->size = size;
  arrayList->length = len;

  return OK;
}

void DisplayList(struct ArrayList arrayList)
{
  for (int i = 0; i < arrayList.length; i++)
  {
    printf("%d ", arrayList.list[i]);
  }
  printf("\n");
  
}


int main(int argc, char const *argv[])
{
  ElemType arr[] = {2, 3, 5, 7, 11, 13};

  struct ArrayList arrayList;
  InitList(&arrayList, arr, sizeof(arr)/sizeof(arr[0]));

  DisplayList(arrayList);

  return 0;
}
