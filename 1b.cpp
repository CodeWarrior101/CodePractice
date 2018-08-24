//https://codeforces.com/contest/1/problem/B
#include<iostream>
#include<cmath>
#include <algorithm>
#define toupper(str) transform(str.begin(), str.end(),str.begin(), ::toupper)
#define tolower(str) transform(str.begin(), str.end(),str.begin(), ::tolower)

using namespace std;

// returns uppercase string
string cal_str(int val)
{
	//cout<<"val = "<<val<<endl;
	int i,j;
	int len;
	string str;
	int d;
	int r;
	
	len = 1;
	d = val;
	r = val%26;
	while(d > 26 && val > 26)
	{
		d = d/26;
		//cout<<"d = "<<d<<endl;
		len++;
	}
	//cout<<"len = "<<len<<endl;
	//d = val;
	if(len==1)
	{
		char c = (char)(val+64);
		str += c;
		return str;
	}
	int tmp_val = val;
	i =len-1;
	while(i>=0)
	{
		int pow_val =(int) pow(26,i);
		
		d = tmp_val/pow_val;
		r = tmp_val%pow_val;

		if(r > 26)
		{
			char c = (char)(d+64);
			str += c;
			//cout<<"d = "<<d<<" r = "<<r<<endl;
			//cout<<" str = "<<str<<endl;
			
		}
		else if(r > 0)
		{
			char c = (char)(d+64);
			str += c;
			
			c = (char)(r+64);
			str += c;
			
			cout<<"d = "<<d<<" r = "<<r<<endl;
			cout<<" str = "<<str<<endl;
			break;
		}
		else
		{
			char c = (char)((d-1)+64);
			str += c;
			str += 'Z';
			//cout<<" str = "<<str<<endl;
			break;
		}
		
		if(!d)
		{
			if(str[str.size()-2])
				str[str.size()-2] = (char)((int)str[str.size()-2] -1);
			str[str.size()-1] = 'Z';
		}
		tmp_val = r;
		i--;
	}
	//cout<<"str = "<<str<<endl;
	return str;
}

// for upper case string
int cal_val(string s)
{
	int i,j;
	int p;
	int val;
	int len = s.size();
	//cout<<"len = "<<len<<endl;
	//p = pow(26,(len-1));
	//cout<<"pow = "<<p<<endl;
	int s_val = 0;
	for(i=len-1;i>=0;i--)
	{
		s_val += (((int)s[i])-64)*pow(26,(len-1)-i);
	}
	//cout<<"val = "<<s_val<<endl;
	//cal_str(s_val);
	return s_val;
}


int main()
{
	string str;
	int n;
	int i,j;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>str;
		
	string s1 = "";// to store nums in strings
	string s2 = "";
	string s3 = ""; // to store second format string
	
	// first number string
	j = 0;
	int len = str.length();
	//cout<<"len = "<<len<<endl;
	int c = ((int)str[j])-48;
	while((j<len) && !(c>=0 && c<=9))
	{
		s3 += str[j];
		j++;
		c = ((int)str[j])-48;
	}
	while((j<len) && (c>=0 && c<=9))
	{
		s1 += str[j];
		c = ((int)str[++j])-48;
	}
	// seconmd number
	while((j<len) && !(c>=0 && c<=9))
	{
		j++;
		c = ((int)str[j])-48;
	}
	// first number string
	while((j<len) && (c>=0 && c<=9))
	{
		s2 += str[j];
		c = ((int)str[++j])-48;
	}		
	//cout<<"str 1: "<<s1<<endl;
	//cout<<"str 2: "<<s2<<endl;
	int len1 = s1.length();
	int len2 = s2.length();
	if(len1 && len2)
	{
		//cout<<"format 1"<<endl;
		int num2;
		//cout<<"s2 = "<<s2<<endl;
		num2 = stoi(s2);
		//string upper_str = cal_str(num2);
		//toupper(upper_str);
		//ut<<"num2 = "<<num2<<endl;
		//cout<<cal_str(num2)<<endl;
		cout<<cal_str(num2)+s1<<endl;
	}
	else
	{
		//cout<<"format 2"<<endl;
		//toupper(s3);
		cout<<(("R"+s1+"C"))<<cal_val(s3)<<endl;
		//cout<<(int)'A'<<endl;
	}
	}
	
	//cout<<(char)64<<endl;
		
	return 0;
}
