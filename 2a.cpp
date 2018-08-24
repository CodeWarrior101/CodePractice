#include<iostream>
#define MAX_VALUE (1<<31)
using namespace std;

void printarraystring(string s[],int n)
{
	int i;
	for(i=0;i<n-1;i++)
		cout<<s[i]<<" ";
	cout<<s[i]<<endl;
}

void printarrayint(int s[],int n)
{
	int i;
	for(i=0;i<n-1;i++)
		cout<<s[i]<<" ";
	cout<<s[i]<<endl;
}

int search(string s[],string key,int n)
{
	if(!n) return 0;
	else
	{
		int i;
		for(i=0;i<n;i++)
		{
			if(key==s[i])
				return 1;
		}
		return 0;
	}
}

void max_score(string name[],int score[],int n)
{
	int i,j;
	string uniques[1000];
	int ts[1000];
	int ui = 0;
	int maxv = MAX_VALUE;
	for(i=0;i<n;i++)
	{
		string sea = name[i];
		int val = score[i];
		if(!search(uniques,sea,ui))
		{
			for(j=i+1;j<n;j++)
			{
				if(name[j]==sea)
				{
					val = val+score[j];
				}
			}
		uniques[ui] = sea;
		ts[ui] = val;
		ui++;
		}
	}
	//printarraystring(uniques,ui);
	//printarrayint(ts,ui);
	for(i=0;i<ui;i++)
	{
		if(ts[i] > maxv)
		{
			maxv = ts[i];
		}
	}
	// second iteraton to find the name of the first person whos score is atleast maxv
	ui = 0;
	int tmp_score[1000] = {0,};
	for(i=0;i<n;i++)
	{
		int same_name_value = 0;
		for(j=0;j<=i;j++)
		{
			if(name[i]==name[j])
				same_name_value+= score[j];
		}
		tmp_score[i] = same_name_value;
	}
	//printarraystring(name,n);
	//printarrayint(tmp_score,n);
	for(i=0;i<n;i++)
	{
		if((tmp_score[i]) >= maxv)
		{
			//cout<<tmp_score[i]<<" "<<maxv<<" i = "<<i<<endl;
			cout<<name[i]<<endl;
			return;
		}
	}
}

int main()
{
	string name[1000];
	int score[1000] = {0,};
	int n;
	int i;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>name[i];
		cin>>score[i];
	}
	max_score(name,score,n);
	return 0;
}