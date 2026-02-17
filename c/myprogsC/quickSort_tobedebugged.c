/*
 * Desc: Quick sort
 * DATE: 26th Dec 2025
 */
#include <stdio.h>
#include <stdint.h>

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

void swap(int16_t *a, int16_t *b)
{
        int16_t temp = *a;
        *a = *b;
        *b = temp;
}

int16_t partition(int16_t low, int16_t high, int16_t arr[], uint16_t len)
{
        int16_t pivot = arr[high];
        int16_t pi = low - 1;

        for(int j = low; j < high; j++){
                if( arr[j] < pivot)
                {
                        pi++;
                        swap(&arr[j], &arr[pi]);
                }
        }
        swap(&arr[pi], &arr[high]);
        return pi;
}

void quickSort(int16_t low, int16_t high, int16_t arr[], uint16_t len)
{
        if(high > low)
        {
                uint16_t pi = partition(low, high, arr, len);

                quickSort(low, pi-1, arr, len);
                quickSort(pi+1, high, arr, len);
        }
}

void printArr(int16_t arr[], uint16_t len)
{
        printf("ARRAY Contains: ");
        for (int16_t idx = 0; idx < len; idx++)
                printf("%d ",arr[idx]);
        printf("\r\n");
}

int main()
{
        int16_t arr[] = { 14, 1, 4, 35, 60, 45, 90, 12, 11, 22, 5};

        printArr(arr, ARRAY_SIZE(arr));
        quickSort(0, ARRAY_SIZE(arr)-1, arr, ARRAY_SIZE(arr));
        printArr(arr, ARRAY_SIZE(arr));
}
