#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr [4] = {1,2,3,4};
    printf("max value = %d", BS(arr));
    return 0;
}

int BS (int arr [4])
{
    int max =arr[0];
    printf("%d \n", max);

    for (int i= 1; i<= 3; i++)
    {
        if (max < arr[i])
        {
           max = arr[i];
        }
    }
    return max;

}
