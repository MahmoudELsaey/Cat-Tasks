#include <stdio.h>
#include <stdlib.h>

void inArr(int arr[])
{
    for(int i=0; i<8; i++)
    {
        scanf("%d", &arr[i]);
    }
}

void merge(int leftArr[], int rightArr[], int fullArr[], int nl, int nr)
{
    int i = 0, j = 0, k = 0;

    while (i < nl && j < nr)
    {
        if (leftArr[i] <= rightArr[j])
        {
            fullArr[k] = leftArr[i];
            i++;
        }
        else
        {
            fullArr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < nl)
    {
        fullArr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < nr)
    {
        fullArr[k] = rightArr[j];
        j++;
        k++;
    }
}



void mergeSort(int arr[], int n)
{
    if (n < 2)
        return;

    int mid = n / 2;
    int left[mid];
    int right[n - mid];

    for (int i = 0; i < mid; i++)
        left[i] = arr[i];

    for (int i = mid; i < n; i++)
        right[i - mid] = arr[i];

    mergeSort(left, mid);
    mergeSort(right, n - mid);
    merge(left, right, arr, mid, n - mid);
}


void printArray(int A[], int size)
{
    int i;
    printf("The Sorted Array: ");
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main()
{
    int arr1[8], arr2[8], fullArray[16];
    printf("Enter First Array 8 Elements:\n");
    inArr(arr1);
    printf("Enter Second Array 8 Elements:\n");
    inArr(arr2);

    mergeSort(arr1,8);
    mergeSort(arr2,8);
    merge(arr1, arr2, fullArray, 8, 8);
    printArray(fullArray, 16);

    return 0;
}
