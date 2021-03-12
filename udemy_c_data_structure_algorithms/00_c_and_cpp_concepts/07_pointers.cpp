// pointers

#include <stdio.h>
#include <iostream>
#include <stdlib.h> // include malloc

using namespace std;

int main()
{
    // variable
    int a = 10;
    int *p;
    p = &a;

    cout<<a<<endl;
    cout<<*p<<endl;
    printf("using pointer address: %p pointer value: %d\n", p, *p);

    cout<<"\n array:"<<endl;
    int arr[5] = {1, 3, 5, 7, 9};
    int *pArr;
    pArr = &arr[0];
    pArr = arr;
    for (int i = 0; i < 5; i++)
    {
        cout<<pArr[i]<<endl;
    }
    cout<<endl;


    cout<<"\n heap:"<<endl;
    int *pHeap;
    pHeap = (int *)malloc(5*sizeof(int));
    int *pHeapPP;
    pHeapPP = new int[5];

    for (int i = 0; i < 5; i++)
    {
        pHeap[i] = (i + 1) * 2;
        pHeapPP[i] = pHeap[i];
    }

    for (int i = 0; i < 5; i++)
    {
        cout<<pHeap[i]<<"\t"<<pHeapPP[i]<<endl;
    }

    // dont forget to clear heap
    free(pHeap);
    delete [] pHeapPP;

    cout<<"\n base type use memory:"<<endl;
    int intV;
    short shortV;
    long longV;
    float floatV;
    double doubleV;
    char charV;

    cout<<sizeof(intV)<<"\t"<<sizeof(shortV)<<"\t"<<sizeof(longV)<<"\t"<<sizeof(floatV)<<"\t"<<sizeof(doubleV)<<"\t"<<sizeof(charV)<<"\t"<<endl;
    cout<<sizeof(&intV)<<"\t"<<sizeof(&shortV)<<"\t"<<sizeof(&longV)<<"\t"<<sizeof(&floatV)<<"\t"<<sizeof(&doubleV)<<"\t"<<sizeof(&charV)<<"\t"<<endl;

    
    return 0;
}
