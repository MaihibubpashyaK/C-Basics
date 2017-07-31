#include<stdio.h>
#include"Array_Sorting.h"
int a[20];

int main()
{
    int *p;


    int i,l;
    printf("Enter the array to be sorted\n");
    for(i=0;i<10;i++)
        scanf("%d",&a[i]);
    printf("Enterd array:\n\n");
    for(i=0;i<10;i++)
       printf("%d\t",a[i]);

     p = increment_order(a);

   //dec = decrement_order(a);
   printf("Sorted array in increment order:\n\n");
       for(l=1;l<11;l++)
       {
       printf("%d\t",*(p+l));
       }


 // printf("Sorted array in decrement order:\n\n");
      // for(l=0;l<10;l++)
        // {
           // printf("%d\t",*(dec+l));
         //}

return 0;
}
