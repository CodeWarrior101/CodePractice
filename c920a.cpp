#include<iostream>
using namespace std;

int isvalid(int num,int n)
{
	if (num >= 0 && num < n) return 1;
	else
		return 0;
}

void printa(int a[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		cout << a[i]<<" ";
	cout << endl;
}

int cal(int n,int k,int t[])
{
	int i, j;
	int a[200] = {0, };
	int cnt = 0;
	for (i = 0; i < k; i++)
	{
		a[t[i]-1] = 1;
		cnt = 1;
	}
	//printa(a, n);
	while (1)
	{
		int g = 0;
		for (i = 0; i < n; i++)
		{
			//g = 0;
			//if (a[i] != 2)
				//g = 1;
			if (a[i] == 1)
			{
				a[i] = 2;
				if (isvalid(i - 1, n) && (a[i - 1] == 0))
				{
					a[i - 1] = 1;
					g = 1;
					//i--;
				}
				if (isvalid(i + 1, n) && (a[i + 1] == 0))
				{
					a[i + 1] = 1;
					g = 1;
					i++;
				}
			}
			//printa(a, n);
		}
		//printa(a, n);
		if (g)
		{
			cnt++;
			//cout << "cnt = " << cnt << endl;
		}
		else
			break;
	}
	return cnt;
}

int main()
{
	int tc;
	int n, k;
	int t[200];
	int i, j;

	cin >> tc;
	for (i = 0; i < tc; i++)
	{
		cin >> n >> k;
		for (j = 0; j < k; j++)
		{
			cin >> t[j];
		}
		cout << cal(n, k, t) << endl;
	}

	return 0;
}
