#include <stdio.h>
#include <stdlib.h>

int max (int a, int b)
{
    if (a>b)
        return a;
    else
        return b;
}

int min (int a, int b)
{
    if (a<b)
        return a;
    else
        return b;
}

int main()
{
    int a, b, c, d;
    printf("Enter the four numbers: ");
    scanf("%d %d %d %d", &a, &b, &c, &d);

    int step1 = max(a,b);
    int step2 = max(c,d);
    int step3 = max(step1,step2);
    printf("%d is the max number\n", step3);

    int step4 = min(a,b);
    int step5 = min(c,d);
    int step6 = min(step4, step5);
    printf("%d is the min number\n", step6);

    return 0;
}
