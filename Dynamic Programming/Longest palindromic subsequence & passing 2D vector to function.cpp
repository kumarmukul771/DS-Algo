#include<bits/stdc++.h>
using namespace std;
int rec(string s,string t,int n,int m,vector<vector<int>>& dp)
{
	if(n<=0 || m<=0)
	return 0;

	if(dp[n][m]!=-1)
	return dp[n][m];

	int ans=0;

	if(s[n-1]==t[m-1])
	ans=1+rec(s,t,n-1,m-1,dp);
	else ans=max(rec(s,t,n-1,m,dp),rec(s,t,n,m-1,dp));

	return dp[n][m]=ans;
}
int main()
{
	string s;
	cin>>s;
	int n=s.size();

	vector<vector<int>> dp(n+5,vector<int>(n+5,-1));

	string t=s;
	reverse(s.begin(),s.end());

	cout<<rec(t,s,n,n,dp);
}