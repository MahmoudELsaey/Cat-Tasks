#include <stdio.h>
#include <stdlib.h>

void fs(int range)
{
    int x=0;
    int y=1;
    int z;
    while (x<=range)
    {
        printf("%d\t", x);
        z = x+y;
        x = y;
        y = z;
    }
}

int main()
{
    int range;

    printf("Enter range: ");
    scanf("%d", &range);

    printf("The fibonacci series is: \n");

    fs(range);

    return 0;
}
