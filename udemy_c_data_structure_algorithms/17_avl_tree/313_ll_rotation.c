#include <stdio.h>
#include <stdlib.h>

struct AVLTreeNode
{
  struct AVLTreeNode *lchild;
  int data;
  int height;
  struct AVLTreeNode *rchild;
} *rootAVL = NULL;

struct TreeNode
{
  struct TreeNode *lchild;
  int data;
  struct TreeNode *rchild;
} *root = NULL;

void inorder(struct TreeNode *p)
{
  if (p != NULL)
  {
    inorder(p->lchild);
    printf("%d ", p->data);
    inorder(p->rchild);
  }
}

void inorderAVL(struct AVLTreeNode *p)
{
  if (p != NULL)
  {
    inorderAVL(p->lchild);
    printf("%d(%d) ", p->data, p->height);
    inorderAVL(p->rchild);
  }
}

int nodeHeight(struct AVLTreeNode *p)
{
  int lh, rh;
  lh = p && p->lchild?p->lchild->height:0;
  rh = p && p->rchild?p->rchild->height:0;
  
  return (lh > rh) ? (lh + 1) : (rh + 1);
}

int balanceFactor(struct AVLTreeNode *p)
{
  int lh, rh;
  lh = p && p->lchild?p->lchild->height:0;
  rh = p && p->rchild?p->rchild->height:0;
  
  return lh - rh;
}

struct AVLTreeNode * doLLRotation(struct AVLTreeNode *p)
{
  struct AVLTreeNode *pl = p->lchild;
  struct AVLTreeNode *plr = pl->rchild;

  p->lchild = plr;
  pl->rchild = p;

  p->height = nodeHeight(p);
  pl->height = nodeHeight(pl);

  if (rootAVL == p)
    rootAVL = pl;
  
  return pl;
}

struct AVLTreeNode * doLRRotation(struct AVLTreeNode *p)
{
  struct AVLTreeNode *pl = p->lchild;
  struct AVLTreeNode *plr = pl->rchild;

  pl->rchild = plr->lchild;
  p->lchild = plr->rchild;
  plr->lchild = pl;
  plr->rchild = p;

  p->height = nodeHeight(p);
  pl->height = nodeHeight(pl);
  plr->height = nodeHeight(plr);

  if (rootAVL == p)
    rootAVL = plr;

  return plr;
}

struct AVLTreeNode * doRRRotation(struct AVLTreeNode *p)
{
  struct AVLTreeNode *pr = p->rchild;
  struct AVLTreeNode *prl = pr->lchild;

  p->rchild = prl;
  pr->lchild = p;

  p->height = nodeHeight(p);
  pr->height = nodeHeight(pr);

  if (rootAVL == p)
    rootAVL = pr;
  
  return pr;
}

struct AVLTreeNode * doRLRotation(struct AVLTreeNode *p)
{
  // TODO review
  return p;
}

struct AVLTreeNode * rAVLInsert(struct AVLTreeNode *p, int key)
{
  struct AVLTreeNode *t = NULL;

  if (p == NULL)
  {
    t = (struct AVLTreeNode *)malloc(sizeof(struct AVLTreeNode));
    t->data = key;
    t->height = 1;
    t->lchild = NULL;
    t->rchild = NULL;
    return t;
  }
  
  if (key < p->data)
    p->lchild = rAVLInsert(p->lchild, key);
  else if (key > p->data)
    p->rchild = rAVLInsert(p->rchild, key);
  
  p->height = nodeHeight(p);

  int bf = balanceFactor(p);
  int lbf = balanceFactor(p->lchild);
  int rbf = balanceFactor(p->rchild);

  if (bf == 2 && lbf == 1)
    return doLLRotation(p);
  else if (bf == 2 && lbf == -1)
    return doLRRotation(p);
  else if (bf == -2 && lbf == -1)
    return doRRRotation(p);
  else if (bf == -2 && lbf == -1)
    return doRLRotation(p);
  
  return p;
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

struct AVLTreeNode * search(int key)
{
  struct AVLTreeNode * t = rootAVL;
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
  int p[] = {5, 1, 2};

  root = rInsert(root, p[0]);
  rootAVL = rAVLInsert(rootAVL, p[0]);

  for (int i = 1; i < 3; i++)
  {
    rAVLInsert(rootAVL, p[i]);
    rInsert(root, p[i]);
  }

  inorderAVL(rootAVL);
  struct AVLTreeNode * rAVL = rootAVL;
  printf("\n");
  inorder(root);
  struct TreeNode * r = root;
  printf("\n");

  return 0;
}
