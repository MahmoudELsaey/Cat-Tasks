#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr1 [] = {1,2,3,4};
    int arr2 [] = {5,6,7,8};


    printf(" %d \n %d \n", arr1, arr2);

    int *ptr1 = &arr1;
    int *ptr2 = &arr2;

    printf(" %d \n %d \n", ptr1, ptr2);
    SMF (ptr1, ptr2);

    return 0;
}

int SMF (int *ptr1, int *ptr2)
{
   int arr3 [4];
   for (int i=0; i<=3; i++)
   {
       arr3[i]= (*ptr1 +i) * (*ptr2+i);
   }

   for (int i=0; i<=3; i++)
    {
        printf(" Elemnts of scalar Multibliction Array are: %d\n", arr3[i]);
    }
}
