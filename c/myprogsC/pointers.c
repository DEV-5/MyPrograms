//Date:29-5-2018 
//Test objextive:find the student/students with the second most highest number 
//of Marks 
#pragma pack(1)
#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    float marks;
    char* name;
}stu;
    
 char*  Read_string()
{
    char ch = ' ',*chptr;
    int i;
    getchar();//clearing buffer contents
    chptr= calloc(1,sizeof(char));
    for (i=0;ch!='\n';i++)
    {
        chptr = realloc(chptr,(i+1)*sizeof(char));
        ch = getchar();
        chptr[i] = ch; 
    }
    chptr[i-1] = '\0'; 
    printf("Enter marks secured by %s:",chptr);
    return chptr;
}   

int main()
{

    int num_of_entries=0,i;
    stu * stu_array;
    /*
    int a=10 ,num_of_entries=0,i;
    char ch ='j';
    double f = 1.23; 
    void * voidptr;//declaring a void pointer
    voidptr = &a;
    printf("The value of a=%d ,ch =%c and f=%f\n",*((int*)(voidptr=&a )),*((char*)(voidptr=&ch )),*((double*)(voidptr=&f)));
    */
    printf("please enter the number of students: ");
    scanf("%d",&num_of_entries);
    stu_array = calloc(num_of_entries,sizeof(stu));
    /*//start of debug 1
    for(i=0;i<num_of_entries;i++)
     {   
         printf("stu_array=%ld stu_array+1=%ld stu_array.marks=%f and stu_array.name=%s \n ",stu_array,stu_array+1,stu_array[0].name,stu_array[0].marks);
     }
    //end of debug1*/
    for(i=0;i<num_of_entries;i++)
    {
        printf("please enter the name of student %d: ",i);
        stu_array[i].name = Read_string("");
        scanf("%f",&(stu_array[i].marks));
    }
    printf("Printing student data\n");
    
    for(i=0;i<num_of_entries;i++)
    {
        printf("student %d info: Name:%s and Marks aquired:%f\n",i,stu_array[i].name,stu_array[i].marks);
    }
}



