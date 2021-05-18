#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;
class Stack
{
private:
  int top;
  int size;
  int *S;
public:
  Stack(int size);
  ~Stack();
  void printStack();
  void push(int x);
  int pop();
  int peek(int index);
  int isEmpty();
  int stackTop();
  int isFull();
};

Stack::Stack(int size)
{

  this->top = -1;
  this->size = size;
  this->S = (int *)malloc(this->size * sizeof(int));
}

Stack::~Stack()
{
}

void Stack::printStack()
{
  for (int i = top; i > -1; i--)
  {
    printf("%d ", S[i]);
  }
  printf("\n");
}

void Stack::push(int x)
{
  if (size >= top + 1)
  {
    top = top+1;
    S[top] = x;
  }
}


int Stack::pop()
{
  int x = -1;
  if (top != -1)
  {
    x = S[top];
    top = top - 1;
  }

  return x;
}


int Stack::peek(int index)
{
  int x = -1;
  if (top != -1)
  {
    x = S[index - top + 1];
  }
  
  return x;
}


int Stack::isEmpty()
{
  int flag = 0;
  if (top != -1)
  {
    flag = 1;
  }
  
  return flag;
}


int Stack::stackTop()
{
  if (!isEmpty())
    return S[top];
  return -1;
}

int Stack::isFull()
{
  int flag = 0;
  if (top == size-1)
  {
    flag = 1;
  }
  
  return flag;
}

int main(int argc, char const *argv[])
{
  struct Stack *st = new Stack(7);

  st->push(2);
  st->push(3);
  st->push(5);
  st->push(7);
  st->push(11);
  st->push(13);
  st->push(17);
  st->printStack();

  st->pop();
  st->printStack();

  return 0;
}
