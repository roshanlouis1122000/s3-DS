#include <stdio.h>
#include <stdlib.h>
#define max 5
int front =-1,rear=-1;
int ar[max];
void enqueue();
void dequeue();
void display();
void main()
{
  int c;
  while(1){
     printf("\n1. Enqueue \n2. Dequeue \n3. Display \n4. Exit \nEnter your choice : ");
     scanf("%d",&c);
     switch(c)
    {
      case 1 : enqueue();
               break;
      case 2 : dequeue();
               break;
      case 3 : display();
               break;
      case 4 : exit(0);
      default : printf("Invalid choice \n");
    }
  }
}
void enqueue()
{
  if(rear == (max-1))
    printf("Queue Full ");
  else 
  {  int x;
   printf("Enter the data ");
   scanf("%d",&x);
  if(rear==-1)
  {
   front++;
   ar[++rear]=x;
   }
   else
   {
    ar[++rear]=x;
   }
  }
}
void dequeue()
{
 if(front==-1)
   printf("Queue Empty");
 else if(front==rear)
 {
  printf("The element deleted is %d ",ar[front]);
  front=-1;
  rear=-1;
 }
 else
 {
  printf("The element deleted is %d ",ar[front]);
  front++;
 }
}
void display()
{
 if(front ==-1)
{ 
 printf("Empty Queue ");
}
 else
{
 for(int i=front;i<=rear;i++)
{
 printf("%d ",ar[i]);
}
}
}
