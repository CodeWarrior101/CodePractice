#include<iostream>
#include<string>
#include<algorithm>

#define TABLE_SIZE 100000

using namespace std;

int hash_fun(string name)
{
	int len = name.size();
	long long int val = 0;
	int i = 0;
	while(name[i])
	{
		val += (len-i)*((int)name[i]-96);
		i++;
	}
	//cout<<val<<endl;
	return val%TABLE_SIZE;
}

string insert(string name,int scnt[])
{
	int index = hash_fun(name);
	if(index<0)
	{
		return "value is negative";
	}
	if(!scnt[index])
	{
		scnt[index]++;
		return "OK";
	}
	else
	{
		return name.append(to_string(scnt[index]++));
	}
}

int main()
{
	int str_cnt[TABLE_SIZE] = {0,};
	int n;
	string name;
	int i,j;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>name;
		transform(name.begin(), name.end(), name.begin(), ::tolower);
		cout<<insert(name,str_cnt)<<endl;
	}
	return 0;
}