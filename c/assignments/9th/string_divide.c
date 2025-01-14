//DATE:3-11-16
//divide a given string into two halves and then swap their values
#include<stdio.h>
#include<string.h>
#define s 20
#define hs (s+1)
int main()
{
char mom[s],son[hs],dau[hs],temp[hs];
int mid;
printf("\nplease enter a string :");
fgets(mom,sizeof(mom),stdin);
mom[strlen(mom)-1]=0;
mid =strlen(mom)/2;
strncpy(son,mom,mid);
strcpy(dau,mom+mid);
strcpy(temp,"");
strcpy(temp,son);
strcpy(son,dau);
strcpy(dau,temp);
printf("\n son=%s;dau=%s\n",son,dau);
}
