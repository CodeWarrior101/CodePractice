#include<iostream>
#define FOR(i,n) for(i=0;i<n;i++)

using namespace std;
int main()
{
  char arr[] = {'a','b','c'};
  int i,j,k;
  FOR(i,3)
  {
    FOR(j,3)
    {
      if(j!=i)
      {
        FOR(k,3)
        {
          if(k!=j && k!=i)
          cout<<arr[i]<<" "<<arr[j]<<" "<<arr[k]<<endl;
        }
      }
    }
  }
  return 0;
}
