//https://codeforces.com/contest/1/problem/A
#include<iostream>

using namespace std;

int main()
{
	int m,n,a;
	int i,j;
	cin>>m>>n>>a;
	unsigned long long int cnth = 0;
	unsigned long long int cntv = 0;
	int rh = 0;
	int dh = 0;
	int rv = 0;
	int dv = 0;
	
	rh = m%a;
	dh = m/a;
	if(!rh)
	{
		cnth = dh;
	}
	else
	{
		cnth = dh+1;
	}
	
	rv = n%a;
	dv = n/a;
	if(!rv)
	{
		cntv = dv;
	}
	else
	{
		cntv = dv+1;
	}
	cout<<cnth*cntv<<endl;
	return 0;
}