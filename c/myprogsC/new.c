
  #include<stdio.h>
  #include<string.h>
  #include<stdlib.h>
   
    void main()
   {
    unsigned int k; 
    char *a,*ar;
    a=(char*)calloc(60,sizeof(char));

    printf("please enter a name : ");     
    scanf("%s",a); 
    k = strlen(a);
    a = (char*)realloc(a,sizeof(int)*(k));
    ar =(char*)calloc(k,sizeof(char));
    strcpy(ar,a);
    free(a);
    printf("\n");
    for(int i=0;i<k;i++)
   { 
        printf("%s-",a);
   }
    
    printf("\n");
    printf("\nerror check :%c %c",*(ar+k+1),*(ar+k-1));
    printf("test\n");
   }
