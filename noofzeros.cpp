// this code calculates no of zeros in a int number
#include<iostream>
using namespace std;

int cal_zeros(int n)
{
    int d,r;
    int num = n;
    int cnt = 0;

    while(1)
    {
        d = num/10;
        r = num%10;
        if(!r)
            cnt++;
        num = d;
        if(num < 10)
            break;
    }
    return cnt;
}
int main()
{
    int n;
    cin>>n;
    cout<<cal_zeros(n)<<endl;
    return 0;
}
