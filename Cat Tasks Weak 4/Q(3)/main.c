#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x=0, i=0, j=1, k=1;

    printf("Enter size of the array : ");
    scanf("%d",&x);

    int arr[x], arr2[x];

    printf("Enter the elements : ");

    for(int i=0; i<x; i++)
    {
        scanf("%d",&arr[i]);
    }

    arr2[0]=arr[0];

    while(j<x)
    {
        for(int i=0; i<x; i++)
        {
            if(arr[j]==arr2[i])
                break;
            if(i==x-1)
            {
                arr2[k]=arr[j];
                k++;
            }
        }
        j++;
    }

    printf("Unique Elements in the given array are : ");
    for(int i=0; i<k; i++)
    {
        printf("%d\t",arr2[i]);
    }
    return 0;
}
