//name:DEV

 #include<stdio.h>
 #include<string.h>

   typedef struct
 {
  int val;
  char g[20]; 
 }Titan;

 void main ()
 {
  Titan go;
  go.val = 17;
  strcpy(go.g, "this will work ");
  printf("\n %s %d\n",go.g,go.val);
  return;
 }
