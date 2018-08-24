//https://codeforces.com/contest/2/problem/B
#include<iostream>
#include<cmath>
#define INT_MAX ~(1<<31)
using namespace std;

int r[] = {0,1};
int c[] = {1,0};
int min_noz = INT_MAX;

int visited[1000][1000] = {0,};

int pathr[1000] = {0,};
int pathc[1000] = {0,};
int pr = 0;
int pc = 0;

int cal_trailing_zeros(int n)
{
    int d,r;
    int i;
    int num = n;
    int nod = 0; // no if digits
    while(1)
    {
        d = num/10;
        r = num%10;
        nod++;
        num = d;
        if(!d)
            break;
    }
    i = nod;
    for(i = nod-1;i>0;i--)
    {
       d = n/(int)pow(10,i);
       r = n%(int)pow(10,i);
       if(!r)
           return i;
    }
    return 0;
}

int check(int r,int c,int n)
{
    if((r < n) && (c < n))
        return 1;
    return 0;
}

void cal_val(int m[][1000],int n,int sr,int sc,int dr,int dc,int pval,int pathr[],int pathc[],int pr,int pc)
{
    int i;
    visited[sr][sc] = 1;
    int val = pval*m[sr][sc];
    int noz = cal_trailing_zeros(val);

    pathr[pr] = sr;
    pr++;
    pathc[pc] = sc;
    pc++;

    if(noz > min_noz)
    {
        goto end;
        //return;
    }
    if((sr == dr) && (sc == dc))
    {
        //cout<<"Destination arrived"<<endl;
        for(i=0;i<pr;i++)
        {
            cout<<"("<<pathr[i]<<", "<<pathc[i]<<")"<<" ";
        }
        cout<<endl;
        if(min_noz > noz)
        {
            min_noz = noz;
        }
        cout<<"min no of zeros:"<<min_noz<<endl;
    }
    else
    {
        for(i=0;i<2;i++)
        {
            int row = sr+r[i];
            int col = sc+c[i];
            if(check(row,col,n) && !visited[row][col])
            {
                //cout<<"("<<row<<", "<<col<<")"<<endl;
                // calculate no of zeros in the current cell value
                //visited[row][col] = 1;
                cal_val(m,n,row,col,dr,dc,val,pathr,pathc,pr,pc);
                //visited[row][col] = 0;
            }
        }
    }
    label:end:
    pr--;
    pc--;
    visited[sr][sc] = 0;
}

int main()
{
    int n;
    int m[1000][1000];
    int i,j;
    cin>>n;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            cin>>m[i][j];
    }
    cal_val(m,n,0,0,n-1,n-1,1,pathr,pathc,pr,pc);
    for(i= 0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<visited[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
