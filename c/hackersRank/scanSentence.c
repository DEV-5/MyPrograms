/*
Task
You have to print the character,
, in the first line. Then print in next line. In the last line print the sentence,


Input Format

First, take a character,
as input.
Then take the string, as input.
Lastly, take the sentence

as input.

Constraints

Strings for
and

will have fewer than 100 characters, including the newline.

Output Format

Print three lines of output. The first line prints the character,
.
The second line prints the string, .
The third line prints the sentence,

.

Sample Input 0

C
Language
Welcome To C!!

Sample Output 0

C
Language
Welcome To C!!
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define BUFF_SIZE 101  

static char* read_sentence(char* str_ptr)
{
    int charReadCount = 0;
    int blockSize = 1;
    char temp_ch = '\0';
    char * currentCharPtr = str_ptr;
    do{
        charReadCount++;
        if(charReadCount >= BUFF_SIZE)
        {
            blockSize++;
            str_ptr = (char *) realloc((void *) str_ptr, (blockSize * BUFF_SIZE));
            currentCharPtr = str_ptr + ((blockSize - 1) * BUFF_SIZE);
        }
        scanf("%c", &temp_ch);
        *currentCharPtr = temp_ch;
        currentCharPtr++;
    }while(temp_ch != '\0');
    return str_ptr;
}

int main() 
{
    char ch, *stri, *sen;
    stri =  (char *) malloc(BUFF_SIZE);
    sen  =  (char *) malloc(BUFF_SIZE);
            
    scanf("%c", &ch);
    stri = read_sentence(stri);
    sen = read_sentence(sen);
    printf("%c\r\n%s\r\n%s", ch, stri, sen);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
