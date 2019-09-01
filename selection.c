#include <stdio.h>
void selsort(int arr[],int size);
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
  selsort(arr,n);
  printf("The sorted array\n");
  for(int i=0;i<n;i++)
  printf("%d ",arr[i]);
  printf("\n");
}
void selsort(int arr[],int size)
{
  int small,pos,temp;
  for(int i=0;i<size;i++)
  {
    small = arr[i];
    pos = i;
    for(int j=i+1;j<size;j++)
     {
       if(small>arr[j])
       {
        small=arr[j];
        pos=j;
       }
     }
     temp=arr[i];
     arr[i]=arr[pos];
     arr[pos]=temp;
  }
}
