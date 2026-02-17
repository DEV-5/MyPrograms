#include <stdio.h>
#include <stdint.h>

#define TOTAL_ELEMENTS  4
#define M     3

struct node{
        int data;
        struct node* next;
};

void add_node(struct nodes* head, int data)
{
    struct node *newnode  = (struct node*) malloc(sizeof(strcut node));
    newnode->data = data;

}

void reverseSLL(struct node* HEAD, uint32_t m)
{
        if ((!HEAD || !HEAD->next) ||((m < 2) || (m > n))
                return;

        struct node* cur = HEAD, prev = NULL, nxt = NULL;

        prev = HEAD;
        for (int idx = 0; idx < m; idx++){
                cur->next = prev;
                nxt = cur->next;
                prev = cur;
                cur = nxt;


                next

                if(!nxt)
                        return;
       }
}

int main(){
        // input: 1 -> 2 -> 3 -> 4-> 5
        // expected out for n =3: 3->2-> 1 -> 4 -> 5
        add_node(HEAD, 2);
        add_node(HEAD, 3);
        add_node(HEAD, 4);

        reverseSLL(head, NUM);

}
