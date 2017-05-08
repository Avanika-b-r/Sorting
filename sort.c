#include<stdio.h>

int arr[100];

void merge(int arr[],int low, int mid, int high);

void divide(int arr[],int l,int h)
{ 
  if(l<h)
  {
    int mid=(l+h)/2;
    divide(arr,l,mid);
    divide(arr,mid+1,h);
    merge(arr,l,mid,h);
  }
}

void merge(int arr[], int low, int mid, int high)
{
  int a[50],b[50],i,j,k;
  for(i=low,j=0;i<=mid;i++,j++)
    a[j]=arr[i];
  a[j]=-9999;
  for(i=mid+1,j=0;i<=high;i++,j++)
    b[j]=arr[i];
  b[j]=-9999;

  i=0,j=0,k=0;
  for(i=low;i<=high;i++)
  {
    if(a[j]>b[k])
      arr[i]=a[j++];
    else
      arr[i]=b[k++];
  }
}

void main()
{
  int n,arr[100];
  printf("Enter the number of elements:\n");
  scanf("%d",&n);
  printf("Enter the elements:\n");
  for(int i=0;i<n;i++)
    scanf("%d",&arr[i]);

  divide(arr,0,n-1);

  printf("Sorted Array:\n");
  for(int i=0;i<n;i++)
    printf("%d ",arr[i]);
  printf("\n");
}
 
      
