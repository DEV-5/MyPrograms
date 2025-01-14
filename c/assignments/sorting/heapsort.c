//DATE: 18th July 2020
//Author: V_DEV
#include <stdio.h>
#include <stdlib.h>

#define NO_OF_NODES 8

typedef struct linklist{
    int data;
    int count;
}node;

typedef struct tree{
    int data;
    int count;
    struct linklist* left_child;
    struct linklist* right_child;
}tnode;

tnode* heapsort(node* );
void printtree(tnode*);

int main()
{ 
    node* arr = malloc(sizeof(node)*NO_OF_NODES);
    //12,14,6,134,2,33,17,109
    arr[0].count = 12;
    arr[0].data  = 1;
    arr[1].count = 14;
    arr[1].data  = 3;
    arr[2].count = 6;
    arr[2].data  = 2;
    arr[3].count = 134;
    arr[3].data  = 5;
    arr[4].count = 2;
    arr[4].data  = 89;
    arr[5].count = 33;
    arr[5].data  = 8;
    arr[6].count = 17;
    arr[6].data  = 60;
    arr[7].count = 109;
    arr[7].data  = 11;

    tnode* result = heapsort(arr);
    printtree(result);
}

tnode* heapsort(node * arr)
{
    //1.heapify
    tnode* tn = malloc(sizeof(tnode));
    tnode* root;
    root->data =  
    root->data = 


    return tn; 
}
void printtree(tnode* tn)
{
    //print the entire tree
}
