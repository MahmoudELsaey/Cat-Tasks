#include <stdio.h>
#include <stdlib.h>

void swap(int *ptr1, int *ptr2)
{
    int temp;
    temp=*ptr1;
    *ptr1=*ptr2;
    *ptr2=temp;
}

int partions(int arr[],int start,int end)
{
    int pivot= arr[end];

    int j=start;
    for(int i=start; i<end; i++)
    {
        if(arr[i]<pivot)
        {
        swap(&arr[j],&arr[i]);
        j++;
        }
    }
    swap(&arr[j], &arr[end]);
    return j;
}

void quicksort(int arr[], int start, int end)
{
    if(start<end)
    {
        int j= partions(arr, start, end);
        quicksort(arr, start, j-1);
        quicksort(arr,j+1, end);
    }
}


int main()
{
    int arr[8]={1,5,4,2,3,6,8,7};
    quicksort(arr,0,7);

    for (int i = 0; i < 8; i++)
        printf("%d ", arr[i]);
    return 0;
}
