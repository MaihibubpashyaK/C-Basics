#include<stdio.h>
typedef struct node
{

    int data;
    struct node *next;

}node;
typedef void (*callback)(node *dis);//pointer to a function

node *create(node *head,int data)
{
    node *new_node = (node *)malloc(sizeof(node));
    if(new_node == NULL)
    {
        printf("Error found while creating a new node\n");
        exit(0);
    }
    new_node->data = data;
    new_node->next = head;

    return new_node;

}
node *prepend(node *head,int data)
{

    node *new_node = create(head,data);
    head = new_node;

    return head;
}
void display(node *dis)
{

    if(dis != NULL)
    {
      printf("%d->",dis->data);
    }

}

void traverse(node *head,callback f)
{
    node *cursor = head;
    printf("\n\nSingly Linked List:\n\n");
    while(cursor != NULL)
    {

        f(cursor);
        cursor = cursor->next;
    }
    printf("\n\n");
}

void menu()
{

    printf("--- C Linked List Demonstration --- \n\n");
    printf("0.menu\n");
    printf("1.prepend operation\n");
    printf("-1.quit\n");


}


void main()
{
    node *head = NULL;
    int data;
    int command;

    callback disp =display;

    menu();
    while(1)
    {

        printf("\n\nEnter the command(0-1),press -1 to quit\n");
        scanf("%d",&command);

        if(command == -1)
          break;

        switch(command)
        {

        case 0:
            menu();

        case 1:
            printf("\nEnter the number to be prepended\n");
            scanf("%d",&data);
            head = prepend(head,data);
            traverse(head,disp);

        default:
            printf("\n");
        }


    }

}

