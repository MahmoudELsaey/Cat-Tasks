#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;
    int tz=0;
    int to=0;

    printf("Enter The Number\n");
    scanf("%d",&num);

    while (num!=0)
    {
        if (num%2==0)
            tz++;
        else
            to++;

        num=num/2;
    }
    printf("Total number of Zero bits = %d \n", tz);
    printf("Total number of one bits = %d \n", to);
    return 0;
}
