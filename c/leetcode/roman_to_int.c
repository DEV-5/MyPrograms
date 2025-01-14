/*
 *  Author: Vasudev M
 *  Date:   01/03/2024
 *  About: Program to convert roman to integers provided the input roman numerical ranges form 0 to 3999
 */

/* Header Declaration */

#include <stdio.h>

/* Macro definitions */

#define VALUE_OF_I 1
#define VALUE_OF_V 5
#define VALUE_OF_X 10
#define VALUE_OF_L 50
#define VALUE_OF_C 100
#define VALUE_OF_D 500
#define VALUE_OF_M 1000

/* Function Prototypes */

 int romanToInt(char *);


int main(void)
{
    char str[] = "IV";
    printf("Final Result = %d\r\n", romanToInt(str));
}

int romanToInt(char *str)
{
    int result = 0;
    unsigned short int idx = 0;
    if (str == NULL) {
        return 0;
    }
    do {
        switch (str[idx]) {
        case 'I':
            if (((*(str + 1))!= '\0') && ((str[idx + 1] == 'V') || (str[idx + 1] == 'X'))) {
                result -= VALUE_OF_I;
            } else {
                result += VALUE_OF_I;
            }
            break;

        case 'V':
            result += VALUE_OF_V;
            break;

        case 'X':
            if ((str[idx + 1] != '\0') && ((str[idx + 1] == 'C') || (str[idx + 1] == 'D'))) {
                result -= VALUE_OF_X;
            } else {
                result += VALUE_OF_X;
            }
            break;

        case 'L':
            result += VALUE_OF_L;
            break;

        case 'C':
            if ((str[idx + 1] != '\0') && ((str[idx + 1] == 'D') || (str[idx + 1] == 'M'))) {
                result -= VALUE_OF_C;
            } else {
                result += VALUE_OF_C;
            }
            break;

        case 'D':
            result += VALUE_OF_D;
            break;

        case 'M':
            result += VALUE_OF_M;
            break;

        default:
            printf("ERROR");
            break;
        }
        printf("itteration-%d: result:%d\r\n", (idx + 1), result);
    } while (str[++idx] != '\0');
    return result;
}
