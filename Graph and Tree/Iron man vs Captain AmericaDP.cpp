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
im
{
    tc
    {
        ll n;
        scn(n);
        ll r1[n];
        ll r2[n];
        ll t1[n-1],t2[n-1];
        rep(i,0,n) scn(r1[i]);
        rep(i,0,n) scn(r2[i]);
        rep(i,0,n-1) scn(t1[i]);
        rep(i,0,n-1) scn(t2[i]);
        ll dp[2][n];
        mem(dp,0);
        dp[0][0]=r1[0];
        dp[1][0]=r2[0];
        //cout<<dp[0][0]<<" "<<dp[1][0]<<endl;
        rep(i,1,n)
        {
            dp[0][i]=r1[i]+min(dp[0][i-1],dp[1][i-1]+t2[i-1]);
            dp[1][i]=r2[i]+min(dp[1][i-1],dp[0][i-1]+t1[i-1]);
          //          cout<<dp[0][i]<<" "<<dp[1][i]<<endl;
        }
        //cout<<dp[0][n-1]<<" "<<dp[1][n-1]<<endl;
        ll ans=min(dp[0][n-1],dp[1][n-1]);
        cout<<ans<<endl;
    }
}
