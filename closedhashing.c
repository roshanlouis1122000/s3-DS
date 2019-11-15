#include<stdio.h>
#include<stdlib.h>
#define size 10

int ar[size];
void search();
void insert();
void display();
void main()
{
for(int i=0;i<size;i++)
    ar[i]=-1;
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
void insert()
{
int x,pos;
 printf("Enter the value to be inserted : ");
  scanf("%d",&x);
  pos=x%size;
  if(ar[pos]==-1)
  {
   ar[pos]=x;
  }
  else
  {
    for(int i=1;(pos+i)<size;i++)
     {
       if(ar[(pos+i)%size]==-1)
         { ar[(pos+i)%size]=x;
            break;
         }

     }
   }
}
void search()
{ 
  int x,pos,flag=0,c;
  printf("Enter the element to be searched :");
  scanf("%d",&x);
  pos=x%size;
  for(int i=0;(pos+i)<size;i++)
  {
    c=(pos+i)%size;
    if(ar[c]==x)
   {
     flag=1;
     break;
   }
  }
    if(flag==1)
       printf("Element found at index %d \n",c);
    else
      printf("Element Not found \n ");
 
  
}
void display()
{
 for(int i=0;i<size;i++)
  {
    if(ar[i]!=-1)
      printf("At index %d = %d \n",i,ar[i]);
  }
}

