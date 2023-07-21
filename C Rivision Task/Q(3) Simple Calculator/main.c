#include <stdio.h>
#include <stdlib.h>

int main()
{
    float num1, num2;
    char sum = '+', minus = '-', mult = '*', divide = '/';
    int choice;

    printf("Enter 1st NUM  & 2nd NUM \n");
    scanf("%f %f", &num1, &num2);

    printf("Enter 1 for sum, 2 for minus, 3 for multip, 4 for division \n");
    scanf("%d", &choice);

    switch (choice)
    {
case 1:
    printf("%.2f", (num1 + num2)); ;
    break;
case 2:
    printf("%.2f", (num1 - num2)); ;
    break;
case 3:
    printf("%.2f", (num1 * num2)); ;
    break;
case 4:
    printf("%.2f", (num1 / num2)); ;
    break;
default:
    printf("Wrong Choice");
    }

    return 0;
}
