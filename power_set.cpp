//https://www.geeksforgeeks.org/recursive-program-to-generate-power-set/
#include<iostream>
#include<ctime>
#include<cstdio>

using namespace std;

void powerSet(string str, int index = -1,
              string curr = "")
{
    int n = str.length();

  //  cout<<"str length is :"<<n<<" index is:"<<index<<endl;

    // base case
  //  if (index == n)
    //    return;

    // First print current subset
    cout << curr << "\n";

    // Try appending remaining characters
    // to current subset
    for (int i = index + 1; i < n; i++) {

        curr += str[i];
        powerSet(str, i, curr);

        //cout<<"index:"<<index<<" erasing:"<<curr[curr.size() - 1]<<endl;
        curr.erase(curr.size() - 1);
    }
    return;
}

int main()
{
  /*char str[] = {'a','b','c'};
  int n = sizeof(a)/sizeof(a[0]);
  power_set(str,n);*/
  string str = "abcdefghijk";
  clock_t start_time = clock();
  powerSet(str);
  printf("time taken is: %f seconds\n",((double)(clock()-start_time))/CLOCKS_PER_SEC);
  return 0;
}
