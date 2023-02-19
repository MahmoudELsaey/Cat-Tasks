#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,y;
    int *ptr1 = &x;
    int *ptr2 = &y;

    printf("enter two variables \n");
    scanf("%d %d",&x,&y);
    printf("%d %d \n",x,y);

    printf("the summation of the two varables is: %d", sum(ptr1,ptr2));


    return 0;
}

int sum (int *ptr1, int *ptr2)
{
    int sum = *ptr1 + *ptr2;
    return sum;
}
