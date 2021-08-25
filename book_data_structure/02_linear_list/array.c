#include <stdio.h>
#include <stdlib.h>

#define LIST_INIT_SIZE 10;
#define LIST_INCREMENT 10;

enum Status {ERROR = 0, OK = 1};

typedef int ElemType;

struct ArrayList {
  ElemType * list;
  int length;
  int size;
};

enum Status InitList(struct ArrayList *arrayList, ElemType arr[], int len)
{
  int size = LIST_INIT_SIZE;
  if (len > size)return ERROR;
  
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

enum Status ListInsert(struct ArrayList *arrayList, int index, ElemType e)
{
  // check index range
  if ( index < 0 || index >= arrayList->size ) return ERROR;

  // expand array
  if (arrayList->length >= arrayList->size)
  {
    int listIncrement = LIST_INCREMENT;
    ElemType * expandList = (ElemType *)realloc(arrayList->list, (arrayList->size + listIncrement) * sizeof(ElemType));

    arrayList->list = expandList;
    arrayList->size += listIncrement;
  }
  
  for (int i = arrayList->length; i >= index; i--)
  {
    arrayList->list[i+1] = arrayList->list[i];
  }

  arrayList->list[index] = e;
  arrayList->length++;
  
  return OK;
}


int main(int argc, char const *argv[])
{
  ElemType arr[] = {2, 3, 5, 7, 11, 13};

  struct ArrayList arrayList;
  InitList(&arrayList, arr, sizeof(arr)/sizeof(arr[0]));
  DisplayList(arrayList);

  ListInsert(&arrayList, 0, 0);
  DisplayList(arrayList);
  ListInsert(&arrayList, 2, 2);
  DisplayList(arrayList);
  ListInsert(&arrayList, 4, 4);
  DisplayList(arrayList);
  ListInsert(&arrayList, 6, 6);
  DisplayList(arrayList);
  ListInsert(&arrayList, 8, 8);
  DisplayList(arrayList);

  return 0;
}
