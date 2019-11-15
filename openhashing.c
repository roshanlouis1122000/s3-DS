#include<stdio.h>
#include<stdlib.h>
#define size 10
struct node{
 int data;
 struct node* link;
};
struct node* ar[size];
void insert()
{ 
struct node * newnode=(struct node*)malloc(sizeof(struct node));
struct node * temp;
 int x,pos;
 printf("Enter the value to be inserted : ");
  scanf("%d",&x);
newnode->data=x;
newnode->link=NULL;
pos=x%size;
if(ar[pos]==NULL)
{ 
  ar[pos]=newnode;
}
else
{
  temp=ar[pos];
  while(temp->link!=NULL)
     temp=temp->link;
  temp->link=newnode;
}
}
void search()
{
 struct node * temp;
 int x,pos,flag=0;
  
  printf("Enter the element to be searched :");
  scanf("%d",&x);
  pos=x%size;
  if(ar[pos]==NULL)
    printf("Element Not found ");
  else
 {
  temp=ar[pos];
  while(temp!=NULL)
   {
    if(temp->data==x)
     {
      flag=1;
      break; 
     }
    temp=temp->link;  
   }
  if(flag==1)
    printf("Element Found at Index %d \n",pos);
  else
    printf("Element Not found \n");
 }
}
void display()
{
struct node * temp;
  for(int i=0;i<size;i++)
 {
   if(ar[i]!=NULL)
    {
     temp=ar[i];
     printf("At index %d : ",i);
     while(temp!=NULL)
      {
         printf("%d ->",temp->data);
         temp=temp->link;
      }
      printf("\n");
      
    }
 }
}
void main()
{
for(int i=0;i<size;i++)
    ar[i]=NULL;
  int c;
  while(1){
     printf("1. insert \n2. Search \n3.Display \n 4.Exit \nEnter your choice : ");
     scanf("%d",&c);
     switch(c)
    {
      case 1 : insert();
               break;
      case 2 : search();
               break;
      case 3 : display();
               break;
      case 4 : exit(0);
      default : printf("Invalid choice \n");
    }
  }
}
