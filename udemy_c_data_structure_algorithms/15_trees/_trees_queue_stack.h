#include <iostream>
#include <stdio.h>
#include "./_tree_node.h"

using namespace std;

class QNode
{
public:
  TreeNode *data;
  QNode *next;
};

class TreeQueue
{
private:
  QNode *front;
  QNode *rear;

public:
  TreeQueue();
  ~TreeQueue();
  bool isEmpty();
  void enqueue(TreeNode *x);
  TreeNode * dequeue();
  void printQueue();
};

class SNode
{
public:
  TreeNode *data;
  SNode *next;
};

class TreeStack {
private:
  SNode *top;
public:
  TreeStack();
  ~TreeStack();
  bool isEmpty();
  TreeNode * pop();
  void push(TreeNode *r);
  void push(TreeNode *r, int flag);
  void printStack();
};

TreeQueue::TreeQueue() {
  front = nullptr;
  rear = nullptr;
}

TreeQueue::~TreeQueue() {
}


bool TreeQueue::isEmpty() {
  return front == nullptr;
}

void TreeQueue::enqueue(TreeNode *x) {
  QNode *t = new QNode;
  if (t == nullptr)
  {
    cout<<"Queue is Full"<<endl;
    return;
  }
  
  t->data = x;
  t->next = nullptr;
  if (front == nullptr)
  {
    front = rear = t;
  }
  else
  {
    rear->next = t;
    rear = t;
  }
  
}

TreeNode * TreeQueue::dequeue() {
  struct QNode *t;
  struct TreeNode *x = nullptr;

  if (!isEmpty())
  {
    x = front->data;
    t = front;
    front = front->next;
    free(t);
  }
  
  return x;
}

void TreeQueue::printQueue() {
  QNode *p = front;
  while (p != nullptr)
  {
    cout<<p->data<<" ";
    p = p->next;
  }
  cout<<endl;
  
}


TreeStack::TreeStack() {
  top = nullptr;
}

TreeStack::~TreeStack()
{
  SNode *t;
  while (top != nullptr)
  {
    t = top;
    top = top->next;
    delete t;
  }
}

void TreeStack::push(TreeNode *r) {
  SNode *t = new SNode;

  if (t == nullptr)
    cout<<"stack is full "<<endl;
  
  t->data = r;
  t->next = top;
  top = t;
}

bool TreeStack::isEmpty() {
  return top == nullptr;
}

TreeNode * TreeStack::pop()
{
  SNode *t;
  TreeNode *x = nullptr;

  if (isEmpty())
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

void TreeStack::printStack()
{
  SNode *p;
  p = top;
  while (p != nullptr)
  {
    cout<<p->data<<" ";
    p = p->next;
  }
  cout<<endl;
  
}