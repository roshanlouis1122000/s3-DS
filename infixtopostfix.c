#include <stdio.h>
#include <ctype.h>
#include<math.h>
#define size 20
char post[size];
char postfix[size];
char stack[size];
int s[size];
void conversion(char infix[]);
void evaluate(char postfix[]);
int top =-1;
void main()
{
 char infix[size];
  printf("Enter the infix expression ");
  scanf("%s",infix);
  conversion(infix);
  printf("The postfix : %s ",post);
  printf("\nEnter the postfix expression ");
 scanf("%s",postfix);
 evaluate(postfix);
 
 }
void push(char c)
{
 stack[++top]=c;
}
char pop()
{
 char c=stack[top];
 top--;
 return c;
}
void conversion(char infix[])
{
  char ch;
  int j=0;
  for(int i=0;infix[i]!='\0';i++)
 {
   ch=infix[i];
   if(isalpha(ch))
     {
       post[j]=infix[i];
       j++;
     }
   else 
    {
      
      if(ch=='('||ch=='^')
         {
          push(ch); 
         }
      else if(ch=='*'||ch=='/')
       {
         while(stack[top]=='*'||stack[top]=='/'||stack[top]=='^')
           {
             char s=pop();
             post[j]=s;
             j++;
           }
         push(ch);
       }
       else if(ch=='+'||ch=='-')
        {
          while(stack[top]=='+'||stack[top]=='*'||stack[top]=='/'||stack[top]=='^'||stack[top]=='-')
              {
                 char s = pop();
                 post[j]=s;
                 j++;
              }
           push(ch);
        }
       else if (ch==')')
        {
           while(stack[top]!='(')
              {
                 char s = pop();
                 post[j]=s;
                 j++;
              }
	   top--;
        }
      
    }
  

 }
   while(top>=0)
     {
      char s = pop();
      post[j]=s;
      j++;
    }
         
        
 post[j]='\0';
  
}
void evaluate(char postfix[])
{
  top=-1;
  char ch;
  int x,y,k,z;
  for(int i=0;postfix[i]!='\0';i++)
 {
    ch=postfix[i];
    if(isdigit(ch))
     {
       k = ch-48;
       s[++top]=k;
     }
   else
     {
       x=s[top];
       top--;
       y=s[top];
       top--;
       switch(ch)
	 {case '+': z= y+x;
	     break;
	 case '-' : z=y-x;
	   break;
	 case '*': z=y*x;
	   break;
	 case '/' :z=y/x;
	   break;
	 case '^': z=pow(y,x);
	   break;
	 }
      
       s[++top]=z;
     }
  }
  int f =s[top];
  printf("\nAfter postfix evaluation  : %d",f);
}
