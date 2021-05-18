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
};

BinaryTree::BinaryTree()
{
  root = NULL;
}

BinaryTree::~BinaryTree()
{
  // TODO
}

void BinaryTree::createTree()
{
  struct TreeNode *p, *t;
  TreeQueue *q = new TreeQueue; 
  int x;
  cout<<"Enter root value: ";
  cin>>x;
  root = new TreeNode;
  root->data = x;
  root->lchild = root->rchild = NULL;
  q->enqueue(root);

  while (!q->isEmpty())
  {
    p = q->dequeue();
    cout<<"Enter "<<p->data<<"'s left child: ";
    cin>>x;
    if (x!=-1)
    {
      t = new TreeNode;
      t->data = x;
      t->lchild = t->rchild = NULL;
      p->lchild = t;
      q->enqueue(t);
    }
    cout<<"Enter "<<p->data<<"'s right child: ";
    cin>>x;
    if (x!=-1)
    {
      t = new TreeNode;
      t->data = x;
      t->lchild = t->rchild = NULL;
      p->rchild = t;
      q->enqueue(t);
    }
  }
}

int BinaryTree::height(struct TreeNode * r)
{
  int lCount, rCount;
  if (r == NULL) return 0;

  lCount = height(r->lchild);
  rCount = height(r->rchild);

  if (lCount > rCount)
    return lCount + 1;
  else
    return rCount + 1;
}

void BinaryTree::preorder(struct TreeNode *r)
{
  TreeStack *ts = new TreeStack;
  while (r != NULL || !ts->isEmpty() )
  {
    if (r != NULL) {
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
  while (r != NULL || !ts->isEmpty() )
  {
    if (r != NULL) {
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
  
  while (r != NULL || !ts->isEmpty() )
  {
    if (r != NULL) {
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
        t = NULL;
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

int main(int argc, char const *argv[])
{
  BinaryTree *bi = new BinaryTree;
  bi->createTree();

  bi->preorder();
  cout<<endl;
  bi->inorder();
  cout<<endl;
  bi->postorder();
  cout<<endl;
  // bi->levelorder();

  cout<<bi->height()<<endl;

  return 0;
}