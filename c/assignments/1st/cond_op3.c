//date:5-10-2016
//conditional operator based assignment
//enter three intigers and find the highest

 #include<stdio.h>
 #include<stdlib.h>
 
  void  movie()
 {
   int a,b,c;
   system("clear");
   printf("please enter the three numbers : ");
   scanf("%d%d%d",&a,&b,&c);
   (a>b)?(a>c)?printf("\n\t a(%d)",a):printf("\n\t c(%d)",c):(b>c)?printf("\n\t b(%d)",b):printf("\n\t c(%d)",c);
   printf(" is the biggest number\n");
   exit(0);
 }
