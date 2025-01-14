 // name:DEV 
 
 #include<stdlib.h>
 #include <stdio.h>
 
  void main ()
 {
   int *i;
   printf("\n\tplease enter the no entries persent");
   
   i = (int*)calloc(4,sizeof(int));
   *i= 45;
   *(i+1)=55;
   *(i+2)=65;
   *(i+3)=67;
   
   for(int j=0;j<4;j++)
   {    
    printf("\n  the data present in I%d is %d ",j,*(i+j));
   }
       
}

 
