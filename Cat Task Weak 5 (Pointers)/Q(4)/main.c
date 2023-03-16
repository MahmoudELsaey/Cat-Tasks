#include <stdio.h>
#include <stdlib.h>

#define ele 7 //we can change the size of the array.

int main()
{
    int arr [] = {20,10,500,1,25,15,5};
    BS(arr);

    return 0;
}



int BS (int arr [])
{
    for (int i=0; i<ele-1; i++)
    {
        for (int j=0; j<ele-i-1; j++)
        {
            if (arr[j]>arr[j+1])
            {
                int num = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]= num;
            }
        }
    }


    //printing the final array
    for (int n=0; n<ele; n++)
    {
        printf("%d\n",arr[n]);
    }
}
