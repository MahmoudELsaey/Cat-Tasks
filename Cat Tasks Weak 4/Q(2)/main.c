#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x=0, max=0, i=0, j=0;

    printf("Enter size of the array : ");
    scanf("%d",&x);

    int arr[x], arr2[x];

    printf("Enter the elements : ");

    for(int i=0; i<x; i++)
    {
        scanf("%d",&arr[i]);
    }

    while(i<x)
    {
        for(int i=0; i<x; i++ )
        {
            if (arr[i]>max )
            {
                max= arr[i];
                j=i;
            }
        }
        arr2[i]=max;
        max=0;
        arr[j]=0;
        i++;
    }
    printf("The second largest element is : %d ", arr2[1]);


    return 0;
}
