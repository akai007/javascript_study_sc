#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode
{
  struct TreeNode *lchild;
  int data;
  struct TreeNode *rchild;
} *root = NULL;

void createBinaryTree()
{
  struct TreeNode *p, *t;
  int x;
  printf("Enter root value: ");
  scanf("%d", &x);
  root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
  root->data = x;
  root->lchild = root->rchild = NULL;
  enqueue(root);

  while (!isEmpty())
  {
    p = dequeue();
    printf("Enter %d's left child: ", p->data);
    scanf("%d", &x);
    if (x!=-1)
    {
      t = (struct TreeNode *)malloc(sizeof(struct TreeNode));
      t->data = x;
      t->lchild = t->rchild = NULL;
      p->lchild = t;
      enqueue(t);
    }
    printf("Enter %d's right child: ", p->data);
    scanf("%d", &x);
    if (x!=-1)
    {
      t = (struct TreeNode *)malloc(sizeof(struct TreeNode));
      t->data = x;
      t->lchild = t->rchild = NULL;
      p->rchild = t;
      enqueue(t);
    }
    
  }
  
}

void preorder(struct TreeNode *p)
{
  if(p)
  {
    printf("%d ", p->data);
    preorder(p->lchild);
    preorder(p->rchild);
  }
}

void inorder(struct TreeNode *p)
{
  if(p)
  {
    inorder(p->lchild);
    printf("%d ", p->data);
    inorder(p->rchild);
  }
}

void postorder(struct TreeNode *p)
{
  if(p)
  {
    postorder(p->lchild);
    postorder(p->rchild);
    printf("%d ", p->data);
  }
}

int main(int argc, char const *argv[])
{
  createBinaryTree();

  preorder(root);
  printf("\n");
  inorder(root);
  printf("\n");
  postorder(root);
  printf("\n");

  return 0;
}