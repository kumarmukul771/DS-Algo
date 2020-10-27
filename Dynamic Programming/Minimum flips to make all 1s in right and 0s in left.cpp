#include<bits/stdc++.h>
using namespace std;
#define ll           long long
#define rep(i,j,n)   for(ll i=j;i<n;i++)
#define scn(a)       scanf("%lld",&a)
#define nl         printf("\n")
#define scns(a,b)    scanf("%lld %lld",&a,&b)
#define print(a)     printf("%lld",a)
#define tc           ll t; scn(t); while(t--)
#define vec          vector<ll>
#define pb           push_back
#define pairs        pair<ll,ll>
#define f            first
#define s            second
#define all(v)       v.begin(),v.end()
#define srt(v)       sort(v.rbegin(),v.rend())
#define mem(a,b)     memset(a,b,sizeof(a))
#define im           int main()
#define maxx         5000005
#define inf          LLONG_MAX
#define zer          LLONG_MIN
#define mp           make_pair
int n,cnt=0;
int dp[100][2];
int rec(string s,int i,int f)
{
	if(i>=n)
	return 0;

	int ans=INT_MAX;

	if(dp[i][f]!=-1)
	return dp[i][f];

	if(!f)
	{
		if(s[i]=='0')
		ans=min(rec(s,i+1,0),rec(s,i+1,1)+1);
		else
		ans=min(rec(s,i+1,0)+1,rec(s,i+1,1));	
	}
	else
	{
		if(s[i]=='0')
		ans=rec(s,i+1,f)+1;
		else ans=rec(s,i+1,f);
	}

	cnt++;

	return dp[i][f]=ans;
}
int main()
{
	string s;
	cin>>s;

	n=s.length();
	mem(dp,-1);

	int ans=rec(s,0,0);
	cout<<ans<<" "<<cnt<<endl;
}