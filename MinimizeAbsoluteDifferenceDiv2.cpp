//http://community.topcoder.com/stat?c=problem_statement&pm=14884
#include<iostream>
using namespace std;

void printarr(char a[],int n)
{
  int i,j;
  cout<<"{ ";
  for(i=0;i<n-1;i++)
    cout<<a[i]<<",";
  cout<<a[i]<<" }"<<endl;
}

void cal(char a[],int n,int index)
{
  int i,j;
  if(index>=n)
  {
    printarr(a,n);
    return;
  }
  for(i = index; i<n;i++)
  {
    //for(j= i; j<n;j++)
    //{
      swap(a[i],a[index]);
      //cout<<"i = "<<i<<" j = "<<j<<endl;
      //printarr(a,n);
      cal(a,n,index+1);
      swap(a[i],a[index]);
    //}
  }
}

int main()
{
  char a[] = {'a','b','c'};
  int s = sizeof(a)/sizeof(a[0]);
  int i,j;
  cal(a,s,0);
  return 0;
}
