#include<bits/stdc++.h>
using namespace std;
#define ll           long long
#define rep(i,j,n)   for(ll i=j;i<n;i++)
#define scn(a)       scanf("%lld",&a)
#define nl	     printf("\n")
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
#define maxx         500005
#define inf          LLONG_MAX
#define zer          LLONG_MIN
ll mod=1e9+7,n,a[maxx];
vec v1[maxx],vis;

void multiply(ll f[2][2],ll m[2][2]){
    ll a=(f[0][0]*m[0][0]+f[0][1]*m[1][0])%mod;
    ll b=(f[0][0]*m[0][1]+f[0][1]*m[1][1])%mod;
    ll c=(f[1][0]*m[0][0]+f[1][1]*m[1][0])%mod;
    ll d=(f[1][0]*m[0][1]+f[1][1]*m[1][1])%mod;

    f[0][0]=a;  f[0][1]=b;
    f[1][0]=c;  f[1][1]=d;
}
void power(ll n,ll f[2][2]){
    if(!n or n==1)
    return ;

    ll m[2][2]={{1,1},{1,0}};
    power(n/2,f);
    multiply(f,f);
    if(n&1) multiply(f,m);
}
ll fibo(ll n){
    ll f[2][2]={{1,1},{1,0}};
    if(!n) return 0;
    power(n-1,f);
    f[0][0]%=mod;
    return f[0][0];
}

im{
    tc{
        scn(n);
        ll ans=fibo(n+2);
        print(ans);
        nl;
    }
}
