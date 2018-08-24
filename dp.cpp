// https://www.spoj.com/problems/COINS/
#include<iostream>

using namespace std;

int max(int a,int b)
{
    return (a>b)?a:b;
}

int val  = 0;
int val1 = 0;

int dp[100] = {0,};

int cal_coin(int n,int tval)
{
    if(n<=1)
    {
        cout<<"cnt = "<<cnt<<endl;
        return cnt;
    }
     int val = cal_coin(n/2 ,(++tval)*(n/2));
     //val = max(val,cal_coin(n/3 ,++cnt));
     //val = max(val,cal_coin(n/4 ,++cnt));
     cout<<"val = "<<val<<endl;
     return val;
}

int main()
{
    int n;
    cin>>n;
    cout<<max(n,cal_coin(n,1))<<endl;
    return 0;
}
