// https://www.geeksforgeeks.org/closest-product-pair-array/
#include<bits/stdc++.h>
#include<iostream>
//#include<cstdlib>
//#include<cstdio>
#include<cmath>

using namespace std;

int print_closet_pair(int *a,int n,int x)
{
  int i;
  int l,r;
  int res_l,res_r;
  int diff = INT_MAX;
  l = 0;
  r = n-1;
  while(l<r)
  {
    if(abs(a[l]*a[r]-x)<diff)
    {
      diff = abs(a[l]*a[r]-x);
      res_l = l;
      res_r = r;
    }
    if(a[l]*a[r]>x)
    {
      r--;
    }
    else
      l++;
  }
  cout<<"closet pair is:("<<a[res_l]<<", "<<a[res_r]<<")"<<endl;
}

int main()
{
  int a[] ={2,3,5,9};
  int x = 8;
//  cout<<(~(1<<31))<<endl;
  int size = sizeof(a)/sizeof(a[0]);
  print_closet_pair(a,size,x);
  return 0;
}
