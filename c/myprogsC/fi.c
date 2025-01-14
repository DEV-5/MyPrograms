
 #include<stdio.h>
 #include<stdlib.h>
 
FILE *fp;
  
  void main()
 {
   if((fp = fopen("/home/dev/cprog/TEMP.txt", "r")) == NULL);
  {
   printf(" hi error opening TEMP.txt");
   exit(100);   
  }
     printf("this works\n");     
      fclose(fp);
  
 }
