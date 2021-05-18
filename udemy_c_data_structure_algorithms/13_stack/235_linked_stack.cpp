#include <iostream>

using namespace std;


class Node
{
  public:
    int data;
    struct Node *next;
};

class LinkedStack
{
private:
  struct Node *top;
public:
  LinkedStack();
  ~LinkedStack();
  void push(int x);
  int pop();
  void printStack();
};

LinkedStack::LinkedStack()
{
  top = NULL;
}

LinkedStack::~LinkedStack()
{
}


void LinkedStack::push(int x)
{
  Node *t = new Node;

  if (t == NULL)
    cout<<"stack is full "<<endl;
  
  t->data = x;
  t->next = top;
  top = t;
}

int LinkedStack::pop()
{
  struct Node *t;
  int x = -1;

  if (top == NULL)
    cout<<"stack is empty"<<endl;
  else
  {
    t = top;
    top = top->next;
    x = t->data;
    delete t;
  }
  
  return x;
}

void LinkedStack::printStack()
{
  struct Node *p;
  p = top;
  while (p != NULL)
  {
    cout<<p->data<<" ";
    p = p->next;
  }
  cout<<endl;
  
}

int main(int argc, char const *argv[])
{
  LinkedStack ls;
  ls.push(2);
  ls.push(3);
  ls.push(5);
  ls.push(7);
  ls.push(11);
  ls.push(13);
  
  ls.printStack();
  ls.pop();
  ls.printStack();
  
  return 0;
}
