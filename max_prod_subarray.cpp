// https://www.geeksforgeeks.org/maximum-product-subarray-set-3/
#include<iostream>

using namespace std;

void max_prod_subarray(int *a,int n)
{
  int i,j;
  int max_prod = (1<<31);
  int prod = 1;
  for(i=0;i<n;i++)
  {
    prod *= a[i];
    if(prod > max_prod)
        max_prod = prod;
    if(!prod)
        prod = 1;
    //else
        //prod = 1;
  }
  cout<<"max produt of subarray is: "<<max_prod<<endl;
  return;
}

int main()
{
  int a[] = {-2, -3, 0, -2, -40};
  int n = sizeof(a)/sizeof(a[0]);
  max_prod_subarray(a,n);
  return 0;
}
