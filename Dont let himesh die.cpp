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
ll a[1000006];
ll sum;
vector <pairs> v[maxx];
map <ll,ll> m;
ll ans[maxx];
void build(ll node,ll st,ll ends)
{
    if(st==ends) {tree[node]=a[st]; return;}
    ll mid=(st+ends)/2;
    build(2*node,st,mid);
    build(2*node+1,mid+1,ends);
    tree[node]=(tree[2*node]+tree[2*node+1]);
}
void update(ll node,ll st,ll ends,ll ind,ll x)
{
    if(st==ends) {tree[node]+=x; return;}
    ll mid=(st+ends)/2;
    if(mid>=ind){
        tree[node]+=x;
        update(2*node,st,mid,ind,x);}
    else{
            tree[node]+=x;
        update(2*node+1,mid+1,ends,ind,x);}

}
ll query(ll node,ll st,ll ends,ll l,ll r)
{
    if(st==ends && (l==st||r==ends)) return tree[node];
  ll mid=(st+ends)/2;
  if(st>=l && ends<=r) return tree[node];
  else if(r<st||ends<l) return 0;
  else
     return (query(2*node,st,mid,l,r)+query(2*node+1,mid+1,ends,l,r));
}
im
{
    ll n;
    scn(n);
    rep(i,0,n)
    scn(a[i]);
    build(1,0,n-1);
    ll q;
    scn(q);
    rep(i,0,q)
    {
        ll l,r;
        scns(l,r);
        v[r].pb(l,i);
    }
    ll sum=0;
    /*rep(i,0,n)
    {
        if(m[a[i]]==0)
        sum+=1,m[a[i]]=1;
        else sum-=1;
        for(auto it:g[i])
        {
            ll maxim=query(it.f,i);
            ans[it.s]=maxim-sum;
        }
    }

    rep(i,0,q)
    cout<<ans[i]<<endl;*/

    ll am=query(1,0,n-1,,n-1);
    cout<<am;


}
