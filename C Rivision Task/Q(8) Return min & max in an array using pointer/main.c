#include <stdio.h>
#include <stdlib.h>

int fun(int *arr, int size, int *max, int *min)
{
    *max=*arr;
    *min=*arr;
    for(int i=0; i<size; i++)
    {
        if (*max<*(arr+i))
            *max=*(arr+i);
        if (*min>*(arr+i))
            *min=*(arr+i);
    }
}




int main()
{
    int size;
    int max,min;
    printf("Enter size of the array\n");
    scanf("%d",&size);

    int arr[size];
    for(int n=0; n<size; n++)
    {
        printf("Enter Element %d\n",n+1);
        scanf("%d",&arr[n]);
    }

    fun(arr, size, &max, &min);
    printf("the max num is: %d, the min num is: %d", max,min);

    return 0;
}
