https://www.geeksforgeeks.org/shortest-uncommon-subsequence/?ref=rp

#include<bits/stdc++.h>
using namespace std;
int rec(string s,string t,int i,int j)
{
	int n=s.size(),m=t.size();

	if(i==n)
	return INT_MAX-1;

	if(j>=m)
	return 1;

	int k=j;
	for(k=j;k<m;k++)
	if(t[k]==s[i])
	break;

	if(k==m)
	return 1;

	int x=rec(s,t,i+1,j);
	int y=1+rec(s,t,i+1,k+1);

	int a=min(x,y);

	return a;
}
int main()
{
	string s,t;
	cin>>s>>t;
	
	int ans=rec(s,t,0,0);
	cout<<ans;
}