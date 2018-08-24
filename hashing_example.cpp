//https://www.hackerearth.com/practice/data-structures/hash-tables/basics-of-hash-tables/tutorial/
#include<iostream>

using namespace std;

int hash(char c)
{
  return c-'a';
}

void print_charFrequency(string str)
{
  int freq[26]={0,};
  int i;
  for(i=0;i<str.length();i++)
  {
    int index = hash(str[i]);
    freq[index]++;
  }
  for(i=0;i<26;i++)
  {
    if(freq[i])
    {
      cout<<char(97+i)<<" "<<freq[i]<<endl;
    }
  }
}

int main()
{
  string str = "abcdefaabdffaqqqqqqqqeqqqewewwewwffghjjkllhh";
  print_charFrequency(str);
  return 0;
}
