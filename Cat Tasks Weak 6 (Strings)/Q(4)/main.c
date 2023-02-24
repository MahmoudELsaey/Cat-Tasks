#include <stdio.h>
#include <stdlib.h>

int main()
{
    char str [100];
    printf("Enter Your String \n");
    scanm(str, 100);


    char ch;
    printf("Enter The Character \n");
    scanf("%c", &ch);

    // counter for the String
    int i =0;

    while(ch != str[i])
    {
        i++;
    }

    printf("The Character %c found at Index %d", ch,i);
    return 0;
}




int scanm (char str [], int n)
{
    int i=0; char ch;
    while ((ch= getchar()) != '\n')
    {
        if (i<n)
            str[i++] = ch;
    }
    str[i]= '\0';
    return i;
}
