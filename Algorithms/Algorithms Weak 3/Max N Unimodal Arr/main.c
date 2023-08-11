#include <stdio.h>
#include <stdlib.h>

//BInary Search Algorithm.
int MaxN(int arr[], int low, int high)
{
// Divide & conquer.
// Base Case (1 Element).
if (low == high)
	return arr[low];
// 2 Elements.
if ((high == low + 1) && arr[low] >= arr[high])
	return arr[low];
// 2 Elements.
if ((high == low + 1) && arr[low] < arr[high])
	return arr[high];

int mid = (low + high)/2;
if ( arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1])
	return arr[mid];

//Decreasing Side(Right).
if (arr[mid] > arr[mid + 1] && arr[mid] < arr[mid - 1])
	return MaxN(arr, low, mid-1);
//Increasing Side(Left).
else
	return MaxN(arr, mid + 1, high);
}

int main()
{
int arr[] = {10,20,30,40,50,60,6,5,4,3,2,1,0};
int n = sizeof(arr)/sizeof(arr[0]);
printf("The Maximum Element is %d", MaxN(arr, 0, n-1));
return 0;
}
