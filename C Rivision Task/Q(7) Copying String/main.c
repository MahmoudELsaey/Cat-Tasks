#include <stdio.h>
#include <stdlib.h>

int main()
{
    char arr[51];
    int i=0;
    printf("Enter the 50 literal String\n");
    fgets(arr, sizeof(arr), stdin); //I searched about it.

    char arrcpy[51];
    for(i=0; i<=50; i++)
    {
        arrcpy[i]=arr[i];
    }
    arrcpy[i]='\0';
    printf("%s",arrcpy);

    return 0;
}
