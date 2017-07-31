#include<stdio.h>

typedef int (*callback)(int ,int );
int add(int a,int b)
{
   return a+b;
}

int sub(int a,int b)
{
 return (a-b);
}

void main()
{
  int a=10,b=5;
  callback f;
  f=add;
  printf("a+b=%d",f(a,b));
  //printf("%u",f);
  f(a,b);
  f=sub;
  printf("a-b=%d",f(a,b));
  //printf("%u",f);
  f(a,b);
}
