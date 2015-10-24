#include<iostream>
using namespace std;
#include<stdio.h>
int partition(int Arr[],int st,int end,int idx)
{
  int pivot = Arr[idx];
  swap(Arr[st],Arr[idx]);
  int ind=st;
  for(int i=st+1;i<=end;i++)
  {
    if(Arr[i]<=pivot)
      swap(Arr[++ind],Arr[i]);
  }
  swap(Arr[st],Arr[ind]);
  return ind;
}
int findKth(int Arr[],int st,int end,int k)
{
  if(k>end || k<st)
    return -1;
  
  if(st>end)
    return -1;
  
  while(st<=end)
  {
    int p = partition(Arr,st,end,k);
    
    if(p==k)
      return Arr[p];
    if(p>k)
      end = p-1;
    else
    {
      st = p+1;
    }
  }
  if(st == k)
    return Arr[k];
  return -1;

}
void qsort(int Arr[],int st,int end)
{
  if(st>=end)
    return ;
  int p =partition(Arr,st,end,st);
  qsort(Arr,st,p-1);
  qsort(Arr,p+1,end);
}
int main()
{
  int A[]={1,2,1,1,2,6};
  for(int i=0;i<6;i++)
    printf("%d\n",findKth(A,0,5,i));
  qsort(A,0,5);
  for(int i=0;i<6;i++)
    printf("%d  ",A[i]);
  printf("\n");
}
