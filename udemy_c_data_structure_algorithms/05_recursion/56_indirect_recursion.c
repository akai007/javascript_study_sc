#include <stdio.h>
void funB(int n);

void funA(int n) {
    if (n > 0)
    {
        printf("A:%d ", n);
        funB(n - 1);
    }
    
}

void funB(int n) {
    if (n > 1)
    {
        printf("B:%d ", n);
        funA(n / 2);
    }
}

int main(int argc, char const *argv[])
{
    funA(20);
    
    return 0;
}
