#include <stdio.h>
#include <stdlib.h>


void printSubArray(int *arr, int size)
{
    int max = 1 << size;

    for ( int i = 1; i < max; i++)
    {
        printf("{");
        for(int j = 0;j < size; j++)
        {
            if ( (i >> j) & 1 )
                printf("%d", arr[j]);
        }
        printf("}\n");
    }
}
int main()
{
    int count;
    int val;
    printf("Enter array count : ");
    scanf("%d", &count);

    int *arr = calloc(count, sizeof(int));
    for(int i = 0; i < count; i++)
    {
        scanf("%d",&val);
        arr[i] = val;
    }

    printSubArray(arr, count);
}