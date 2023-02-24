#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *str = "Mahmoud Mahmoud Mostafa Elsaey";
    int i;

    for (i = strlen(str)-1; i>= 0; i--)
    {
        printf("%c", str[i]);
    }

    return 0;
}
