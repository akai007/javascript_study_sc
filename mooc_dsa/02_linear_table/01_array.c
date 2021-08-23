#include <stdio.h>

#define LIST_INIT_SIZE 100;

typedef int ElemType;

typedef struct SqList
{
  ElemType *elem;
  int length;
  int list_size;
} SqList, *Ptr;

typedef Ptr *L;

int List_Create(L) {

}

void List_Destory(L) {

}

void List_Clear(L) {

}

void List_Empty(L) {

}

int List_Size(L) {
  return 0;
}

int List_Get(L, int pos, ElemType * e) {

}



