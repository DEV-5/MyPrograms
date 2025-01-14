//DATE:9-11-16
#include<stdio.h>
#include<string.h>
int notenough_args(int argc);
int not_integer(char * str);
int not_float(char * str);
void data_verify(char **argc,int argv);
int verify_operator(char  **argv,int argc);
int verify_operand(char **argv,int argc);
 void stof(char *str,int dec);
 void stoi(char *str);

float f[2];
int in[2];
static int d;

void main(int argc,char**argv)
{
 int res;
 if(notenough_args(argc))
  return ;
 data_verify(argv,argc);
 if(d==-1||d==-2)
  printf("\n Arguments type error\n");
 if((argv[2][0]=='%') && d) 
 {
  printf("\n   modular division on float data is not possible\n");         
  return;
 }
  switch(argv[2][0])
 {
  case '+' : 
            if(d==0)
            { 
              printf("\n %d\n",in[0]+in[1]);
              return;
            }
            if(d<2)
           {
             printf("\n %d\n",(int)f[0]+in[0]);
             return;
           } 
            printf("\n %f\n",f[0]+f[1]);
            return;
              

  case '-' : if(d==0)
            { 
              printf("hello1");
              printf("\n %d\n",res=in[0]-in[1]);
              return;
            }
            if(d<2)
           {
              printf("hello2");
             printf("\n %d\n",res=(int)f[0]-in[0]);
             return;
           } 
            printf("\n %f\n",f[0]-f[1]);
            return;
              
  case '*' : if(d==0)
            { 
              printf("\n %d\n",in[0]*in[1]);
              return;
            }
             if(d<2)
            {
             printf("\n %d\n",(int)f[0]*in[0]);
             return ;
            } 
            printf("\n %f\n",f[0]+f[1]);
            return;
               
               
  case '/' : if(d==0)
            { 
              printf("\n %d\n",in[0]/in[1]);
              return;
            }
            if(d<2)
           {
             printf("\n %d\n",(int)f[0]/in[0]);
             return ;
           } 
            printf("\n %f\n",f[0]/f[1]);
            return;
             
         
  default: 
    printf("\n something went wrong \n");       
 }
}

 void data_verify(char **argv,int argc)
{
 int a;
 a=verify_operand(argv,argc);
 printf("\n **************a=%d**%d****************** after operand",d,a);
 if(a==-1)
  return ;
 printf("\n **************a=%d**%d****************** after operand",d,a);
 //printf("\n ************************************* after operand");
 d = verify_operator(argv,argc);
 return;
}

int notenough_args(int argc)
{
 if(argc!=4)
 {
  printf("\n ERROR no of arguments are wrongly specified");
  printf("\nThe correct format is ./a.out <arg1> <arg2> <arg3>\n");
  return 1;
 }
 return 0;
}
 int not_integer(char *str)
{  
 printf("\nchecking if the input is an integer\n");     
   for(;*str;str++)
  {
   if(!((*str>=48)&&(*str<=57)))
   {  printf("\nthe input is not an integer\n");     
     return 1;   
   }
  }
 printf("\nthe input is an int\n");     
 return 0;
}

int not_float(char * str)
{
 printf("\nchecking if the input is an float\n");     
 int i;
 for(i=0;str[i];i++)       
 if(str[i]=='.')
 { 
  memmove(str+i,str+i+1,strlen(str+1)+1);
  break;
 }  
 if(not_integer(str)) 
 { 
    printf("\nthe input is an not float\n");     
         return -1;
 }
 stof(str,strlen(str)-i-1);
 printf("\nthe input is a FLOAT \n");     
 return i;
}

 int verify_operand(char **argv,int argc)
{
 int i,j;
  for(i=1,j=0;i<=argc;i+=2,j++)
 { 
   printf("\npresent check for arg[%d]\n",i);      
   if(not_integer(argv[i]))
  { 
   if(not_float(argv[i])==-1)
    return -1;     
   d+=i; 
  }
 else
  stoi(argv[i]);
 }
  printf("\n-------------d=%d--------------------end of  verify operand----",d);
 return d;
}
 
 int verify_operator(char  **argv,int argc)
{
 int i,j;
 printf("\n launch sucessful \n");
 char sym[]="+-*/%";
 for(j=2;j<=argc;j+=2)
 { 
  if(strlen(argv[j])!=1)
     return -2;
   for(i=0;sym[i];i++)
  { 
   if(argv[j][0]==sym[i])
   break;
  }  
  if(i==5)
   return -2;
 } 
 return d;
}

 void stof(char *str,int dec)
{
 int j;
 float fl; 
 static int i;
 for(fl=0;*str;str++)         
     fl=fl*10+(*str-48);
 for(j=0;j<=dec;j++)
     fl/=(float)10; 
 f[i]=fl;
 printf("\nnew float entry f[%d]=%f\n",i,f[i]);
 i++;
 return; 
}

 void stoi(char *str)
{
 int a;       
 static int i;
 for(a=0;*str;str++)         
     a=(a*10)+(*str-48);
  in[i]=a;
 printf("\nnew integer entry in[%d]=%d\n",i,in[i]);
 i++;
}



