// this code calculates no of trailing zeros in a int number https://codeforces.com/contest/2/problem/B
#include<iostream>
#include<cmath>
using namespace std;

int cal_trailing_zeros(int n)
{
    int d,r;
    int i;
    int num = n;
    int cnt = 0;
    int nod = 0; // no if digits
    while(1)
    {
        d = num/10;
        r = num%10;
        nod++;
        num = d;

        if(!d)
            break;
    }
    i = nod;
    for(i = nod-1;i>0;i--)
    {
       d = n/(int)pow(10,i);
       r = n%(int)pow(10,i);
       if(!r)
           return i;
    }
    return 0;
}
int main()
{
    int n;
    cin>>n;
    cout<<cal_trailing_zeros(n)<<endl;
    return 0;
}
