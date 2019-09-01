#include <stdio.h>
void insertsort(int arr[],int n);
void main()
{
  int n;
  printf("Enter the size of the array : ");
  scanf("%d",&n);
  int arr[n];
  printf("Enter the elements :\n");
  for(int i=0;i<n;i++)
 {
   scanf("%d",&arr[i]);
 }
 insertsort(arr,n);
 printf("The sorted array\n");
 for(int i=0;i<n;i++)
  printf("%d ",arr[i]);
 printf("\n");
 
}
void insertsort(int arr[],int n)
{ 
 int key,j;
 for(int i=1;i<n;i++)
{
 key=arr[i];
 j= i-1;
 while((j>=0)&&(arr[j]>key))
 {
  arr[j+1]=arr[j];
  j--;
 }
 arr[j+1]=key;
 
 }
}

