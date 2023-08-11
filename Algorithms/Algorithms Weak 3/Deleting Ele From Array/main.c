#include <stdio.h>
#include <stdlib.h>

void inArr(int arr[])
{
    for(int i=0; i<10; i++)
    {
        scanf("%d", &arr[i]);
    }
}

void printArray(int A[], int size)
{
    int i;

    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

void deleteArray(int arr[], int n, int position)
{
    int narray[n-1];
    for(int i=0; i<n-1; i++)
    {
        if(i>=position)
            narray[i]=arr[i+1];
        else
            narray[i]=arr[i];
    }
    printArray(narray,n-1);
}

int main()
{
    int arr[10], position;
    printf("Enter Array's 10 Elements\n");
    inArr(arr);
    printf("Enter Element position\n");
    scanf("%d", &position);

    if(position < 1 || position > 10)
        printf("Invalid position! Please enter position between 1 to 10");
    else
        deleteArray(arr, 10, position-1);

    return 0;
}
