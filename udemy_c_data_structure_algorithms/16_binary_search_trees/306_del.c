#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
  struct TreeNode *lchild;
  int data;
  struct TreeNode *rchild;
} *root = NULL;

void insert(int x)
{
  struct TreeNode *t = root;
  struct TreeNode *p, *q;

  p = (struct TreeNode *)malloc(sizeof(struct TreeNode));
  p->data = x;
  p->lchild = NULL;
  p->rchild = NULL;

  if (root == NULL)
  {
    root = p;
    return;
  }

  while (t != NULL)
  {
    q = t;
    if (x < t->data)
      t = t->lchild;
    else if (x > t->data)
      t = t->rchild;
    else return;
  }

  if (x < q->data)
    q->lchild = p;
  else if (x > q->data)
    q->rchild = p;

  return;
}

struct TreeNode * rInsert(struct TreeNode *p, int key)
{
  struct TreeNode *t = NULL;

  if (p == NULL)
  {
    t = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    t->data = key;
    t->lchild = NULL;
    t->rchild = NULL;
    return t;
  }
  
  if (key < p->data)
    p->lchild = rInsert(p->lchild, key);
  else if (key > p->data)
    p->rchild = rInsert(p->rchild, key);
  
  return p;
}

void inorder(struct TreeNode *p)
{
  if (p != NULL)
  {
    inorder(p->lchild);
    printf("%d ", p->data);
    inorder(p->rchild);
  }
}

struct TreeNode * search(int key)
{
  struct TreeNode * t = root;
  while (t != NULL)
  {
    if (key == t->data) return t;
    else if (key < t->data) t = t->lchild;
    else t = t->rchild;
  }

  return NULL;
}

int height(struct TreeNode *p)
{
  int lCount;
  int rCount;
  if (p == NULL)
    return 0;
  
  lCount = height(p->lchild);
  rCount = height(p->rchild);
  return (lCount > rCount ? lCount : rCount) + 1;
}

struct TreeNode * inPre(struct TreeNode *p)
{
  while (p && p->rchild != NULL)
  {
    p = p->rchild;
  }

  return p;
}

struct TreeNode * inSucc(struct TreeNode *p)
{
  while (p && p->lchild != NULL)
  {
    p = p->lchild;
  }

  return p;
}

struct TreeNode * del(struct TreeNode *p, int key)
{
  struct TreeNode *q;

  if (p == NULL)
  {
    return NULL;
  }

  if (p->lchild == NULL && p->rchild == NULL)
  {
    if (p == root)
      root = NULL;
    free(p);
    return NULL;
  }
  
  if (key < p->data)
    p->lchild = del(p->lchild, key);
  else if (key > p->data)
    p->rchild = del(p->rchild, key);
  else
  {
    if (height(p->lchild) > height(p->rchild))
    {
      q = inPre(p->lchild);
      p->data = q->data;
      p->lchild = del(p->lchild, q->data);
    }
    else
    {
      q = inSucc(p->rchild);
      p->data = q->data;
      p->rchild = del(p->rchild, q->data);
    }
    
  }

  return p;
}

int main(int argc, char const *argv[])
{
  int p[] = {9, 15, 5, 20, 16, 8, 12, 3, 6};

  for (int i = 0; i < 3; i++)
  {
    insert(p[i]);
  }
  for (int j = 3; j < 9; j++)
  {
    rInsert(root, p[j]);
  }
  

  inorder(root);
  printf("\n");


  del(root, 20);
  inorder(root);
  printf("\n");

  struct TreeNode *s = search(20);
  if (s != NULL)
    printf("Key 20 is fund. \n");
  else
    printf("Key 20 not fund. \n");

  return 0;
}
