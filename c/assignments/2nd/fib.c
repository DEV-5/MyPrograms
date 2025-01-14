
 //DATE:14-10-16
 //program to print  fibonacci series

 int system(const char*(clear));
 int scanf(const char*,...);
 int printf(const char*,...);
 void fibonacci(int);
  int main()
 { 
    int max=0,fi=0,num=0,temp=1;
    system("clear"); 
    printf("\nplease enter  the  fibinocii limit:  ");
    scanf(" %d",&max);
    printf("\nthe fibinocii sequence is as follows : \n \t");
    fibonacci(max);
 }

void fibonacci(int max)
{
    int temp,num,fi;
    for(temp=0,fi=0,num=1;max>=fi;num=temp)
    {
        printf(" %d",fi);
        temp =fi; 	  
        fi+=num;
    }
    printf("\n");
} 
