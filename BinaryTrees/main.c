#include <stdio.h>
#include <stdlib.h>

typedef struct node
{

    int data;
    struct node *left;
    struct node *right;
}node;
typedef int (*callback)(int,int);
node *create(int data)
{

    node *new_node = (node *)malloc(sizeof(node));
    if(new_node == NULL)
    {

        printf("Error found while allocating memory\n");
    }
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}
int compare(int rdata,int odata)
{
   if(rdata < odata)
        return 1;
   else if(rdata > odata)
        return -1;

   return 0;

}
node *insert_new_data(node *root,callback compare,int data)
{

    if(root == NULL)
    {
     root = create(data);
    }
    else
    {
        node *cursor = root;
        node *prev;
        int cmp;
        int is_left;
        while(cursor != NULL)
        {
        cmp = compare(data,cursor->data);
        prev = cursor;
        if(cmp > 0)
        {
            is_left = 1;
            cursor = cursor->left;
        }
        else
        {
            is_left = 0;
            cursor = cursor->right;

        }
      }
       if(is_left)
       {
         prev->left = create(data);

        }
    else
        {
        prev->right = create(data);
        }
   }

return root;
}

void display(node *root)  //pre-order
{
   node *disp = root;
   if(root == NULL)
        return ;
      printf("%d",disp->data);
      if(disp->left != NULL)
      {
          printf("(L:%d)",disp->left->data);
      }
     if(disp->right != NULL)
      {

       printf("(R:%d)",disp->right->data);
      }
   printf("\n");
      display(disp->left);
      display(disp->right);
}

void in_order(node *root)
{
   //Left Root Right
   if(root == NULL)
    return;
    in_order(root->left);
    printf("%d\t",root->data);
    in_order(root->right);
}
void post_order(node *root)
{
//Left Right Root
if(root == NULL)
    return;
post_order(root->left);
post_order(root->right);
printf("%d\t",root->data);

}

int size(node *root,int count)
{
    if(root == NULL)
        return count;

    count++;
    size(root->left,count);
    size(root->right,count);


}
int hight(node *root)
{
      if (root == NULL)
       return -1;
   else
   {
       /* compute the depth of each subtree */
       int lDepth = hight(root->left);
       int rDepth = hight(root->right);

       /* use the larger one */
       if (lDepth > rDepth)
           return(lDepth+1);
       else return(rDepth+1);
   }

}
void menu()
{
    printf("Binary Tree Implementation\n");
    printf("0.menu\n");
    printf("1.Insert Data into Tree\n");

}

void main()
{


      node *root = NULL;
      int data;
      int command;
      callback comparer = compare;
      menu();
      while(1)
      {
      printf("\nEnter the command(0-1),-1 to quit:");
      scanf("%d",&command);
      if(command == -1)
        break;

       switch(command)
       {
       case 0:
           menu();
           break;

       case 1:
           printf("\n\nEnter the data to be saved into the binary tree:");
           scanf("%d",&data);
           root = insert_new_data(root,comparer,data);
           display(root);
           break;

       case 2:
            in_order(root);
            break;

       case 3:
            post_order(root);
            break;

       case 4:

            printf("\nsize of the tree is %d",size(root,0));
            break;

       case 5:
           printf("\nsize of the tree is %d",hight(root));
           break;

       }

  }
}


