#include <stdio.h>
#include <stdlib.h>
#define max 10
int ar[max];
int top1 =-1,top2 =max;

void push1()
{
 if(top1<top2)
  {
   int x;
   printf("Enter the data : ");
   scanf("%d",&x);
   ar[++top1]=x;
   printf("\n");
  }
  else
{ 
 printf("Stack Overflow\n");
}
}
void push2()
{
 if(top1<top2)
  {
   int x;
   printf("Enter the data : ");
   scanf("%d",&x);
   ar[--top2]=x;
   printf("\n");
  }
  else
{ 
 printf("Stack Overflow\n");
}
}
void pop1()
{
 if(top1<=-1)
  printf("Empty Stack\n");
 else
 {
  printf("The poped element is %d \n",ar[top1]);
  top1--;
  printf("\n");
 }
}
void pop2()
{
 if(top2>=max)
  printf("Empty Stack\n");
 else
 {
  printf("The poped element is %d \n",ar[top2]);
  top2++;
  printf("\n");
 }
}
void display1()
{ 
if(top1==-1)
{ 
  printf("Empty Stack \n");
}
else
{
 printf("The elements in the Stack : ");
 for(int i=top1;i>=0;i--)
 {
  printf("%d ",ar[i]);
 }
  printf("\n");
}
}
void display2()
{ 
if(top2==max)
{ 
  printf("Empty Stack \n");
}
else
{
 printf("The elements in the Stack : ");
 for(int i=top2;i<max;i++)
 {
  printf("%d ",ar[i]);
 }
  printf("\n");
}
}
void main()
{
  int c;
  while(1){
     printf("1. push into stack 1\n2. push into stack 2\n3. pop into stack1\n4.pop into stack2\n5.Display stack1 \n6.Display stack2  \n7.Exit\n");
     printf("Enter your choice : "); 
     scanf("%d",&c);
     switch(c)
    {
      case 1 : push1();
               break;
      case 2 : push2();
               break;
      case 3 : pop1();
               break;
      case 4 : pop2();
               break;
      case 5 : display1();
               break;
      case 6 : display2();
               break;
      case 7 : exit(0);
      default : printf("Invalid choice ");
    }
  }
}

