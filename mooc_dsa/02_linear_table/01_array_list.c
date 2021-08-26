#include <stdio.h>
#include <stdlib.h>

#define LIST_INIT_SIZE 100;

typedef int DataType;

struct ArrayList
{
  int * arr;
  int length;
  int list_size;
};

struct ArrayList List_Create(int arr[], int len) {
  struct ArrayList arrayList;
  arrayList.length = len;
  arrayList.arr = (int *)malloc(sizeof(int) * arrayList.length);
  
  for (int i = 0; i < arrayList.length; i++)
  {
    arrayList.arr[i] = arr[i];
  }

  return arrayList;
}

void List_Display(struct ArrayList arrayList) {
  for (int i = 0; i < arrayList.length; i++) {
    printf("%d \t", arrayList.arr[i]);
  }
  printf("\n");
}

void List_Destory(struct ArrayList arrayList) {
  free(arrayList.arr);
}

void List_Clear(struct ArrayList arrayList) {
  for (int i = 0; i < arrayList.length; i++)
  {
    arrayList[i] = 0;
  }
  arrayList.length = 0;
}

// void List_Empty(L) {

// }

// int List_Size(L) {
//   return 0;
// }

int List_Get(struct ArrayList arrayList, int index, ElemType * e) {

}


int main(int argc, char const *argv[])
{
  
  int arr [5] = {2, 3, 5, 7, 11};
  struct ArrayList arrayList = List_Create(arr, sizeof(arr) / sizeof(arr[0]));
  
  List_Display(arrayList);

  return 0;
}




