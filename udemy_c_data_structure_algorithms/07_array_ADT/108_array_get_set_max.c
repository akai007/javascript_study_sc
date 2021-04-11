#include <stdio.h>

struct Array
{
    int A[20];
    int size;
    int length;
};

void set(struct Array *arr, int index, int num)
{
    if (index < 0 || index >= arr->length)
        printf("have no value on index[%d]", index);

    arr->A[index] = num;
}

int get(struct Array *arr, int index)
{
    if (index < 0 || index >= arr->length)
        return -1;

    return arr->A[index];
}

int max(struct Array *arr)
{
    int max = arr->A[0];
    for (int i = 1; i < arr->length; i++)
    {
        if (max < arr->A[i])
            max = arr->A[i];
    }

    return max;
}

int main(int argc, char const *argv[])
{
    struct Array arr = {{2, 3, 4, 5, 6}, 20, 5};

    set(&arr, 2, 8);
    printf("%d \n", get(&arr, 2));
    printf("%d \n", max(&arr));

    return 0;
}
