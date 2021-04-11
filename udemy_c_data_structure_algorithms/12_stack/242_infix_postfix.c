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
  char x = -1;
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

char stackTop()
{
  if (top != NULL)
  {
    return top->data;
  }
  else
    return ' ';
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

int isOperand(char x)
{
  if (
    x == '+' ||
    x == '-' ||
    x == '*' ||
    x == '/'
  )
    return 0;
  else
    return 1;
}

int pre(char x)
{
  if ( x == '+' || x == '-' )
    return 1;
  else if ( x == '*' || x == '/' )
    return 2;
  
  return 0;
}

int strLength(char * str)
{
  int i = 0;
  while (str[i] != '\0')
  {
    i++;
  }
  
  return i;
}

char * convert(char *exp)
{
  char * postfix = (char *)malloc(sizeof(char) * strLength(exp));
  int j = 0;
  for (int i = 0; exp[i]!='\0'; i++)
  {
    char c = exp[i];
    if (isOperand(c))
    {
      postfix[j++] = c;
    }
    if (pre(c) > pre(stackTop()))
      push(c);
    else
    {
      char pc = pop();
      if (pc != -1)
        postfix[j++] = pc;
      
    }
  }

  while (top != NULL)
    postfix[j++] = pop();
  
  postfix[j] = '\0';

  return postfix;
}

int main(int argc, char const *argv[])
{
  char *exp1 = "a+b*c-d/e";

  printf("%d \n", strLength(exp1));
  printf("%s \n", convert(exp1));
  
  return 0;
}
