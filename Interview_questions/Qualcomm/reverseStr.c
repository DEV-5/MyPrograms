
#include <stdio.h>
#include <string.h>

int main(){
char strSrc[] = "This is test string";

printf("String value = %s\n", strSrc);
for (int start = 0, end = strlen(strSrc) -1 ; start < end; start++, end--)
{
        char temp;
        temp = strSrc[start];
        strSrc[start] = strSrc[end];
        strSrc[end] = temp;
}
printf("String value = %s\n", strSrc);
}
