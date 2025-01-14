/*
 *  Author: Vasudev M
 *  Date:   03/03/2024
 *  About: Program to convert string has valid parentheses
 */

/* Header Declaration */
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

/* Macro definitions */
#define END_OF_STRING               '\0'
#define stackPush(stk, val)         stk.top ++; \
                                    stk.array[stk.top] = val; \
                                    printf("top char= %c\r\n", stk.array[stk.top])
#define stackPop(stk)               (stk.array[stk.top--])
#define stackEmpty(stk)             (stk.top == -1)

/* Function Prototypes */
bool isValid(char *str);

/* type define */
typedef struct{
    int16_t top;
    char* array;
}stack;

int main(void)
{
    char str[] = "((";
    printf("Final Result = %s\r\n", isValid(str)?"TRUE":"FALSE");
}

bool isValid(char *str)
{
    uint16_t idx;
    //setup stack
    stack stk;
    stk.top = -1;
    stk.array = (char*)malloc((strlen(str) - 1) * sizeof(char));

    for(idx = 0; str[idx] != END_OF_STRING; idx++)
    {
        switch(str[idx])
        {
            case '(':
                stackPush(stk, '(');
                break;
            case '[':
                stackPush(stk, '[');
                break;
            case '{':
                stackPush(stk, '{');
                break;
            case ')':
                if ((stackEmpty(stk)) || (stackPop(stk) !='('))
                {
                    return false;
                }
                break;
            case ']':
                if (stackEmpty(stk) || (stackPop(stk) !='['))
                {
                    return false;
                }
                break;
            case '}':
                if (stackEmpty(stk) || (stackPop(stk) !='{'))
                {
                    return false;
                }
                break;
            default:
                break;
        }
    }
    return stackEmpty(stk);
}
