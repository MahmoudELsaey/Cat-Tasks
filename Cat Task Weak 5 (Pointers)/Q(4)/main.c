#include <stdio.h>
#include <stdlib.h>

#define ele 4 //we can change the size of the array.

int main()
{
    int arr [] = {20,10,500,1};
    BS(arr);

    return 0;
}



int BS (int arr [])
{
    for (int j=0; j<ele; j++)
    {
        for (int i=0; i<ele; i++)
        {
            if (arr[j]>arr[j+i])
            {
                int num = arr[j];
                arr[j]=arr[j+i];
                arr[j+i]= num;
            }
        }
    }


    //printing the final array
    for (int n=0; n<ele; n++)
    {
        printf("%d\n",arr[n]);
    }
}
