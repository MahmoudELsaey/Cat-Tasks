#include <stdio.h>
#include <stdlib.h>

char user; int pass;

int main()
{
    printf ("User name : ");
    scanf ("%s",&user);

    printf ("Password : ");
    scanf ("%d",&pass);
    login(user, pass);
    return 0;
}

void login(char user , int pass)
{
    if (pass == 12345)
    printf (" Login...");
    else
        printf("username or password is not correct. ");
}
