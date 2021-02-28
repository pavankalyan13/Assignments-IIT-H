#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>
#include<unistd.h>
#include<pthread.h>

void printArray();
void merge( int l,  int pivot,  int r);
void mergeSort( int left,  int right);
void* multThredmSort(void *arg);

// denotes the size of segments of the array
 int siz, segments;
 int part = 0;

// denotes the array of our interest
long int *arr;

int main()
{
    int n,p;

    FILE *fp;

    fp = fopen("info.txt", "r");

    if(fp == NULL)
    {
        printf("Error in opening in file\n");
    }
    else
    {
        //printf("File opened in read mode\n");
        fscanf(fp, "%d %d", &n, &p);
    }

    clock_t start, end;

    // size denotes the number of elements in the array
    siz = pow(2,n);

    // number of segements to be made
    segments = pow(2,p);

    // size of each segment is
    int segSize = pow(2,n-p);

    // using malloc to create a array of size siz
    arr = (long int *)malloc(siz * sizeof(long int));

    // printf("Read data : %d %d\n", n, p);
    printf("The array has %d elements and %d segments\n", siz, segments);


    srand(time(0));

    int i;
    for( i = 0; i < siz; i++)
    {
        arr[i] = rand();
    }

	printf("\n");
    printArray();
    pthread_t threads[segments];


    start = clock();

    for( i = 0; i < segments; i++)
    {
        pthread_create(&(threads[i]),NULL,multThredmSort, (void *)NULL);
    }

    pthread_exit(NULL);

    for(i = 0; i < segments; i++)
    {
        pthread_join(threads[i], NULL);
    }


    // do the sorting of entire array again using method 1

    /*
     int pivot;
     int last;
    for( int p = 0; p <= segments-1; p++)
    {
        pivot = p*segSize - 1;
        last = (p+1)*segSize - 1;

        merge(0,pivot,last);
    }
*/
    end = clock();


    printf("\nThe array after sorting\n");
    printArray();
    printf("\nTime taken: %f Microseconds", (start - end)/(double)CLOCKS_PER_SEC);

    return 0;
}

// Utility function to print the array
void printArray()
{
     int i;

    for( i = 0; i < siz; i++)
    {
        printf("%ld  ", arr[i] );
    }

}

void merge( int left, int pivot, int right)
{
     int size1 = pivot - left + 1;
     int size2 = right - pivot;

    long int leftArr[size1];
    long int rightArr[size2];

    int i;
    for(i = 0; i < size1; i++)
    {
        leftArr[i] = arr[left+i];
    }

    for(i = 0; i < size2; i++)
    {
        rightArr[i] = arr[pivot+1+i];
    }

     i = 0;
     int j = 0;
    int k = left;

    while(i < size1 && j < size2)
    {
        if(leftArr[i] <= rightArr[j] )
        {
            arr[k] = leftArr[i];
            i++;

        }
        else
        {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while(i < size1)
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while(j < size2)
    {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(int left, int right)
{
    if(left < right)
    {
        int middle = left + (right- left)/2;

        mergeSort(left,middle);
        mergeSort(middle+1,right);

        merge(left, middle, right);
    }
}

void* multThredmSort(void *arg)
{
    int tPart = part;

    // then increase the part for the next thread
    part++;

    int low = tPart * (siz)/(segments);


    int high = tPart *(siz)/(segments) - 1;

    // find the mid point
    int mid = low + (high - low)/2;

    if(low < high)
    {
        mergeSort(low,mid);
        mergeSort(mid+1, high);
        merge(low, mid, high);
    }

}
