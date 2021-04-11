#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node * next;
}*first = NULL;


void create(int A[], int n)
{
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
    

}

void printList(struct Node *p)
{
    while (p->next != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

int main(int argc, char const *argv[])
{
    int A[] = {3, 5, 7, 11, 13, 17, 19};

    create(A, 7);
    printList(first);

    return 0;
}
