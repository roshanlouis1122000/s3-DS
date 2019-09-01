#include <stdio.h>

void linear(int arr[],int size,int x);
void sort(int arr[],int size);
void binary(int arr[],int size,int x);
void recur(int arr[],int l,int u,int x);
void main()
{
  int n,x,c;
  printf("Enter the size of array :");
  scanf("%d",&n);
  int arr[n];
  printf("Enter the elements of the array :\n");
  for(int i =0;i<n;i++)
  {
    scanf("%d",&arr[i]);
  }
  printf("Enter the elemnt to be searched :");
  scanf("%d",&x);
  printf("1. linear search \n 2. Binary Search\n 3. Binary search(Recursion)\n Enter your choice :");
  scanf("%d",&c);
  switch(c)
  {
   case 1 : linear(arr,n,x);
            break;
   case 2 :sort(arr,n); 
           binary(arr,n,x);
            break;
   case 3 :sort(arr,n);
           recur(arr,0,n-1,x);
           break;
  } 

}

void linear(int arr[],int size,int x)
{ 
  int found =0,pos;
  for(int i=0;i<size;i++)
  {
    if(arr[i]==x)
     {
       found=1;
       pos=i;
       break;
     }
   }
  if (found==1)
  {
   printf("Element found at position %d \n",(pos+1));
  }
  else
 {
   printf("Element not found\n");
 } 
}
void sort(int arr[],int size)
{
  int temp;
  for(int i=0;i<size;i++)
   for(int j=0;j<size-1;j++)
    {
      if(arr[j]>arr[j+1])
       { 
         temp=arr[j];
         arr[j]=arr[j+1];
         arr[j+1]=temp;
       }
     }
    printf("the sorted array\n");
    for(int i=0;i<size;i++)
    printf("%d ",arr[i]);
}
void binary(int arr[],int size,int x)
{
  int lower= 0,upper=size-1,mid,pos,found=0;
  while(lower<=upper)
  { 
    mid =(lower+upper)/2;
    
    if(arr[mid]<x)
    {
       lower=mid+1;
    }
    if(arr[mid]>x)
    { 
      upper=mid-1;
    }
    if(arr[mid]==x)
    {
      found=1;
      pos=mid;
       break;
    }
}
    if(found==1)
    printf("Element found at position %d ",(pos+1));
    else
    {
     printf("Element not found");
     }
   
  }
void recur(int arr[],int l,int u,int x)
{ 
if(l<=u)
{
  int mid =(l+u)/2;
  if(arr[mid]<x)
   {
    l = mid+1;
    recur(arr,l,u,x);
   }
    if(arr[mid]>x)
    { u =mid-1;
     recur(arr,l,u,x);
    }
    if(arr[mid]==x)
    {
     printf("\nThe element is present in position %d ",(mid+1));
     return;
    }
 }
else
{ 
 printf("\nElement Not Found"); 
}
}

  




