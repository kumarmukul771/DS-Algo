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
#define inf          pow(2,32)
#define zer          LLONG_MIN
#define mp           make_pair
ll n,dp[100005],m=3;
ll rec(ll x)
{
    if(x==n)
    return 1;
    if(x>n)
    return 0;
    if(dp[x]!=-1)
    return dp[x];

    ll ans=0;

    rep(i,1,4)
    ans+=rec(x+i);

    return dp[x]=ans;
}
int main()
{
    scn(n);
    mem(dp,-1);

    ll ans=rec(0);

    cout<<ans<<endl;
}