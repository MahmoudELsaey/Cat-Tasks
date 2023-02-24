#include <stdio.h>
#include <stdlib.h>

int repeat(int arr[]);
int x=0;

int main()
{
    printf("Enter size of the array : ");
    scanf("%d",&x);

    int arr[x];

    printf("Enter the elements : ");

    for(int i=0; i<x; i++)
    {
        scanf("%d",&arr[i]);
    }

    repeat(arr);

    return 0;
}

int repeat(int arr[])
{
    int k=0, j=0, arr2[x];

    while(j<x)
    {
        for(int i=j+1; i<x; i++)
        {
            if(arr[j]==arr[i])
            {
                arr2[k]=arr[j];
                k++;
                break;
            }
        }
        j++;
    }

    printf("Repeating elements are : ");
    for(int i=0; i<k; i++)
    {
        printf("%d\t",arr2[i]);
    }

}
