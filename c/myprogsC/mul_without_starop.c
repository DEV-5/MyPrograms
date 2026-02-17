/*
 * Date: 3rd Jan 2026
 * PROG: Multiply two integers without using * or / operators
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int32_t mul(int32_t a, int32_t b){

        int32_t sign = (a<0) ^ (b<0) ? -1 : 1;
        uint32_t op1 = abs(a);
        uint32_t op2 = abs(b);
        int32_t result = 0;
        printf("sign is %s\n", sign>0?"POSITIVE":"NEGITIVE");
        while(op1){
                if(op1 & 1)
                {
                        result += op2;
                }
                printf("result=%d op1=%d and op2=%d\n", result, op1,op2);
                op1 >>=1;
                op2 <<=1;
        }
        return  (sign * result);
}

int main(){
        //int32_t a = -5, b = 13;
        int32_t a = -4, b = 13;
        //int32_t a = 6, b = -40;
        //int32_t a = 37, b = 15;
        //int32_t a = -40, b = -13;
        printf(" %d * %d = %d", a, b, mul(a,b));
}

