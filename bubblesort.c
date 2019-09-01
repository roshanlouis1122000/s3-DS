#include <stdio.h>

void sort(int arr[],int size);

void sort(int arr[],int size)
{
  int temp;
  for(int i=0;i<size;i++)
   for(int j=0;j<size-1-i;j++)
    {
      if(arr[j]>arr[j+1])
       { 
         temp=arr[j];
         arr[j]=arr[j+1];
         arr[j+1]=temp;
       }
     }
    }

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
 sort(arr,n);
 printf("The sorted array\n");
 for(int i=0;i<n;i++)
  printf("%d ",arr[i]);
 printf("\n");
 
}
