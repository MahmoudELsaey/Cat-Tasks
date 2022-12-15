#include <stdio.h>
#include <stdlib.h>

//Calculate how many digits in binary.

//int main()
//{
//    int x,num;
//
//    printf("Enter the number\n");
//    scanf("%d", &num);
//
//    for(x=0;num!=0;x++)
//    {
//      num = num>>1;
//    }
//    printf("%d",x);
//    return 0;
//}



//Calculate how many digits

int main()
{
    int n, count=0;

    printf("Enter a number\n");
    scanf("%d",&n);

    while(n!=0)
    {
        n=n/10;
        count++;
    }

    printf("The number of digits is : %d",count);
    return 0;
}
