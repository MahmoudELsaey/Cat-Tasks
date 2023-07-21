#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size;
    printf("Enter size of the array\n");
    scanf("%d",&size);

    int arr[size];
    int en=0, on=0;
    for(int n=0; n<size; n++)
    {
        printf("Enter Element %d\n",n+1);
        scanf("%d",&arr[n]);
    }

    for(int x=0; x<size; x++)
    {
        if(arr[x]%2==0)
            en++;
        else
            on++;
    }

    printf("Total of odd numbers: %d\n", on);
    printf("Total of even numbers: %d\n", en);

    return 0;
}
