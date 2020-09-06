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
ll tree[4000006];
ll a[100006];
void build(ll node,ll st,ll ends)
{
    if(st==ends)
    {
        tree[node]=a[st];
        return;
    }
    ll mid=(st+ends)/2;
    build(2*node,st,mid);
    build(2*node+1,mid+1,ends);
    tree[node]=__gcd(tree[2*node],tree[2*node+1]);
}
im
{
    ll n,q;
    scns(n,q);
    rep(i,0,n)
    scn(a[i]);
    build(1,0,n-1);
    rep(j,0,q)
    {
        ll k;
        scn(k);
        rep(i,0,n) a[i]+=k;
        ll ans=a[0];
        rep(i,1,n)
      ans=__gcd(a[i],ans);
      rep(i,0,n) a[i]-=k;
        cout<<ans<<endl;
    }
}
