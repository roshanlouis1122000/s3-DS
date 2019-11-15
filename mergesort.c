#include <stdio.h>
#define max 10
int a[max];
void merge(int lb,int mid,int ub);
void mergesort(int lb,int ub);
void main()
{ 
   printf("Enter the elements of the array : ");
  for(int i=0;i<max;i++){
     scanf("%d",&a[i]);
   }
  mergesort(0,max-1);
 printf("The sorted array: ");
  for(int i=0;i<max;i++)
     printf("%d ",a[i]);
}
void mergesort(int lb,int ub)
{
 
 if(lb<ub)
{  
  int mid=(lb+ub)/2;
  mergesort(lb,mid);
  mergesort(mid+1,ub);
  merge(lb,mid,ub);
 }
}
void merge(int lb,int mid,int ub)
{
 int i=lb,j=mid+1,k=0;
 int temp[max];
 while(i<=mid&&j<=ub)
{
  if(a[i]<a[j])
   {
    temp[k]=a[i];
    i++;
    k++;
   }
  else
  {
   temp[k]=a[j];
   j++;
   k++;
   }
  }
while(i<=mid)
{
  temp[k]=a[i];
  k++;
  i++;
}
while(j<=ub)
{
  temp[k]=a[j];
k++;
 j++;
}


for(i=lb,k=0;i<=ub;i++,k++)
    a[i]=temp[k];
}

