#include <stdio.h>

struct Array
{
  int A[20];
  int size;
  int length;
};

void swap(int *x, int *y) {
  int t;

  t = *x;
  *x = *y;
  *y = t;
}

int linearSearch(struct Array *arr, int num)
{
  for (int i = 0; i < arr->length; i++)
  {
    if (arr->A[i] == num) {
      return i;
    }
  }
  
  return -1;
}

int linearSearchTranspotion(struct Array *arr, int num)
{
  for (int i = 0; i < arr->length; i++)
  {
    if (arr->A[i] == num) {
      swap(&arr->A[i], &arr->A[i-1]);
      return i-1;
    }
  }
  
  return -1;
}

int linearSearchTop(struct Array *arr, int num)
{
  for (int i = 0; i < arr->length; i++)
  {
    if (arr->A[i] == num) {
      swap(&arr->A[0], &arr->A[i]);

      return 0;
    }
  }
  
  return -1;
}



int main(int argc, char const *argv[])
{

  struct Array arr = {{1, 2, 3, 4, 5}, 20, 5};
  
  printf("%d ", linearSearch(&arr, 5));
  printf("%d ", linearSearch(&arr, 8));

  printf("\n");
  printf("%d ", linearSearchTranspotion(&arr, 5));
  printf("%d ", linearSearchTranspotion(&arr, 8));

  printf("\n");
  printf("%d ", linearSearchTop(&arr, 5));
  printf("%d ", linearSearchTop(&arr, 8));

  return 0;
}
