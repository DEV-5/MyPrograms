//AUTHOR:DEV
//program :in function call

 #include<stdio.h>
 #include<string.h>

char* popo();
 
 char a[7];	
int main ()
{
 printf("time = %d",system("time"));
 printf("the data to be entered is %s",popo());
 printf("time = %d",system("time"));
 return 0;
}

 char*  popo()
{
 strcpy(a,"green");	
 return a;
}
