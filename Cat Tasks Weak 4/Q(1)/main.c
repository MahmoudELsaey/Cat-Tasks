#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x=0, max=0, i=0, j=0, choice=0 ;

    printf("Enter numbers of the elements u wanna sort : ");
    scanf("%d",&x);

    int arr[x], arr2[x];

    printf("Enter the elements u wanna sort : ");

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
    printf("Enter 0 if u wanna sort the elements of array in ascending \nor 1 in case of descending : ");
    scanf("%d",&choice);

    if(choice == 1)
    {
        printf("Sort in descending is : ");
        for(int i=0; i<x; i++)
        {
            printf("%d\t",arr2[i]);
        }
    }
    else if(choice == 0)
    {
        printf("Sort in ascending is : ");
        for(int i=x-1; i>=0; i--)
        {
            printf("%d\t",arr2[i]);
        }
    }
    else
    {
        printf("Enter a valid choice !!!");
    }

    return 0;
}
