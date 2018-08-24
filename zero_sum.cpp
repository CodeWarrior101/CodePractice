// http://www.techiedelight.com/check-subarray-with-0-sum-exists-not/
#include<iostream>
using namespace std;

void printArr(int a[],int l,int h)
{
    int i;
    cout<<"{";
    for(i=l;i<h;i++)
    {
        cout<<a[i]<<",";
    }
    cout<<a[h]<<"}"<<endl;
}

void zeroSum(int a[],int n)
{
   int i,j;
   int sum;
   for(i=0;i<n;i++)
   {
       sum = a[i];
       for(j=i+1;j<n;j++)
       {
           sum = sum + a[j];
           if(!sum)
               printArr(a,i,j);
       }
   }
}

int main()
{
    int a[] = {3,4,-7,3,1,3,1,-4,-2,-2};
    int n = sizeof(a)/sizeof(a[0]);
    zeroSum(a,n);
    return 0;
}
