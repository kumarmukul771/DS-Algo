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
ll n=100005;
ll dp[100006][10];
ll isPrime(ll x)
{
    vec v{2,3,5,7};
    ll f=0;
    rep(i,0,v.size())
    {
        if(v[i]==x)
        {
            f=1;
            break;
        }
    }
    return f;
}
void DP()
{
        rep(i,0,10)
        dp[0][0]=0;
        dp[1][0]=0;
        rep(i,1,10)
        dp[1][i]=1;
        rep(i,2,n+1)
        {
            rep(j,0,10)
            {
                rep(k,0,10)
                {
                    if(isPrime(abs(k-j)))
                        dp[i][j]=(dp[i][j]+dp[i-1][k])%mod;
                }
            }
        }
}
im
{
   DP();
    tc
    {
        ll N;
        scn(N);
        ll sum=0;
        rep(i,0,10)
        {
            sum+=dp[N][i];
            sum%=mod;
        }
        cout<<sum<<endl;
    }
}
