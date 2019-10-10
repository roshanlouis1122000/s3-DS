#include <stdio.h>
#include<stdlib.h>
#define max 5
int front=-1,rear=-1;
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
 if(front==((rear+1)%max))
   printf("Queue FULL ");
 else
{
  int x;
   printf("Enter the data ");
   scanf("%d",&x); 
if (front ==-1)
{
 front =rear=0;
 ar[rear]=x;
}
else
 {
 rear=(rear+1)%max;
 ar[rear]=x;
 }
}
}
void dequeue()
{
 if(front==-1)
   printf("Empty Queue ");
 else
 {
  printf("The deleted element is %d ",ar[front]);
  if(front==rear)
     front=rear=-1;
  else
    front =(front+1)%max;
 } 
}
void display()
{
 if(front==-1)
  printf("Empty Queue ");
 else
{
 int i =front;
 while(i!=rear)
{
 printf("%d ",ar[i]);
 i=(i+1)%max;
}
printf("%d ",ar[rear]);
}
}
