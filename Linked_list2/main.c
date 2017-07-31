#include<stdio.h>
typedef struct node
{

    int data;
    struct node *next;

}node;
typedef void (*callback)(node *dis);//pointer to a function
node *create(node *,int );

void insert_before(node *btmp,node *temp,int data)
{
    node *temp1;
    node *new_node = create(temp,data);
    while(btmp != NULL)
    {
       if(btmp == temp)
       {
         temp1->next = new_node;
         break;

       }
       temp1 = btmp;
      btmp = btmp->next;
   }
}


void insert_after(node *temp,int data)
{
    node *old_node = temp->next;
    node *new_node = create(temp->next,data);
    temp->next = new_node;


}
node* search(node* head,int data)
{

    node *cursor = head;
    while(cursor!= NULL)
    {
        if(cursor->data == data)
            return cursor;
        cursor = cursor->next;
    }
    return NULL;
}
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

/*
    add a new node at the end of the list
*/
node *append(node  *head,int data)
{
    node *cursor = head;
    if(head == NULL)  //If append node is the first node,it prints nothing
        return NULL;


    while(cursor->next != NULL)
    {
       cursor = cursor->next;
    }
    node *new_node = create(NULL,data);
    cursor->next = new_node;

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

node *front_delete(node *head)
{
   node *front = head;
   if(head == NULL)
    return NULL;
   head =head->next;
   front->next = NULL;
   front = front->next;
   if(head == front)
     head = NULL;
   free(front);
   return head;

}
node *back_delete(node *head)
{
   node *cursor = head;
   node *temp;
   if(head == NULL)
    return NULL;
    if(cursor->next == NULL)
    {
        cursor->next = NULL;
        free(cursor);
        return NULL;    }



   while(cursor->next != NULL)
   {
       temp = cursor;
       cursor = cursor->next;

   }

   temp->next = NULL;
   free(cursor);
   return head;



}
node *delete_node(node *head,int data)
{
    node *cursor = head;
    node *temp = NULL;
    while(cursor->data != data)
    {
        temp = cursor;
        cursor = cursor->next;
    }

    temp->next = cursor->next;
    cursor->next = NULL;
    free(cursor);

    return head;

}
node *assending(node* head)
{
    node *cursor = head;
    node *temp = head;
    int count = 0;
    while(cursor != NULL)
    {
     count++;
     cursor =cursor->next;
    }
    int i=0,j=0;
    printf("count =%d",count);
    count--;
    for(i=0;i<count;i++)
    {
        for(j=0;j<count;j++)
        {
          if(temp->data > temp->next->data)
          {
              int swap;
              swap = temp->data;
              temp->data = temp->next->data;
              temp->next->data = swap;
          }
          temp = temp->next;
        }
        temp = head;
    }

    return head;
}
void menu()
{
    printf("--- C Linked List Demonstration --- \n\n");
    printf("0.Display all the elements\n");
    printf("1.menu\n");
    printf("2.prepend operation\n");
    printf("3.append operation\n");
    printf("4.Key search operation\n");
    printf("5.Insert after the element\n");
    printf("6.Insert before the element\n");
    printf("7.Remove the front element\n");
    printf("8.Remove the last(back) element\n");
    printf("9.Remove any element between the first and last element\n");
    printf("10.Assending Operation\n");
    printf("-1.quit\n");
}


void main()
{
    node *head = NULL;
    int data;
    int command;
    node *temp = NULL;
    callback disp =display;

    menu();
    while(1)
    {

        printf("\n\nEnter the command(0-1),press -1 to quit:");
        scanf("%d",&command);

        if(command == -1)
          break;

        switch(command)
        {
        case 0:
            traverse(head,disp);
            break;

        case 1:
            menu();
            break;
        case 2:
            printf("\nEnter the number to be prepended:");
            scanf("%d",&data);
            head = prepend(head,data);
            traverse(head,disp);
            break;
        case 3:
            printf("\nEnter the number to be appended:");
            scanf("%d",&data);
            head = append(head,data);
            traverse(head,disp);
            break;

        case 4:
            printf("\nEnter the number to be searched:");
            scanf("%d",&data);
            temp = search(head,data);
            if(temp != NULL)
               printf("Number %d is found\n",data);
            else
              printf("Number %d is not found\n",data);
            break;

        case 5:
            printf("Select the number after which you want to add a new number:");
            scanf("%d",&data);
            temp = search(head,data);
            if(temp != NULL)
            {
                printf("Enter the new number that you want to insert after the %d",data);
                scanf("%d",&data);
                insert_after(temp,data);
            }
            else
            {
                printf("Entered number is not valid\n");
            }
            break;

        case 6:
            printf("Select the number before which you want to add a new number:");
            scanf("%d",&data);
            temp = search(head,data);
            if(temp != NULL)
            {
                printf("Enter the new number that you want to insert before the %d:",data);
                scanf("%d",&data);
                insert_before(head,temp,data);
            }
            else
            {
                printf("Entered number is not valid:");
            }
            break;

        case 7:
            printf("front node has been deleted\n");
            head = front_delete(head);
            traverse(head,disp);
            break;

        case 8:
            printf("last node has been deleted\n");
            head = back_delete(head);
            traverse(head,disp);
            break;

        case 9:
            printf("Enter the node that you wanna delete:");
            scanf("%d",&data);
            head = delete_node(head,data);
            traverse(head,disp);
            break;

        case 10:
            printf("ASSENDING ORDER\n");
            head = assending(head);
            traverse(head,disp);
            break;



        default:
            printf("Please choose right option:");
            break;
        }


    }

}

