#include<stdio.h>
#include<string.h>
#include<stdlib.h>

 void sort (char p[][80],int cnt);
 void swap(char*str1,char*str2);
 int main(int argc,char** argv)
{
 char line[15][80];
 FILE *fp;
 int i,cnt;
 if(argc!=2){printf("\n Incorrect arguments provided\n");return 0;}
 
 fp=fopen(argv[1],"r");
 if(fp==NULL){printf("sorry the source file does not exist");return 0;}
 
 for(i=0,cnt=0;fgets(line[i],80,fp);cnt++,i++); 
 fclose(fp);
 printf("\n count:%d\n",cnt);
 for(i=0;i<cnt;i++)
   printf("%s",line[i]); 

 sort(line,cnt);
printf("\n after sort\n");
  for(i=0;i<cnt;i++)
   printf("%s",line[i]); 
fp=fopen(argv[1],"w");
for(i=0;i<cnt;fputs(line[i],fp),i++);
}

 void sort (char p[][80],int cnt)
{
 int i,j;
 for(i=cnt-1;i>0;i--)
         for(j=0;j<i;j++)
         if(strcmp(p[j],p[j+1])>0)
                 swap(p[j],p[j+1]);
}

 void swap(char *str1,char *str2)
{
 char temp[80];
 strcpy(temp,str1);
 strcpy(str1,str2);
 strcpy(str2,temp);
 return ;
}
