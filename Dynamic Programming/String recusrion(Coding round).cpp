#include<bits/stdc++.h>
using namespace std;
int n;
string s="";
int dp[105][3][5][5];
int rec(int i,int a,int b,int c)
{
	if(i>n)
	{
		cout<<s<<endl;
		return 1;
	}

	if(dp[i][a][b][c]!=-1)
	return dp[i][a][b][c];

	int ans=0;

	// taking b is allowed
	if(b==0)
	{
		// take a for next index
		if(a==0||a==1)
		{
			s+='a';
			ans+=rec(i+1,a+1,b,c);
			s=s.substr(0,s.size()-1);
		}

		// take b for next index
		s+='b';
		ans+=rec(i+1,0,2,c);
		s=s.substr(0,s.size()-1);

		// take c for next index if c<3
		if(c<3)
		{
			s+='c';
			ans+=rec(i+1,0,b,c+1);
			s=s.substr(0,s.size()-1);
		}
	}
	else// taking b is not allowed
	{
		// take a for next inde
		if(a==0||a==1)
		{
			s+='a';
			ans+=rec(i+1,a+1,b-1,c);
			s=s.substr(0,s.size()-1);
		}

		// take c for next index if c<3
		if(c<3)
		{
			s+='c';
			ans+=rec(i+1,a,b-1,c+1);
			s=s.substr(0,s.size()-1);
		}
	}

	return dp[i][a][b][c]=ans;
}
int main()
{
	cin>>n;
	memset(dp,-1,sizeof(dp));
	int ans=rec(1,0,0,0);

	cout<<ans<<endl;
}