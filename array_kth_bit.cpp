// https://www.geeksforgeeks.org/queries-for-number-of-array-elements-in-a-range-with-kth-bit-set/
#include<iostream>
#include<malloc.h>

using namespace std;

int bit_print(int *a,int n,int l,int r,int k)
{
  int cnt = 0;
  int i,j;
  for(i=l-1;i<r;i++)
  {
    if(a[i]&(1<<(k-1)))
      cnt++;
  }
  return cnt;
}

int main()
{
  int n;
  int i,j;
  int *a = NULL;
  cout<<"enter the numner of elements in array:";
  int l,r,k;
  cin>>n;
   a = (int *)malloc(sizeof(int)*n);
   if(!a)
      {
        printf("memory is not allocated for array\n");
        return 0;
      }
    cout<<"enter "<<n<<" elements"<<endl;
    for(i=0;i<n;i++)
    {
      cin>>a[i];
    }
    cout<<"enter l,r,k"<<endl;
    cin>>l>>r>>k;
   cout<<bit_print(a,n,l,r,k)<<endl;
   if(a)
   {
    free(a);
    a = NULL;
  }
  return 0;
}
