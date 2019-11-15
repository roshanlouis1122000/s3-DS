#include <stdio.h>
//#define size 6
#define max 10
 int size;
int visited[max];
int stack[max];
int queue[max];
int top=-1,front=-1,rear=-1;
int ar[max][max];
void dfs(int i);
void bfs(int i);
void main()
{
  int n;
  printf("Enter the size of the array : ");
  scanf("%d",&size);
  printf("Enter the Adjacency Matrix:\n");
  for(int i=0;i<size;i++)
    {
      for(int j=0;j<size;j++)
	{
           scanf("%d",&ar[i][j]);
	}
    }
  printf("Enter the source vertex : ");
  scanf("%d",&n);
  for(int i=0;i<size;i++)
     visited[i]=0;
   dfs(n);
for(int i=0;i<size;i++)
     visited[i]=0;
 bfs(n);
  
}
void dfs(int i)
{
  
  stack[++top]=i;
  int x;
  printf("The DFS : ");
  while(top>=0)
    {
      x=stack[top--];
     
      if(visited[x]==0)
	{
	  printf("%d ",x);
	  visited[x]=1;
	
      for(int j=0;j<size;j++)
	{
	  if(ar[x][j]==1)
	    stack[++top]=j;
	}
	}
    }
}
void bfs(int i)
{
  printf("THE BFS : %d ",i);
   visited[i]=1;
  queue[++rear]=i;
  front++;
  int x;
  while(front<size)
    {

      x=queue[front];
       front++;
      for(int j=0;j<size;j++)
	{
	  if(ar[x][j]==1)
	    {
	      if (visited[j]==0)
                  {
		    printf("%d ",j);
	            queue[++rear]=j;
	             visited[j]=1;
                   }
	    }
	}
    }  
}
