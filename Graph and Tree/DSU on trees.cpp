#include<bits/stdc++.h>
using namespace std;
#define ll           long long
#define rep(i,j,n)   for(ll i=j;i<n;i++)
#define scn(a)       scanf("%lld",&a)
#define scns(a,b)    scanf("%lld %lld",&a,&b)
#define print(a)     printf("%lld",a)
#define tc           ll t; scn(t); while(t--)
#define inp          scn(n); rep(i,0,n) scn(a[i])
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
#define mp           make_pair
ll mod=998244353;
vec g[maxx];
vector <string> str;
vec root;
vector <pairs> query[maxx];
ll ans[maxx];
ll euler[maxx];ll tim;ll in[maxx];ll ou[maxx];
ll depth[maxx];
set <string> s1[maxx];


void dfs2(ll u,ll par)
{
    in[u]=tim;
    euler[tim]=u;
    //s1[depth[u]].insert(str[u]);
    for(auto it:g[u])
    {
        if(it!=par)
        {
            depth[it]=depth[u]+1;
            tim++;
            dfs2(it,u);
        }
    }
    ou[u]=tim;
}


void dfs(ll node,ll par,ll keep)
{
    ll mx=-1,big=-1;
    for(auto t:g[node])
    {
        if(t!=par)
        {
            if(mx<(ou[t]-in[t]+1))
            {
                mx=ou[t]-in[t]+1;
                big=t;
            }
        }
    }


    for(auto t:g[node])
    {
        if(t!=par && t!=big)
            dfs(t,node,0);
    }

    s1[depth[node]].insert(str[node-1]);

    if(big!=-1) dfs(big,node,1);


    for(auto it:g[node])
    {
        if(it!=par && it!=big)
        {
          for(ll i=in[it];i<=ou[it];i++)
          {
            ll u=euler[i];
            s1[depth[u]].insert(str[u-1]);
          }
        }
    }


    for(auto it:query[node])
    {
        ll i=it.s;
        ll orig=it.f + depth[node];
        ans[i]=s1[orig].size();
    }

    if(!keep)
    {
        for(ll i=in[node];i<=ou[node];i++)
          {
            ll u=euler[i];
            s1[depth[u]].erase(str[u-1]);
          }
    }


}


im
{
    ll n;
    scn(n);

    ll ind;

    rep(i,1,n+1)
    {
        string str2;
        ll a;
        cin>>str2;
        cin>>a;
        str.pb(str2);
        if(a!=0){
        g[i].pb(a);
        g[a].pb(i);
        }
        else
        root.pb(i);
    }

    ll q;
    scn(q);

    ll j=0;
    rep(i,0,q)
    {
        ll u,k;
        scns(u,k);
        query[u].pb(mp(k,j));
        j++;
    }

    for(auto t:root){
    dfs2(t,0);
    tim++;
    }

    for(auto t:root){
    dfs(t,0,0);}


    rep(i,0,q)
    cout<<ans[i]<<endl;
}
