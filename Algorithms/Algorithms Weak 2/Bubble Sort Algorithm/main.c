#include <stdio.h>
#include <stdlib.h>

int swap(int *ptr1, int *ptr2)
{
    int temp= *ptr1;
    *ptr1=*ptr2;
    *ptr2=temp;
}

void BS (int arr[], int n)
{
    for (int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            if(arr[j]>arr[j+1])
                swap(&arr[j], &arr[j+1]);
        }
    }
}

void printArray(int arr[], int n)
{
    printf("The sorted array is: ");
    for (int z=0; z<n; z++)
        printf("%d ",arr[z]);
}


int main()
{
    int arr[]={1,5,0,8,4,3,20,2,200,150,123,1584};
    int n= sizeof(arr)/sizeof(arr[0]);

    BS(arr,n);
    printArray(arr,n);
    return 0;
}
