#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x =10;
    printf("%d \n",x);

    int *ptr =&x;
    *ptr=20;
    printf("%d",x);
    return 0;
}
