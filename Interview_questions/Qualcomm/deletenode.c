
//1 -> 3 -> 5 -> 7(to be added)


struct node{
        int data;
        struct node *next;
};

uint8_t add_at_last(struct node * head, int datatwowrite)
{
    struct node *newnode (struct node*) malloc(sizeof(struct node));
    newnode->data = datatwowrite;
    newnode->next = NULL;
    while(head->next !=NULL)
        head = head->next;
    // attach node at the end
    head->next = newnode;
} 
