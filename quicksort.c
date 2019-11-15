#include <stdio.h>
#define max 5
int a[max];
void quicksort(int lb,int ub);
int partition(int lb,int ub);
void main()
{ 
  
  printf("Enter the elements of the array : ");
  for(int i=0;i<max;i++){
     scanf("%d",&a[i]);
   }
  quicksort(0,max-1);
 printf("The sorted array: ");
  for(int i=0;i<max;i++)
     printf("%d ",a[i]);
}
void quicksort(int lb,int ub)
{ 
  if(lb<ub)
{
 int p=partition(lb,ub);
 quicksort(lb,p-1);
 quicksort(p+1,ub);
}
}
int partition(int lb,int ub)
{ 
  int pivot=a[lb];
  int left=lb,right=ub;
  while(left<right)
  {
   while((a[left]<=pivot)&&(left<right))
       left++;
   while((a[right]>pivot)&&(left<right))
       right--;
   if(left<right)
   {
     int temp=a[left];
     a[left]=a[right];
     a[right]=temp;
   }
  }
 
   right--;
   int temp=a[lb];
   a[lb]=a[right];
   a[right]=temp;
 return right; 
}
