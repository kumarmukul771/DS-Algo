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
ll n,dp[1005][1005];
ll a[1005][1005]={0};
ll rec(ll pari,ll parj,ll i,ll j)
{
    if(i>=n || j>=n)
    return 0;
    if(i<0 || j<0)
    return 0;

    if(pari !=-1)
    {
        if((a[i][j]-a[pari][parj])!=1)
        return 0;
    }

    if(dp[i][j]!=-1)
    return dp[i][j];

    ll ans=max({rec(i,j,i+1,j),rec(i,j,i-1,j),rec(i,j,i,j+1),rec(i,j,i,j-1)});

    return dp[i][j]=ans+1;
}
int main()
{
    scn(n);
    rep(i,0,n)
    rep(j,0,n)
    scn(a[i][j]);

    mem(dp,-1);

    ll ans=-1;

    rep(i,0,n)
    rep(j,0,n)
    {
        if(dp[i][j]==-1)
        ans=max(ans,rec(-1,-1,i,j));
    }

    cout<<ans<<endl;
}