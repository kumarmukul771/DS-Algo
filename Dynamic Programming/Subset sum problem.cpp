#include<bits/stdc++.h>
using namespace std;
#define ll           long long
#define rep(i,j,n)   for(ll i=j;i<n;i++)
#define scn(a)       scanf("%lld",&a)
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
#define nl           printf("\n")
#define maxx         300005
#define inf          INT_MAX
#define zer          INT_MIN
int main()
{
    ll n,sum=0;
    scn(n);
    ll a[n+1]={0};

    rep(i,1,n+1)
    scn(a[i]);

    scn(sum);

    ll dp[n+5][sum+5];
    mem(dp,0);

    rep(i,0,n+1)
    rep(j,0,sum+1)
    {
        if(j==0)
        dp[i][j]=1;
    }

    rep(i,1,n+1)
    {
        rep(j,1,sum+1)
        {
            dp[i][j]=dp[i-1][j];
            if(a[i]<=j)
            dp[i][j]=dp[i-1][j-a[i]] || dp[i][j];
        }
        cout<<endl;
    }

    cout<<dp[n][sum];
}