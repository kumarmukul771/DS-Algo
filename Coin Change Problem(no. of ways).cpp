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
ll mod=1e9+7;
im
{
    ll m,n;
    scns(m,n);
    ll a[m+1];
    rep(i,1,m+1) scn(a[i]);
    ll dp[m+1][n+1];
    mem(dp,0);
    rep(i,1,m+1)
    dp[i][0]=1;
    rep(i,1,m+1)
    rep(j,1,n+1)
    {
        dp[i][j]=dp[i-1][j];
        if((j-a[i])>=0)
        dp[i][j]=(dp[i][j]+dp[i][j-a[i]])%mod;
    }
    cout<<dp[m][n];
}
