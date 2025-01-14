
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
 void menu();
 node* pospt(int pos);

 
  int main()
 {
         
    int ch ;
   
     while(1)
    { 
        system("clear");    
        menu();  
        scanf(" %d",&ch);
      switch(ch)
     {
     case 2:
             print_sll();
             break;
     case 3:
             insert_at();
             break;
     case 4:
             return 0;       
     default:
            printf("\nyou have entered the wrong option\n");   
            
     }
    }
    return 0;
 }

  void print_sll()
 {
    node *temp;  
    
    printf("\n in print_sll\n");
    if(HEAD == NULL)
    printf("\nThe SLL is empty\n");     
         
    else
    { 
     for(temp = HEAD;temp!=NULL;temp=temp->next)
     printf(" %d->",temp->data);
    }
 }
  
  void insert_at()
 {
   int data,pos;
   printf("enter the data and its position :");
   scanf(" %d %d",&data ,&pos);   
   node *last,*new,*temp;     
   new  = (node *)malloc(sizeof(node)); 
   new->data=data;
   last = findlast();
  // printf("the value of current is %d, pos is %d and last=%d \n",current,pos,last->data);
   if(HEAD==NULL||pos==0)
   {
     new->next=HEAD;      
     HEAD = new;
   }
   else if(pos>current)
   {
    if(pos!=current+1)       
    printf("adding data at the end as the previous position is unoccupied \n");       
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
 
  void menu()
 {
         
  printf("\n\t*************MENU*************\n");      
    printf("\t DISPLAY CONTENTS OF SLL: 1 \n");      
    printf("\t ADD NODE AT A POSITION: 2\n");      
    printf("\t EXIT: 3 \n");
   return ;    
 }
