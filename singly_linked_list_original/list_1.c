#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    struct node
    {
        int val;
        struct node *next;
    };

    typedef struct node item;
    item *head, *curr, *temp;
    int i;

    head=NULL;

    for(i=1;i<=10;i++)
    {
      temp=(item *)malloc(sizeof(item));

      temp->val=i;
      temp->next=head;
      head=temp;
    }

    curr=head;

    printf("\n\n");
    while(curr!=NULL)
    {
        printf("%5d",curr->val);
        curr=curr->next;
    }
    printf("\n\n");
    return 0;
}
