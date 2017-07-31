#include<stdio.h>

typedef void (*callback)(int ,int );
void add(int a,int b)
{
    printf("a+b=%d",(a+b));
}

void sub(int a,int b)
{
  printf("a-b=%d",(a-b));
}

void main()
{
  int a=10,b=5;
  callback f;
  f=add;
  //printf("%u",f);
  f(a,b);
  f=sub;
  f(a,b);
}
