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
void add()
{
  struct node* pp=phead,*qq=qhead;
 struct node * rptr  =(struct node *)malloc(sizeof(struct node));

 while(pp!=NULL&&qq!=NULL)
{
 if(pp->exp>qq->exp)
{
 struct node * newnode=(struct node *)malloc(sizeof(struct node));
 newnode->coef=pp->coef;
 newnode->exp=pp->exp;
 newnode->link=NULL;
if(r==NULL){
	r=newnode;
	rptr=r;
      }
      else{
	rptr->link=newnode;
	rptr=newnode;
      }
 pp=pp->link;
}
if(qq->exp>pp->exp)
{
 struct node * newnode=(struct node *)malloc(sizeof(struct node));
 newnode->coef=qq->coef;
 newnode->exp=qq->exp;
 newnode->link=NULL;
if(r==NULL){
	r=newnode;
	rptr=r;
      }
      else{
	rptr->link=newnode;
	rptr=newnode;
      }

 qq=qq->link;
}
if(pp->exp==qq->exp)
 {
 struct node * newnode=(struct node *)malloc(sizeof(struct node));
 newnode->coef=pp->coef+qq->coef;
 newnode->exp=pp->exp;
 newnode->link=NULL;
if(r==NULL){
	r=newnode;
	rptr=r;
      }
      else{

 rptr->link=newnode;
 rptr=newnode;
      }
 pp=pp->link;
 qq=qq->link;
 }
}
while(pp!=NULL)
{
struct node * newnode=(struct node *)malloc(sizeof(struct node));
 newnode->coef=pp->coef;
 newnode->exp=pp->exp;
 newnode->link=NULL;
if(r==NULL){
	r=newnode;
	rptr=r;
      }
      else{

 rptr->link=newnode;
 rptr=newnode;
      }
 pp=pp->link;
 
}
while(qq!=NULL)
{
 struct node * newnode=(struct node *)malloc(sizeof(struct node));
 newnode->coef=qq->coef;
 newnode->exp=qq->exp;
 newnode->link=NULL;
if(r==NULL){
	r=newnode;
	rptr=r;
      }
      else{

 rptr->link=newnode;
 rptr=newnode;
 }
 qq=qq->link;
 }
printf("\nThe sum of the polynomial : ");
struct node * t2=r;
while (t2!=NULL){
     printf("%dx^%d + ",t2->coef,t2->exp);
     t2=t2->link;
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
  add();
  
}
