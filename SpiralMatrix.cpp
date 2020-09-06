#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);

		int a[n+5][n+5]={0};		

		int x=n,st=0,val=1;

		while(x)
		{
			for(int i=st;i<x;i++)
			a[st][i]=val,val++;

			for(int i=st+1;i<x;i++)
			a[i][x-1]=val,val++;

			for(int i=x-2;i>=st;i--)
			a[x-1][i]=val,val++;

			for(int i=x-2;i>=(st+1);i--)
			a[i][st]=val,val++;

			st++;
			x--;
		}

		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			cout<<a[i][j]<<" ";

			cout<<endl;
		}
	}
}