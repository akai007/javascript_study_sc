#include <iostream>
#include "_trees_queue_stack.h"

using namespace std;

class BinaryTree
{
public:
  TreeNode *root;
  BinaryTree();
  ~BinaryTree();
  void createTree();
  void preorder(){preorder(root);}
  void preorder(TreeNode *p);
  void postorder(){postorder(root);}
  void postorder(TreeNode *p);
  void inorder(){inorder(root);}
  void inorder(TreeNode *p);
  void levelorder(){levelorder(root);}
  void levelorder(TreeNode *p);
  int height(){return height(root);}
  int height(TreeNode *root);
  int count(){return count(root);}
  int count(TreeNode *root);
  void insert(int key) { insert(root, key); };
  TreeNode * insert(TreeNode *p, int key);
};

BinaryTree::BinaryTree()
{
  root = nullptr;
}

BinaryTree::~BinaryTree()
{
  // TODO
}

void BinaryTree::createTree()
{
  struct TreeNode *p, *t;
  TreeQueue q; 
  int x;
  cout<<"Enter root value: ";
  cin>>x;
  root = new TreeNode;
  root->data = x;
  root->lchild = nullptr;
  root->rchild = nullptr;
  q.enqueue(root);

  while (!q.isEmpty())
  {
    p = q.dequeue();
    cout<<"Enter "<<p->data<<"'s left child: ";
    cin>>x;
    if (x!=-1)
    {
      t = new TreeNode;
      t->data = x;
      t->lchild = nullptr;
      t->rchild = nullptr;
      p->lchild = t;
      q.enqueue(t);
    }
    cout<<"Enter "<<p->data<<"'s right child: ";
    cin>>x;
    if (x!=-1)
    {
      t = new TreeNode;
      t->data = x;
      t->lchild = nullptr;
      t->rchild = nullptr;
      p->rchild = t;
      q.enqueue(t);
    }
  }
}

void BinaryTree::preorder(struct TreeNode *r)
{
  TreeStack *ts = new TreeStack;
  while (r != nullptr || !ts->isEmpty() )
  {
    if (r != nullptr) {
      cout<<r->data<<" ";
      ts->push(r);
      r = r->lchild;
    } else {
      r = ts->pop();
      r = r->rchild;
    }
  }
}

void BinaryTree::inorder(struct TreeNode *r)
{
  TreeStack *ts = new TreeStack;
  while (r != nullptr || !ts->isEmpty() )
  {
    if (r != nullptr) {
      ts->push(r);
      r = r->lchild;
    } else {
      r = ts->pop();
      cout<<r->data<<" ";
      r = r->rchild;
    }
  }
}

void BinaryTree::postorder(struct TreeNode *r)
{

  TreeStack *ts = new TreeStack;
  TreeNode *t;
  
  while (r != nullptr || !ts->isEmpty() )
  {
    if (r != nullptr) {
      ts->push(r);
      r = r->lchild;
    } else {
      t = ts->pop();

      if (t->data > 0) {
        t->data = - (t->data);
        ts->push(t);
        r = t->rchild;
      } else {
        cout<<( - (t->data) )<<" ";
        t = nullptr;
      }
    }
  }
}

void BinaryTree::levelorder(TreeNode *r)
{
  TreeQueue *q = new TreeQueue;

  q->enqueue(r);
  cout<<r->data<<" ";

  while (!q->isEmpty())
  {
    r = q->dequeue();
    if (r->lchild)
    {
      cout<<r->lchild->data<<" ";
      q->enqueue(r->lchild);
    }
    if (r->rchild)
    {
      cout<<r->rchild->data<<" ";
      q->enqueue(r->rchild);
    }
  }
  
  cout<<endl;
}

int BinaryTree::height(struct TreeNode * r)
{
  int lCount, rCount;
  if (r == nullptr) return 0;

  lCount = height(r->lchild);
  rCount = height(r->rchild);

  if (lCount > rCount)
    return lCount + 1;
  else
    return rCount + 1;
}

int BinaryTree::count(struct TreeNode * r){
  int lCount;
  int rCount;
  if (r != nullptr) {
    lCount = count(r->lchild);
    rCount = count(r->rchild);
    
    return lCount + rCount + 1;
  }
  return 0;
}

TreeNode * BinaryTree::insert(TreeNode *p, int key) {
  TreeNode *tn = new TreeNode;

  if (p == nullptr) {
    tn->data = key;
    tn->lchild = nullptr;
    tn->rchild = nullptr;
    return tn;
  }

  if (key < p->data)
    p->lchild = insert(p->lchild, key);
  else if (key > p->data)
    p->rchild = insert(p->rchild, key);
  
  return p;
}

int main(int argc, char const *argv[])
{
  BinaryTree *bi = new BinaryTree;
  bi->createTree();
  bi->insert(5);

  bi->levelorder();

  cout<<bi->count()<<endl;

  return 0;
}