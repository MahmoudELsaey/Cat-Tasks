#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *str = "Hello Mahmoud 23#@";
    int alpha=0, digits=0, sc=0, space=0;
    for (int i = 0; i<strlen(str); i++)
    {
        if (str[i] >= 48 && str[i] <= 57)
            digits++;

        else if ((str[i] >= 65 && str[i]<= 90) || (str[i] >= 97 && str[i]<= 122))
            alpha++;

        else if (str[i] == 32)
            space++;

        else
            sc++;
    }

    printf("Number of digits = %d \nNumber of Alphabitic = %d \nNumber of Special Characters = %d \nNumber of Spaces = %d", digits, alpha, sc, space);
    return 0;
}
