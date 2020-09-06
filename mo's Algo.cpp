#include<bits/stdc++.h>
using namespace std;
#define ll           long long
#define rep(i,j,n)   for(ll i=j;i<n;i++)
#define scn(a)       scanf("%lld",&a)
#define nl           printf("\n")
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
map<ll,ll> ans;
ll arr[1000005];
ll blocks;
struct type
{
    ll l,r;
    ll ind;
};
struct type query[maxx];
bool comp(type a,type b)
{
    if((a.l/blocks)!=(b.l/blocks)) return a.l<b.l;
    return a.r<b.r;
}
void mo(ll q)
{
    sort(query,query+q,comp);
    ll lf=0,rt=0,sum=0;
    rep(i,0,q)
    {
     ll l=query[i].l;
     ll r=query[i].r;
     ll ind=query[i].ind;
     while(l>lf)
     {
         sum-=arr[lf];
         lf++;
     }
     while(l<lf)
     {
         sum+=arr[lf-1];
         lf--;
     }
     while(r>=rt)
     {
         sum+=arr[rt];
         rt++;
     }
     while(r+1<rt)
     {
         sum-=arr[rt-1];
         rt--;
     }
     ans[ind]=sum;
    }
}
im
{
    ll n,q;
    scns(n,q);
    blocks=sqrt(n);
    rep(i,0,n)
    scn(arr[i]);
    rep(i,0,q)
    {
        ll l,r;
        scns(l,r);
        query[i].l=l-1;
        query[i].r=r-1;
        query[i].ind=i;
    }
    mo(q);
    rep(i,0,q)
    cout<<ans[i]<<endl;
}
