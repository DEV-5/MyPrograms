//DATE:4-11-16
//purpose: program to delete or replace a string.
//

//To Do
//need to add flush mechanism to the function ---DONE added use getchar to get the char and wait until an enter is detected.
//detemine why printing a sting is causing a segmentation fault
//implement string replacement logic ---DONE

#include<stdio.h>
int printf(const char*,...);
int scanf(const char*,...);
char *gets(char*);
#include<string.h>
#include<stdlib.h>

int string_edit(char* sp,char*sm,char*char_null ,char);
static char* input_string_dynamic();
void upper_to_lower_case(char* chptr);

int main()
{
    int count;
    //char st[40]=" mon k   ey  ";
    char *st='\0',*sm='\0',*replacement_string='\0',select='\0',char_null='\0';
    printf("\n please enter a string1:");
    st = input_string_dynamic((char*)NULL);
    //st[strlen(st)-1]=0;//placing a null character at the end of the string
    printf("\n please enter a string2:");
    sm = input_string_dynamic((char*)NULL);
    //fgets(sm,40,stdin);
    //sm[strlen(sm)-1]=0;//placing a null character at the end of the string
    printf("String1:%s:\n",st);
    printf("String2:%s:\n",sm);

    while(select !='r' && select!='R' && select !='d' && select !='D')
    {
        printf(" press 'r' to replace and 'd' to delete the entered second string\n");
        scanf(" %c",&select);
        while(getchar()!=10);//flushing the input buffer
        upper_to_lower_case(&select);
        printf("the value of select is: %c\n",select);
        if(select =='d')
            count=string_edit(st,sm,"NO",select);
        else if(select=='r')
        {
            printf("\n please enter a replacement string:");
            replacement_string = input_string_dynamic(sm);
            count = string_edit(st,sm,replacement_string,select);
        }
    }
    //puts(st);
    //count=del_sm(st,sm);
    printf("String1:%s:\n",st);
    printf("String2:%s:\n",sm);
    printf("\n%d\n",count);
    //puts(st);
    return 0;
}

 int string_edit(char* sp,char * sm,char *Replacement_string,char select)
{
  int count, adjustment_length = strlen(sm) - strlen(Replacement_string); 
  char *p;
 //Debug string //printf("inside string_edit fn sp=|%s|, sm =|%s|, replacementstring=|%s| and select=|%c|\n",sp,sm,Replacement_string,select);
  for(p=sp,count=0;p = strstr(p,sm);)
  {
    count++;
    if(select=='d')
        memmove(p,p+strlen(sm),strlen(p+strlen(sm))+1);
        
    else//replace
    {
        printf("inside else of string_edit\n");
        if(adjustment_length<0)
            sp=realloc(sp,sizeof(char)*(strlen(sp)+1-adjustment_length));
       
        memmove(p+strlen(Replacement_string),p+strlen(sm),strlen(p+strlen(sm))+1);
        strncpy(p,Replacement_string,strlen(Replacement_string));
        p+=strlen(Replacement_string)+1;    
    }
    
  }
  return count;
}

/*
 *  Dynamically allocate space and  store the user inputed string. 
 *  @Input
 *      strptr: character pointer in which the starting address of the mentioned string is stored.
 */
static char* input_string_dynamic(char* strptr)
{
    int i;
    char ch;
    if(strptr == NULL)
        strptr = (char*)calloc(sizeof(char),1000);
    //scanf("%s",strptr);
    for(ch='\0',i=0;ch!=10;i++)
    {
        ch = getchar();
        *(strptr+i) = ch;
    }
    *(strptr+i-1) = '\0';//setting the last character of the string to null
    strptr = (char*)realloc(strptr,sizeof(char)*strlen(strptr)+1);
    
    printf("\nthe value of strptr is:%d, the string is:%s and its stringlength is:%d \n",strptr,strptr,strlen(strptr));
    return strptr;
}


void upper_to_lower_case(char* chptr)
{
 if (*chptr >='A' && (*chptr)<= 'Z')
    *chptr +=32;    
 return;
}
