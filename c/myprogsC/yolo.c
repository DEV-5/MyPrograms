
 #include<stdio.h>
 #include<string.h>
 #include<stdlib.h>
  
  void space();
  
  void main(void)
 {
   char arr[]="sale";
//    char*d;
   char d[2]="this won't work";
//    d=(char*)calloc(2,sizeof(char));
   space();
   
    for(int g=0;g<10;g++)
   {
    printf("%d-",g);     
   }

    *d = 's';
    *(d+1) ='a';
   *(d+2) = '\0';
    *(d+3) = 'd';
    
    //strcpy(d,arr);
   
    strcpy(arr,"sid");
    space();
   
   for(int i=0; i<8;i++)
  {
   printf("%c-",arr[i]);   
  }
   space();
   printf("%s\n\t\t",d);
   
   for(int j=0;j<4;j++)
  {
    printf("%c-",*(d+j));     
  }
   space();
 }
  
  void space()
 {
   printf("\n\t\t"); 
 }
 
