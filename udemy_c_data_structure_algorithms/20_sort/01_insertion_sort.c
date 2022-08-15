#include <stdio.h>

void insertionSort(int arr[], int n) {
    int i, j, x;

    for (i = 1; i < n; i++)
    {
        x = arr[i];

        for (j = i-1; j >= 0 && x < arr[j] ; j--)
        {
            arr[j+1] = arr[j]; 
        }
        arr[j+1] = x;
    }
}

void displayList(int arr[], int n) {
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    int arr[] = { 5, 2, 7, 3, 2 };
    displayList(arr, sizeof(arr)/sizeof(arr[0]));

    insertionSort(arr, sizeof(arr)/sizeof(arr[0]));
    displayList(arr, sizeof(arr)/sizeof(arr[0]));

    return 0;
}
