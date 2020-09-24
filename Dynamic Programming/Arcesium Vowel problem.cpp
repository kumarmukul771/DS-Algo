#include<bits/stdc++.h>
using namespace std;
int ans=1e9+7,c=0;
void rec(string s,int sum,int j,int move)
{
	if(j==-1)
	{
		ans=min(ans,sum);
		return;
	}
	for(int i=-25;i<26;i++)
	{
		int ind=s[j]-'a'+i+move;
		if(ind<0)
		ind+=26;
		ind%=26;

		char ch='a'+ind;
		if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
		rec(s,sum+abs(i),j-1,move+i);
	}
}
int main()
{
	// string s;
	// cin>>s;
	// int n=s.size();

	// rec(s,0,n-1,0);

	// cout<<ans<<endl<<c<<endl;
	cout<<"HELLO";
}