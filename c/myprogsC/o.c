
#include<stdio.h>
#include<string.h>
 
typedef struct{
               char name[10];
               int price;
               int speed;
               }fan;
        
 int main()
 {
        //name,price,speed    
  fan a={"ketan",1200,1500};
  fan b= {"usha",1450,1800};
  
  printf("%s has a speed of %d R.P.M and costs around %d Rs",a.name,b.speed,a.price);
 
  return 0;
}
