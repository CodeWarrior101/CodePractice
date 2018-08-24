#include<iostream>

using namespace std;

int  main()
{
    int n =10;
    int i;
    for(i=0; i<n;i++)
    {
        int j;
        int cnt = 0;
        string str;
        cin>>str;
        for(j=0;j<str.length();j++)
        {
            if((str[j]=='T') || (str[j]=='D') || (str[j]=='F') || (str[j]=='L'))
                cnt++;
        }
        cout<<(1<<cnt)<<endl;
    }
    return 0;
}
