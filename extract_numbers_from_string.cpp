//https://www.geeksforgeeks.org/extract-integers-string-c/
#include<iostrem>

using namespace std;

int main()
{
	int i,n;
	string str;
	cin>>str;
	for(i=0;i<str.size();i++)
	{
		int j;
		int num_found = 0;
		j = i;
		int c = ((int)str[j])-48;
		while(c>=0 && c<=9)
		{
			num_found = 1;
			cout<<c;
			c = ((int)str[++j])-48;
		}
		if(num_found)
			cout<<endl;
		i = j;
			
	}
	return 0;
}