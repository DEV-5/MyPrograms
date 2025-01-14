//DATE:7-11-16
#include<stdio.h>
#include<string.h>
void input_string(char *str);
void reverse_str(char *str,char*p);

int main()
{
    //int i;
    char st[30],rev[30];
    input_string(st);
    printf("\nthe string you have entered is :%s:\n",st);
    reverse_str(st,rev);  
    printf("\nthe reverse of the entered string is :%s:\n",rev);
    return 0;
}
 

void input_string(char *str)
{
    printf("\n\n please enter a  string the string :  ");
    //scanf("%s",st);
    fgets(str,30,stdin);
    str[strlen(str)-1]=0;
}

void reverse_str(char *str,char *rev)
{
    int i=0;
    int STR_SIZE = strlen(str);
    rev+=(STR_SIZE);//adding array size offset
    *(rev--) =0;
    for(;i<STR_SIZE;str++,rev--,i++)
        *rev=*str;
    rev++;
    return;
}
