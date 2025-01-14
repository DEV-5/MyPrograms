
 #include<stdio.h>
   
  void main ()
 {
     char c;
   FILE *fp;
    fp = fopen("/home/v_dev/programming/c/myprogsC/sample.txt" , "r");
     if(fp == NULL )
     {
        printf("this file does not exist\n"); 
    }
    else
    {
        while((c=getc(fp)) !=EOF)
      {      
        putchar(c);  
      } 
     printf("|End of function\n");   
     fclose(fp);
   }
 }
