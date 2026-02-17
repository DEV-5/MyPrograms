/*
 * IMplement binary search from memory
 * Date: 26th Dec 2025
 */

#include <stdio.h>
#include <stdint.h>

#define NEEDLE  24
#define ARRAYSIZE(arr)    (sizeof(arr) / sizeof(arr[0]))

int8_t binarySearch(int16_t key, int16_t arr[], int8_t len)
{
        uint8_t low = 0, high = len - 1, mid;
        int idx = 0;//debug

        while( low <= high)
        {
                mid = (low + high) / 2;
                printf("Trace(%d) low = %d, high=%d, mid =%d(value at mid:%d) and key =%d\n", idx++,low, high, mid, arr[mid], key);
                if (arr[mid] == key)
                        return mid;

                if (key < arr[mid])
                        high = mid - 1;
                else
                        low = mid + 1;
        }
        return -1;
}

int main()
{
        int8_t retIdx;
        int16_t haystack[] = { 1, 2, 5, 7, 13, 20, 23, 24, 36};
        retIdx = binarySearch(NEEDLE, haystack, ARRAYSIZE(haystack));
        if (retIdx != -1)
                printf("Found NEEDLE(%d) in haystack index:%d\r\n", NEEDLE, retIdx);
        else
                printf("NEEDLE(%d) is not present in  haystack !!\r\n", NEEDLE);
}
