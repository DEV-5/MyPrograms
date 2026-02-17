/*
 * Date: 3rd Jan 2026
 * PROG: Add two integers without using + or - operators
 */

#include <stdio.h>
#include <stdint.h>

int32_t add(int32_t a, int32_t b){

        uint32_t op1 = (uint32_t)a;
        uint32_t op2 = (uint32_t)b;
        uint32_t carry;
        while(op2){
                carry = (op1 & op2) << 1;
                printf("carry=%d op1=%d and op2=%d and op1^op2=%d\n", carry, op1,op2, op1^op2);
                op1 ^= op2;
                op2 = carry;
        }
        return (int32_t)op1;
}

int main(){
        //int32_t a = -5, b = 13;
        int32_t a = 5, b = -40;
        // int32_t a = 37, b = 15;
        //int32_t a = -40, b = -13;
        printf(" %d + %d = %d", a, b, add(a,b));
}

