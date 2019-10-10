#include <stdio.h>
#include <stdlib.h>
struct node {
 int data;
 struct node * link;
};
struct node *top=NULL;
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
  struct node * new=(struct node*)malloc(sizeof(struct node));
 if(new ==NULL)
    printf("NO SPACE ");
  printf("Enter the data : ");
  int x;
  scanf("%d",&x);
  new ->data=x;
  if(top==NULL)
{
  new->link=NULL;
}
else
{
 new->link=top;
}
top=new;
}
void pop()
{
struct node* temp;
 if(top==NULL)
   printf("Empty Stack\n");
 else
{
 temp=top;
printf("The poped element is %d \n",temp->data);
top=top->link;
free(temp);
 }
}
void display()
{
 struct node* temp=top;
 if(top==NULL)
   printf("Empty Stack\n");
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
