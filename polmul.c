
#include <stdio.h>
#include <stdlib.h>
struct node{
   int coef,exp;
   struct node* link;
};
struct node * phead=NULL,*qhead=NULL,*r=NULL;

struct node* insert(int n,struct node *x)
{
  int c,i=1,k=n;
  struct node* p;
  while(n>=0)
  { 
    printf("Enter the coefficient of %d : ",n);
    scanf("%d",&c);
    if(c!=0)
    {
      struct node * new=(struct node *)malloc(sizeof(struct node));
    if (new==NULL)
      {
      printf("Insufficient Memory");
      }
    else
      { new->coef=c;
      new->exp=n;
      new ->link=NULL;
     if(x==NULL)
     {
       x=new;
       p=x;
     }
     else
     {
       p->link=new;
       p=new;
     }
    }
    
    }
    n--;
  }
  struct node * t=x;
  while(t!=NULL)
  {
   printf("%dx^%d + ",t->coef,t->exp);
   t=t->link;
  }
  return x;
}
void multiply()
{
  struct node*pptr=phead,*qptr=qhead,*rptr,*s=NULL;
   struct node * sptr=(struct node *)malloc(sizeof(struct node));
  while(pptr!=NULL)
    {
      qptr=qhead;
      while(qptr!=NULL)
	{
	   struct node * new=(struct node *)malloc(sizeof(struct node));
	   new->coef=(pptr->coef)*(qptr->coef);
	   new->exp=(pptr->exp)+(qptr->exp);
	   new->link=NULL;
	   if(s==NULL)
	     {
	       s=new;
	       sptr=s;
	     }
	   else
	     {
	       	sptr->link=new;
		sptr=new;
	     }
	   qptr=qptr->link;
	}
      pptr=pptr->link;
    }
  struct node* t=s;
  int j = s->exp;
  j--;
   struct node * newnode=(struct node *)malloc(sizeof(struct node));
   newnode->exp=s->exp;
   newnode->coef=s->coef;
   newnode->link=NULL;
   r=newnode;
   rptr=r;
  
  while(j>-1)
    {
      int sum=0;
      struct node * new=(struct node *)malloc(sizeof(struct node));
      t=s->link;
      while(t!=NULL)
	{
	  if(t->exp==j)
	    {
	      sum=sum+t->coef;
	    }
	  t=t->link;
	}
      new->exp=j;
      new->coef=sum;
      new->link=NULL;
      rptr->link=new;
      rptr=new;
      j--;
    }
  printf("\nAfter  polynomial multiplication: ");
struct node * t2=r;
while (t2!=NULL){
  if(t2->coef==0)
    {
      t2=t2->link;
    }
  else
    { printf("%dx^%d + ",t2->coef,t2->exp);
     t2=t2->link;
    }
  }
  
}



void main()
{ 
  int n,m,c;
  printf("Enter the degree of first polynomial ");
  scanf("%d",&n);
  phead=insert(n,phead);
  printf("\nEnter the degree of second polynomial ");
  scanf("%d",&m);
  qhead=insert(m,qhead);
  multiply();
  
}
