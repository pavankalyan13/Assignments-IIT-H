#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int insertionSort(int *arr, int n)
{
    int i, key, j;
    int compCount = 1;

    for(i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while(j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j--;
            compCount++;
        }

        if(j > 0 && j < n )
            compCount++;
        arr[j+1] = key;
    }

    return compCount;
}

void printArray(int arr[], int n)
{
    int i;
    for(i = 0; i < n; i++)
        printf("%d ", arr[i] );
    printf("\n");
}

void reverseArray(int *arr, int n, int *revArr)
{
    for(int i = 0; i < n; i++)
    {
        revArr[i] = arr[n-(i+1)];
    }

}
void generateGP(int *arr, int n, int a, int r)
{
    arr[0] = a;

    for(int i = 1; i < n; i++)
    {
        arr[i] = arr[i-1] * r;
       // arr[i+1] = arr[i] * r;

    }

}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;

}

void randomize(int arr[], int n)
{
    srand(time(NULL));

    for(int i = n-1; i > 0; i--)
    {
        int j = rand() % (i+1);

        swap(&arr[i], &arr[j] );
    }
}

int main()
{
    int n,a,r;

    printf("Enter the values of N, a and r: \n");
    scanf("%d %d %d", &n, &a, &r);

    int seq1[n], seq2[n];
    int count1 = 0, count2 = 0, count3 = 0;

    // Function call to generate a GP
    generateGP(seq1, n, a, r);

    printf("\n\nAscending order: ");
    printArray(seq1,n);

    // call to insertion sort which returns the total comparisons count
    count1 = insertionSort(seq1,n);
    printf("Comparison count for ascending sequence: %d\n", count1);



    // Function call to generate reverse order of GP
    reverseArray(seq1,n,seq2);

    printf("\n\nDescending order: ");
    printArray(seq2,n);

    count2 = insertionSort(seq2,n);
    printf("Comparison count for descending sequence: %d\n", count2);


    randomize(seq1,n);
    printf("\n\nRandom order: ");
    printArray(seq1,n);
    count3 = insertionSort(seq1, n);
    printf("Comparison count for Random sequence: %d\n", count3);


    return 0;
}
