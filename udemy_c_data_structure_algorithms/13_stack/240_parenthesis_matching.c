#include <stdio.h>
#include <stdlib.h>

struct Node
{
  char data;
  struct Node *next;
} *top = NULL;

void push(char x)
{
  struct Node *t;
  t = (struct Node *)malloc(sizeof(struct Node));

  if (t == NULL)
  {
    printf("stack is full \n");
  }
  else
  {
    t->data = x;
    t->next = top;
    top = t;
  }
  
}

char pop()
{
  char x = '\0';
  struct Node *t;
  
  if (top == NULL)
  {
    printf("stack is empty \n");
  }
  else
  {
    x = top->data;
    t = top;
    top = top->next;
    free(t);
  }

  return x;
}

void printStack()
{
  struct Node *p;
  p = top;
  while (p != NULL)
  {
    printf("%c ", p->data);
    p = p->next;
  }

  printf("\n");
  
}

int isBlanced(char *exp)
{
  int i;

  for (i = 0; exp[i]!='\0'; i++)
  {
    if ( exp[i] == '(' ||  exp[i] == '[' ||  exp[i] == '{' )
    {
     push(exp[i]);
    }
    else if ( exp[i] == ')' ||  exp[i] == ']' ||  exp[i] == '}' )
    {
      if ( top == NULL )
        return 0;
      
      if ( 
        ( top->data == '(' && exp[i] != ')' ) ||
        ( top->data == '[' && exp[i] != ']' ) ||
        ( top->data == '{' && exp[i] != '}' )
      )
        return 0;

      pop();
    }
  }

  if (top == NULL)
    return 1;
  else 
    return 0;
}

int main(int argc, char const *argv[])
{
  char *exp1 = "((a+b)*(c-b))";
  char *exp2 = "((a+b)*(c-b)))";
  char *exp3 = "{[(a+b)*(c-b)]}";
  char *exp4 = "{[(a+b)*(c-b)]]";

  printf("%s \n", isBlanced(exp1) ? "is Blanced" : "is not Blanced");
  printf("%s \n", isBlanced(exp2) ? "is Blanced" : "is not Blanced");
  printf("%s \n", isBlanced(exp3) ? "is Blanced" : "is not Blanced");
  printf("%s \n", isBlanced(exp4) ? "is Blanced" : "is not Blanced");
  
  return 0;
}
