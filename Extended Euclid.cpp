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
ll x;
ll y;
ll d;
void extendedEuclid(ll a,ll b)
{
    if(b==0)
    {
        d=a;
        x=1;
        y=0;
    }
    else
    {
        extendedEuclid(b,a%b);
        ll temp=x;
        x=y;
        y=temp-((a/b)*y);
    }
}
ll modInvers(ll a,ll m)
{
    extendedEuclid(a,m);
    if(x>0) return x;
    else{
    x+=m;
    x=x%m;
    return x;
    }
}
im
{
    ll a,m;
    scns(a,m);
    modInvers(a,m);
    cout<<x;
}
