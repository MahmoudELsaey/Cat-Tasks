#include <stdio.h>
#include <stdlib.h>

int Get_Max (int num1, int num2)
{
    if (num1>num2)
        return num1;
    else
        return num2;
}

int main()
{
    int x,y;
    printf("Enter 2 numbers\n");
    scanf("%d %d", &x, &y);
    printf("the maximum number is %d",Get_Max(x,y));

    return 0;
}


