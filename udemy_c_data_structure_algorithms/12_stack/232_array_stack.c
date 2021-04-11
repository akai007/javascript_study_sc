#include <stdio.h>
#include <stdlib.h>

struct Stack
{
  int top;
  int size;
  int *S;
};

void create(struct Stack *st)
{
  // printf("Please Enter Size: ");
  st->top = -1;
  // scanf("%d", &(st->size));
  st->size = 5;
  st->S = (int *)malloc(st->size * sizeof(int));

}

void printStack(struct Stack *st)
{
  for (int i = st->top; i > -1; i--)
  {
    printf("%d ", st->S[i]);
  }
  printf("\n");
  
}

void push(struct Stack *st, int x)
{
  if (st->size >= st->top + 1)
  {
    st->top = st->top+1;
    st->S[st->top] = x;
  }
}

int pop(struct Stack *st)
{
  int x = -1;
  if (st->top != -1)
  {
    x = st->S[st->top];
    st->top = st->top - 1;
  }

  return x;
}

int peek(struct Stack *st, int index)
{
  int x = -1;
  if (st->top != -1)
  {
    x = st->S[index - st->top + 1];
  }
  
  return x;
}

int isEmpty(struct Stack *st)
{
  int flag = 0;
  if (st->top != -1)
  {
    flag = 1;
  }
  
  return flag;
}

int stackTop(struct Stack *st)
{
  if (!isEmpty(st))
    return st->S[st->top];
  return -1;
}

int isFull(struct Stack *st)
{
  int flag = 0;
  if (st->top == st->size-1)
  {
    flag = 1;
  }
  
  return flag;
}

int main(int argc, char const *argv[])
{
  struct Stack st;
  create(&st);

  push(&st, 2);
  push(&st, 3);
  push(&st, 5);
  push(&st, 7);
  push(&st, 11);
  push(&st, 13);
  push(&st, 17);
  printStack(&st);

  pop(&st);
  printStack(&st);

  return 0;
}
