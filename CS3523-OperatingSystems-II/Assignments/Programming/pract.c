#include<stdio.h>

int main()
{

    int arr[] = {3,27,38,43,9,10,82};

    int i = k = j = 0;

    int n1 = 3;
    int n2 = 2;

    while(i <= n1 && j <= n2)
    {
        if(arr[i] <= arr[j] )
        {
           arr[k] = arr[i];
           i++;
           k++;
        }
        else if(arr[i] > arr[j] )
        {

        }
    }
    return 0;
}
