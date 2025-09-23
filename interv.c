
#define NODE_NUM 5

struct node{
      int data;
      struct node* next;
   };
   
   void edit_node(struct node* head){
      // go to 5th node and increment value;
      struct node  *temp = head; 
       for (int i = NODE_NUM; i >0; i--){
        temp = temp->next;
      }
       temp->data += 1; 
   }
