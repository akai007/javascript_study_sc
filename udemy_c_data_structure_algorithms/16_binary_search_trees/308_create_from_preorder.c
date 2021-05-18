#include <stdio.h>
#include <stdlib.h>
#include "./_linked_stack.h"

void createFromPreorder(int *pre, int n)
{
  // create root
  struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
  root->data = pre[0];
  root->lchild = NULL;
  root->rchild = NULL;

  struct TreeNode *t;
  struct TreeNode *p = root;

  int i = 1;
  while (i < n)
  {
    // left child case
    if (pre[i] < p->data)
    {
      t = (struct TreeNode *)malloc(sizeof(struct TreeNode));
      t->data = pre[i];
      t->lchild = NULL;
      t->rchild = NULL;
      p->lchild = t;
      push(p);
      p = t;
      i++;
    }
    else
    {
      // right child case
    }
    
  }
  
  

}

int main(int argc, char const *argv[])
{
  
  int pre[] = {30, 20, 10, 15, 25, 40, 50, 45};
  int n = sizeof(pre)/sizeof(pre[0]);

  return 0;
}
