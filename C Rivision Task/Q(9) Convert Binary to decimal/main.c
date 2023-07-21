#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int binum;
    int expo=0, remainder=0, denum=0;
    printf("Enter the binary number\n");
    scanf("%d", &binum);

    while(binum!=0)
    {
        remainder=binum%10;
        binum = binum/10;
        denum= (denum) + remainder*(pow(2, expo));
        expo++;
    }
    printf("The decimal version is: %d", denum);
    return 0;
}
