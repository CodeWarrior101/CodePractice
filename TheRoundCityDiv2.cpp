//http://community.topcoder.com/stat?c=problem_statement&pm=14898
#include<iostream>
#define FOR(i,n) for(i=0;i<n;i++)
#define FORV(i,val,n) for(i=val;i<n;i++)


using namespace std;

void cal(int r)
{
	int i,j;
	int cnt = 0;
	int sr = r*r;
	FORV(i,-r,r+1)
	{
		int si = i*i;
		FORV(j,-r,r+1)
		{
			int sj = j*j;
			if(((si+sj)<=sr)&& (i||j))
				cnt++;	
		}
	}
	cout<<cnt<<endl;
}

int main()
{

	int r;
	int i,j;
	cin>>r;
	cal(r);
	return 0;
}
