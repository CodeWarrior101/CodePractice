// https://www.spoj.com/problems/ABA12C/
#include<iostream>
using namespace std;
int minp = ~(1<<31);
int dp[1000] = {0,};

int min_price(int kg[100],int kgp[100],int nkg,int maxbags,int weight,int price)
{
    int i,j;
    if(weight==0)
    {
        if(minp > price)
        {
            minp = price;
        }
        return 0;
    }
    else if(weight < 0)
    {
        return 0;
    }
    if(dp[weight])
    {
        if(minp > dp[weight])
        {
            minp = dp[weight];
        }
        return dp[weight];
    }
    if(maxbags<=0)
    {
        return 0;
    }
    for(i= 0;i<nkg;i++)
    {
        if((weight-kg[i]) >=0)
            dp[weight-kg[i]] = min_price(kg,kgp,nkg,maxbags-1,weight-kg[i],price+kgp[i]);
    }
}

int main()
{
    int n,k;
    int price[100];
    int kg[100];
    int kgp[100];
    int i,j;
    int minkgp = ~(1<<31);
    int minkg = 0;
    int tc,ti;
    cin>>tc;
    for(ti=0;ti<tc;ti++)
    {
        cin>>n>>k;
        j = 0;
        for(i=0;i<k;i++)
        {
            cin>>price[i];
            if((price[i]!=-1))
            {
                kg[j] = i+1;
                kgp[j] = price[i];
                j++;
            }
        }
        int dpi;
        for(dpi = 0;dpi<k;dpi++)
        {
            dp[dpi] = 0;
        }
        min_price(kg,kgp,j,n,k,0);
        if(minp == ~(1<<31))
            cout<<-1<<endl;
        else
            cout<<minp<<endl;
    }
    return 0;
}
