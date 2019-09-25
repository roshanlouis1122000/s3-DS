#include <stdio.h>
#include <stdlib.h>
#define max 5
int ar[max];
int top =-1;
void push();
void pop();
void display();
void main()
{
  int c;
  while(1){
     printf("1. push \n2. pop \n3. Display \n4. Exit \nEnter your choice : ");
     scanf("%d",&c);
     switch(c)
    {
      case 1 : push();
               break;
      case 2 : pop();
               break;
      case 3 : display();
               break;
      case 4 : exit(0);
      default : printf("Invalid choice ");
    }
  }
}

void push()
{
  if(top<max-1)
  {
   int x;
   printf("Enter the data : ");
   scanf("%d",&x);
   ar[++top]=x;
  }
  else
   printf("Stack Overflow \n");
}
void pop()
{
 if(top<=-1)
{ 
  printf("Empty Stack\n");
}
 else 
 {
  printf("The poped element is %d \n",ar[top]);
  top--;
 }
}
void display()
{ 
if(top==-1)
{ 
  printf("Empty Stack \n");
}
else
{
 printf("The elements in the Stack : ");
 for(int i=top;i>=0;i--)
 {
  printf("%d ",ar[i]);
 }
  printf("\n");
}
}
