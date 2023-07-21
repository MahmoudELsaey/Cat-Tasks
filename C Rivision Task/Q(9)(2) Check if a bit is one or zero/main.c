#include <stdio.h>
#include <stdlib.h>

int isNthBitSet(int num, int n) {
    int mask = 1 << n;
    return (num & mask) != 0;
}

int main() {
    int number, bitPosition;

    printf("Enter an integer number: ");
    scanf("%d", &number);

    printf("Enter the bit position (0-31): ");
    scanf("%d", &bitPosition);

    if (bitPosition < 0 || bitPosition > 31) {
        printf("Invalid bit position. Please enter a value between 0 and 31.\n");
        return 1;
    }

    int isSet = isNthBitSet(number, bitPosition);

    printf("The %dth bit of the number %d is %d\n", bitPosition, number, isSet);

    return 0;
}
