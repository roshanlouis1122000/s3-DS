#include <stdio.h>
#include <stdlib.h>
struct node{
  int data;
  struct node * link;
  };
struct node* head=NULL;

void insert(int pos,int x)
{
  struct node * newnode = (struct node*)malloc(sizeof(struct node ));
  struct node * temp;
  if(newnode==NULL)
   {
     printf("No Space ");
     return;
   }
  newnode -> data = x;
  newnode -> link = NULL;
  if(head==NULL)
  {
    head=newnode;
  }
  else
  {
   temp = head;
   int i = 1;
   while(temp -> link != NULL)
  {
    temp=temp ->link;
     i++;
  }
  if(pos>i+1 || pos<1)
    printf("INVALID POSITION\n");
  else if(pos==1)
  {
    newnode -> link =head;
    head = newnode;
  }
  else if(pos>1)
  {
   temp =head;
   int j=1;
   while(j<pos-1)
   {
   temp=temp -> link;
   j++; 
   }
   newnode -> link = temp ->link;
   temp -> link =newnode;
    
   }
  }
}
void delete(int pos)
{
   if(head==NULL)
   {
     printf("Empty list\n");
     return;
   }
   else
   {
     struct node * temp;
     int i = 1;
     temp=head;
     while(temp -> link != NULL)
     {
    temp=temp ->link;
     i++;
     }
     if(pos>i || pos<1)
        printf("INVALID POSITION\n");
     else if(pos==1)
     {
      temp =head;
      head = head->link;
      free(temp);
     }
     else if(pos==i)
    {
      temp = head;
      struct node * temp1;
      while(temp->link!=NULL)
	{
	  temp1=temp;
	  temp=temp->link;
	}
      temp1->link=NULL;
      free(temp);
    }
     else if(pos<i)
       {
	 struct node * temp1;
	 temp=head;
	 for(int j=1;j<pos;j++)
	   {
	     temp1=temp;
	     temp=temp->link;
	   }
	 temp1->link=temp->link;
	 free(temp);
       }
   }
}
void traverse()
{
   struct node * temp=head;
    while(temp!=NULL)
    {
       printf("%d -->",temp->data);
       temp = temp->link;
    }    
    printf("\n");

}
void search(int x)
{
  struct node * temp;
  if(head==NULL)
    {
      printf("Empty List\n");
    }
  else
    {
      int pos=1,found=0;
      temp=head;
      while(temp->link!=NULL)
	{
	  if(temp->data==x)
	    {
	      found=1;
	      break;
	    }
	  else
	    {
	      temp=temp->link;
	      pos++;
	    }
	}
      if(found==1)
	{
	  printf("Element found at position %d\n ",pos);
	}
      else
	{
	  printf("Element Not found \n");
	}
    }
  
  
}



void main()
{
  
  do{
    printf("1. Insert \n2. Delete \n3. Search \n4. Traverse\n5. Exit  \nEnter your choice :");
    int c;
    scanf("%d",&c);
    switch(c)
    {
      case 1 : printf("Enter the data : "); 
               int d,pos;
               scanf("%d",&d);
               printf("Enter the position :");
               scanf("%d",&pos);
               insert(pos,d);
               break;
    case 2 : printf("Enter the position :");
             int k;
             scanf("%d",&k);
	     delete(k);
	     break;
    case 3 :printf("Enter the data to be searched :");
            int x;
            scanf("%d",&x);
	    search(x);
	    break;
    case 4 :traverse();
            break;
    case 5 : return;	    
     
     }
   }while(1);
}


