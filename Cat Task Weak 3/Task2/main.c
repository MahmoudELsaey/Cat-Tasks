#include <stdio.h>
#include <stdlib.h>
int num1,num2;

int swap (int x, int y)
{
    int z=x;
    x=y;
    y=z;
    printf("%d\n%d",x,y);
    return 0;
}
int main()
{
    printf("Enter 2 numbers\n");
    scanf("%d %d", &num1, &num2);
    swap(num1,num2);

    return 0;
}
