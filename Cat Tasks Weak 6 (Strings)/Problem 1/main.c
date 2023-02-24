#include <stdio.h>
#include <stdlib.h>

int main()
{
 char str [100];


 printf("Enter Your String \n");
 int numberOfLetters = scanm(str, 100); //The Integer is for setting the maximum character can be stored in the Array.

 printf("the string is: %s \nThe Length Is: %d \n", str, numberOfLetters);

 //Turning the Lowercase to Uppercase.
 for(int i=0; i<numberOfLetters; i++)
 {
     if (str[i] >= 97 && str[i] <=122)
     str[i]-=32;
 }
 printf("the string in uppercase is: %s \nThe Length Is: %d \n", str, numberOfLetters);
    return 0;
}



// My own Scanf for strings. It can print until 100 letters.
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
