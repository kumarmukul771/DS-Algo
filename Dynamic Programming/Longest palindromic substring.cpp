#include<bits/stdc++.h>
using namespace std;
int rec(string s,string t,int n,int m,int ele)
{
	if(n<=0 || m<=0)
	return ele;

	if(s[n-1]==t[m-1])
	ele=max(ele,rec(s,t,n-1,m-1,ele+1));
	
	ele=max({ele,rec(s,t,n-1,m,0),rec(s,t,n,m-1,0)});

	return ele;
}
int main()
{
	string s;
	cin>>s;
	int n=s.size();

	string t=s;
	reverse(s.begin(),s.end());

	cout<<rec(t,s,n,n,0);
}