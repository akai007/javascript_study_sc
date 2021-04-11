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

int count(struct Node *p)
{
    int count = 0;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}

int countRecursive(struct Node *p)
{
    if (p == NULL)
        return 0;

    return countRecursive(p->next) + 1;
}
int sum(struct Node *p)
{
    int sum = 0;
    while (p != NULL)
    {
        sum += p->data;
        p = p->next;
    }
    return sum;
}

int sumRecursive(struct Node *p)
{
    if (p == NULL)
        return 0;

    return sumRecursive(p->next) + p->data;
}

int main(int argc, char const *argv[])
{
    int A[] = {3, 5, 7, 11, 13, 17, 19};

    create(A, 7);
    printf("count: %d \n", count(first));
    printf("count: %d \n", countRecursive(first));
    printf("sum: %d \n", sum(first));
    printf("sum: %d \n", sumRecursive(first));

    return 0;
}
