#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;
    int remainder;
    int sum=0;

    printf("Enter the number: ");
    scanf("%d", &num);

    while (num!=0)
    {
        remainder= num%10;
        num = num/10;
        sum+= remainder;
    }
    printf("Sum of digits = %d", sum);
    return 0;
}
