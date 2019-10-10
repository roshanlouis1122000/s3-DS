#include <stdio.h>
#include <stdlib.h>
struct node {
 int data;
 struct node * link;
};
struct node *front=NULL,*rear =NULL;
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
 struct node * new=(struct node*)malloc(sizeof(struct node));
 if(new ==NULL)
    printf("NO SPACE ");
  printf("Enter the data : ");
  int x;
  scanf("%d",&x);
  new ->data=x;
  new->link=NULL;
  if(front==NULL)
{
  front=new;
  rear=new;
}
else
{
 rear->link=new;
 rear=new;
}
}
void dequeue()
{
struct node* temp;
 if(front==NULL)
   printf("Empty Queue\n");
 else
{
 temp=front;
printf("The deleted element is %d \n",temp->data);
front=front->link;
free(temp);
 }
}
void display()
{
 struct node* temp=front;
 if(front==NULL)
   printf("Empty Queue\n");
 else
{
 while(temp!=NULL)
  {
    printf("%d ",temp->data);
    temp=temp->link;
  }
  printf("\n");
}
}

