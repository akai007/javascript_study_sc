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

enum Status InitList(struct ArrayList *L, ElemType arr[], int len)
{
  int size = LIST_INIT_SIZE;
  if (len > size)return ERROR;
  
  ElemType * list = (ElemType *)malloc(sizeof(ElemType)*size);
  for (int i = 0; i < len; i++)
  {
    list[i] = arr[i];
  }

  L->list = list;
  L->size = size;
  L->length = len;

  return OK;
}

void DisplayList(struct ArrayList L)
{
  for (int i = 0; i < L.length; i++)
  {
    printf("%d ", L.list[i]);
  }
  printf("\n");
  
}

enum Status ListInsert(struct ArrayList *L, int index, ElemType e)
{
  // check index range
  if ( index < 0 || index >= L->size ) return ERROR;

  // expand array when full
  if (L->length >= L->size)
  {
    int listIncrement = LIST_INCREMENT;
    ElemType * expandList = (ElemType *)realloc(L->list, (L->size + listIncrement) * sizeof(ElemType));

    L->list = expandList;
    L->size += listIncrement;
  }
  
  for (int i = L->length; i >= index; i--)
  {
    L->list[i+1] = L->list[i];
  }

  L->list[index] = e;
  L->length++;
  
  return OK;
}

enum Status ListConcat(struct ArrayList *L, struct ArrayList *appadingList)
{
  return OK;
}

enum Status ListSortedInsert(struct ArrayList *L, ElemType e)
{
  // find sorted index
  int index = 0;
  while(index < L->length)
  {
    if (e <= L->list[index]) break;

    index++;
  }
  
  return ListInsert(L, index, e);
}

enum Status ListSortedConcat(struct ArrayList *L, struct ArrayList *appadingList)
{
  int sortedListLength = L->length + appadingList->length;
  ElemType * sortedList = (ElemType *)malloc(sizeof(ElemType) * (sortedListLength));

  
  return OK;
}


int test()
{
  ElemType arr[] = {2, 3, 5, 7, 11, 13};

  struct ArrayList L;
  InitList(&L, arr, sizeof(arr)/sizeof(arr[0]));
  DisplayList(L);

  // ListInsert(&L, 0, 0);
  // DisplayList(L);
  // ListInsert(&L, 2, 2);
  // DisplayList(L);
  // ListInsert(&L, 4, 4);
  // DisplayList(L);
  // ListInsert(&L, 6, 6);
  // DisplayList(L);
  // ListInsert(&L, 8, 8);
  // DisplayList(L);

  ListSortedInsert(&L, 8);
  ListSortedInsert(&L, 6);
  ListSortedInsert(&L, 4);
  ListSortedInsert(&L, 0);
  DisplayList(L);

  return 0;
}

// int main(int argc, char const *argv[])
// {
//   test();
//   return 0;
// }
