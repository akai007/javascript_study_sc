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
    else if (key > t->data) t = t->rchild;
  }

  return NULL;
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

  struct TreeNode *s = search(20);

  if (s != NULL)
    printf("Key 20 is fund. \n");
  else
    printf("Key 20 not fund. \n");

  return 0;
}
