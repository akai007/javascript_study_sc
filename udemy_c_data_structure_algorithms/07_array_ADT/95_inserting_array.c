#include <stdio.h>

struct Array
{
  int A[20];
  int size;
  int length;
};

void display(struct Array * arr)
{
  printf("size: %d, length: %d \n", arr->size, arr->length);
  for (int i = 0; i < arr->length; i++)
  {
    printf("%d ", arr->A[i]);
  }
  printf("\n");
  
}

void append(struct Array * arr, int num)
{
  if (arr->length < arr->size) {
    arr->A[arr->length] = num;
    arr->length++;
  } else {
    printf("Array is full");
  }
}

void insert(struct Array * arr, int index, int num)
{
  if (arr->length >= arr->size)
  {
    printf("");
    return;
  }
  for (int i = arr->length; i > index; i--)
  {
    arr->A[i] = arr->A[i-1];
  }
  arr->A[index] = num;
  arr->length++;
}

int main(int argc, char const *argv[])
{
  struct Array arr = {{1, 2, 3, 4, 5}, 20, 5};
  
  display(&arr);
  append(&arr, 6);
  display(&arr);

  insert(&arr, 2, 8);
  display(&arr);

  return 0;
}
