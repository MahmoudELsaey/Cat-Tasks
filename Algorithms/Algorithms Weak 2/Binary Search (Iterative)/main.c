#include <stdio.h>
#include <stdlib.h>

void BinSearch(int arr[], int guess, int low, int high)
{
    int mid;
    if (guess>high || guess<low)
    printf("The guess is not in the array");

    while(low<=high)
    {
        mid=(low+high)/2;

        if (mid==guess)
        {
            printf("the guess is in the array");
            break;

        }

        else if(mid<guess)
            low=mid+1;

        else
            high=mid-1;

    }
}

int main()
{
    int arr[10]={1,2,3,4,5,6,7,8,9,10};
    int low=arr[0];
    int high=arr[9];
    int guess;

    printf("Enter your guess\n");
    scanf("%d", &guess);

    BinSearch(arr,guess,low,high);
    return 0;
}
