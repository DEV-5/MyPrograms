
//DATE:18-12-16
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdarg.h>

void pf(const char *,...);
void printint(int);
 void printdouble(double d);

int main()
{
 int input=75;
 char ch='s';
 double real;
 //pf("please enter a number: ");
// scanf("%d",&input);
 //while(getchar()!=10);
// pf("please enter a character: ");
 //scanf("%c",&ch);
 pf("please enter a real number followed by a char and a integer: ");
 scanf("%lf %c %d",&real,&ch,&input);
 pf("this is a %s message:%d:<%c>|%f| \n","test",input,ch,real,45);
}
 void pf(const char* str,...)
{
 char ch,*strptr;
 short int si;
 int i;
 long int li;
 float f;
 double d;
 va_list handle;
 va_start(handle,str);
 //puts(str);
 //printf("%s\n",str);
 //while(ch = va_arg(handle,char))
 while(*str)
 {
  if((*str)!='%')
  putchar(*str);
  else
  {
   str++;
    switch(*str)
   {
    case 'd': 
             i = va_arg(handle,int);
	     printint(i);
             break;
    case 'c':
             putchar(va_arg(handle,int));
             break;	     
    case 's': 
             fputs(va_arg(handle,char*),stdout);
             break;
    case 'f':
             d = va_arg(handle,double);
             printdouble(d);
             break;
  
    default :  
	     putchar('%');
	     putchar(*str);

   }
  }
  str++;
 }
 //please insert code here//
 va_end(handle);
}

 void printint(int num)
{
 char *st;
 st = calloc(20,1);
 st++;
// if(num>=0)
// getchar('-');
if(num==0)*(st++)=48;
 while(num)
 {
  *st=(48+(num%10));
  num/=10;
  st++;
 }
 do
  {
   st--;
   putchar(*st);
  }while(*st);
 //printf("\n printint successfull\n");
}

 void printdouble(double d)
{
 double d2=d;
 int i=0,no=0;
 d-=(int)d;
// printf("before:%lf\n",d);
  while(i<6)
 {
  d*=10;
  i++;
 // printf("%lf\n",d);
 }
 no=d;
 if((no%10)>=5)
  no++;
// printf("%lf\n",d);
 printint((int)d2); 
 putchar('.');
 printint(no); 
}





