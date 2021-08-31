#include "./array.c"

struct Stack
{
  struct ArrayList * L
}

void push(struct ArrayList * L, ElemType e)
{
  // L.
}

int main(int argc, char const *argv[])
{
  ElemType arr[] = {};

  struct ArrayList L;
  InitList(&L, arr, sizeof(arr)/sizeof(arr[0]));
  DisplayList(L);

  return 0;
}
