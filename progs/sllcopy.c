
 //DATE: 20-10-16
 // program to implement sll

 #include<stdlib.h>
 #include<stdio.h>
//int scanf(const char*,...);
//int printf(const char*,...);
//int system(const char *(clear));

  typedef struct Node
  {
   int data;
   struct Node *next;
  }node;

  node * HEAD=NULL;
  int current;

 node* findlast();
 void print_sll();
 void insert_at();
 void delete_at();
 void menu();
 node* pospt(int pos);

 
  int main()
 {
   char ch='p';
   int dat,pos; 
    
   while(1)
  {  
    system("clear");    
    switch(ch)   
   {
     case 'i':
               insert_at();
               break;
     case 'd':
               delete_at();
               break;
     case 'p':
               print_sll(); 
               break;   
     case 'q':
               return 0;
               break;

      default:
              if(ch>='A'&&ch<='Z')
                 printf(" \n  CAPSLOCK IS ON OR YOU HAVE ENTERED CAPITAL LETTERS tryagain \n");    
              else 
                 printf("\n  you have entered the wrong option\n");   
   } 
      menu();  
      printf("\n  please enter  your choice: ");   
      scanf(" %c",&ch);
      while(getchar()!=10);
   }
             return 0;       
  }

 

  void print_sll()
 {
    node *temp;  
   printf("\n\t");
    if(HEAD == NULL)
      printf("  The SLL is empty\n");          
    else
    { 
     for(temp = HEAD;temp!=NULL;temp=temp->next)
     printf("%d ->",temp->data);
    }
 }
  
  void insert_at()
 {
   int data,pos;      
   node *last,*new,*temp;     
   new  = (node *)malloc(sizeof(node));
   printf("\n  Enter the data and corresponding position in which the data is to be inserted: ");            
   scanf(" %d %d",&data ,&pos); 
   new->next=NULL; 
   new->data=data;
   last = findlast();
  // printf("the value of current is %d, pos is %d and HEAD=%p \n",current,pos,HEAD);
   
   if(HEAD==NULL||pos==0)
   {
    if(pos>0)  
     printf("\n  Adding data at the end as the previous position is unoccupied \n");       
     new->next=HEAD;      
     HEAD = new;
   }
    else if(pos>current)
   {
    if(pos!=current+1)       
    printf("\n  Adding data at the end as the previous position is unoccupied \n");       
    last->next = new;
   }

   else
   {     
    temp = pospt(--pos);
   // printf("the value of temp->data= %d\n\n\n",temp->data);       
    new->next=temp->next;
    temp->next = new;     
   }
  }

  node* findlast()
 {     
   node *last;
    if(HEAD==NULL)
        return HEAD;   
 

   for(last=HEAD,current=0;last->next!=NULL;current++)
   last = last->next;    
   return last;
 }
 
   node* pospt(int pos)
  {
   node* a;      
   int i;      
   for(i=0,a=HEAD;i<pos;a=a->next,i++);
   return a;
  }
 
  void delete_at()
 {
   int pos;      
   node *nod,*temp;      
  
  
   if(HEAD==NULL)
  { 
   printf("\n  Unable to delete as the SLL is empty ");
   return ;
  }
   else
  {  
    nod = findlast();    
    printf("\n  Please enter the positon at which data is to be deleted: ");
    scanf("%d",&pos); 
    printf("\ncurrent=%d",current);
    if(pos==0)
   { 
    free(HEAD);
    HEAD=NULL;
   } 
    else if(pos>current)
    {    
       printf("\n  Unable to delete as the postion is unoccupied ");
    }
     else 
    { 
     nod = findlast();    
     nod = pospt(pos-1);
     temp = nod->next;
     nod->next=temp->next;   
     free(temp); 
    }       
  }
 }
 
  void menu()
 {
         
 printf("\n\n ******************MENU*******************\n");      
       printf("  PRESS:   \n\n");      
       printf("        p - TO DISPLAY CONTENTS OF SLL   \n");      
       printf("        i - TO INSERT NODE AT A POSITION \n");      
       printf("        d - TO DELETE NODE AT A POSITION \n");      
       printf("        q - TO QUIT THE PROGRAM \n\n");
 printf(" *****************************************\n");      
   return ;    
 }
