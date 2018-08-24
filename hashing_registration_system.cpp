//https://codeforces.com/problemset/problem/4/C
#include<iostream>
#include<string>
#include<cstdlib>
#include<cstdio>
#define TABLE_SIZE 100000
using namespace std;

struct data {
	string name;
	int cnt = 0;
};

struct data* arr[TABLE_SIZE] ={NULL,};
int cur_index = 0;

int search(string str)
{
	
	int i = 0;
	//struct data *tmp = arr[i];
	while(arr[i])
	{
		if(arr[i]->name==str)
		{
			return ++(arr[i]->cnt);
		}
		i++;
	}
	return 0;
}

string insert(string str)
{
	int sname = search(str);
	if(!sname)
	{
		struct data *node = (struct data *)calloc(1,sizeof(struct data));
		if(!node)
		{
			cout<<"not sufficient memory"<<endl;
			return NULL;
		}
		node->name = str;
		node->cnt = 0;
		arr[cur_index] = node;
		cur_index++;
		return "OK";
	}
	return (str.append(to_string(sname)));
}

int main()
{
	int n;
	int i;
	string str;
	//cout<<"size of arr is: "<<sizeof(arr)/(1024*1024)<<endl;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>str;
		cout<<insert(str)<<endl;
	}
	//cout<<"size of arr is: "<<sizeof(arr)/(1024*1024)<<endl;
	return 0;
}