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
    ll n;
    scn(n);
    ll a[n+1];
    rep(i,1,n+1) scn(a[i]);
    ll dp[n+1][2];
    mem(dp,0);
    ll cnt=0;
    if(a[1]%2==0) dp[1][0]=1;
    else dp[1][1]=1;
    ll feven=0,fodd=0;
    rep(i,2,n+1)
    {
             dp[i][1]=dp[i-1][1]+fodd;
             dp[i][0]=dp[i-1][0]+feven;
             fodd=0;
             feven=0;
        if(a[i]%2==0)
        {
            if(a[i-1]%2!=0) {
             if(dp[i][0]!=dp[i][1])
                 dp[i][0]++;
             else feven=1;
            }
            else
             dp[i][0]++;
        }
        else if(a[i]%2!=0)
        {
            if(a[i-1]%2==0)
            {
                if(dp[i][0]==dp[i][1]) fodd=1;
                else dp[i][1]++;
            }
            else
             dp[i][1]++;
        }
    }
    ll ans=0;
    rep(i,2,n+1)
    {
        if(dp[i][0]==dp[i][1]) ans+=dp[i][0];
    }
    cout<<ans;
}
