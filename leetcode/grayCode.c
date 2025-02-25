/*
 * DATE: 22/02/2025
 * WACP: To generate a  n-bit gray code sequence is a sequence of 2n integers where:
 *
 *    Every integer is in the inclusive range [0, 2n - 1],
 *   The first integer is 0,
 *   An integer appears no more than once in the sequence,
 *   The binary representation of every pair of adjacent integers differs by exactly one bit, and
 *   The binary representation of the first and last integers differs by exactly one bit.
 *
 * Given an integer n, return any valid n-bit gray code sequence.
 * Link: https://leetcode.com/problems/gray-code/
 */

/*--------------------- INCLUDE SECTION -----------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/*----------------------- MACRO SECTION -----------------------*/
#define NBIT                    2
#define ARRAYSIZE(arr)          (sizeof(arr) / sizeof(*arr))
#define BIT_TOGGLE(var, pos)    ((var)^(1 << pos))

/*------------------ FUNCTION DECLARATION ---------------------*/
uint32_t power(uint16_t var, uint16_t car)
{
    uint32_t res = 1;
    for(uint32_t idx = 0; idx < car; idx++) { res *= var; }
    printf("power(%d, %d) = %d\n", var, car, res);
    return res;
}

void printBin(uint16_t var)
{
    for(uint8_t idx = 0; idx < NBIT; idx++)
    { printf("%d",(var & (1 << (NBIT - idx-1)))?1:0); }
    printf(" ");
}

int main(void)
{
    uint8_t loopCnt = power(2,NBIT);
    uint8_t arrSize = (sizeof(uint16_t) * loopCnt);
    uint16_t* resultArr = (uint16_t *) (malloc(arrSize));

    uint16_t resultArr2[NBIT] = {};
    printf("\nResults:\t");
    printBin(resultArr[0]);
    for (uint8_t idx = 0, var = 0, cycleup = 1; idx < (loopCnt - 1); idx++)
    {
        printf("]\t idx=%d,var=%d,cycleup=%d[", idx, var, cycleup);
        resultArr[idx + 1] = BIT_TOGGLE(resultArr[idx], var);
        printBin(resultArr[idx + 1]);
        
        if((cycleup))
        {
            if(var == (NBIT - 1)) { cycleup = 0; var--; }
            else            { var++; }
        }
        else
        {
            if(var == 0) { cycleup = 1; var++; }
            else            { var--; }
        }
    }
    printf("\n");

    for(int a = 0,b = 0; a < loopCnt; a++)
    {
        //printf("|%d\r\n", b);
        printf("%x\r\n", resultArr[a]);
        // b = BIT_TOGGLE(b,a);
    }
}

