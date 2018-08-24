#include<iostream>
#include<string>
#include<algorithm>

#define TABLE_SIZE 100000

using namespace std;



string insert(string name,int scnt[])
{
	
}

int main()
{
	string str_sort[TABLE_SIZE];
	string str[TABLE_SIZE];
	int n;
	cin>>n;
	int i;
	for(i=0;i<n;i++)
	{
		cin>>str[i];
		str_sort[i] = str[i];
	}
	// sort strings
	sort(str_sort,str_sort+n);
	
	for(i=0;i<n;i++)
	{
		if(!binary_search(str_sort, str_sort+n, str[i]));
		{
			cout<<"OK"<<endl;
		}
	}
	
	return 0;
}