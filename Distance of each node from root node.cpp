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
vector <pairs> g[1000006];
ll path[1000006];
void dfs(ll x,ll par,ll wt)
{
    cout<<1<<endl;
    path[x]+=(path[par]+wt);
    rep(i,0,g[x].size())
    {
        if(g[x][i].f!=par)
            dfs(g[x][i].f,x,g[x][i].s);
    }
}
im
{
  ll n;
  scn(n);
  rep(i,0,n-1)
  {
      ll x,y,wt;
      cin>>x>>y>>wt;
      g[x].pb(mp(y,wt));
      g[y].pb(mp(x,wt));
  }
  dfs(1,0,0);
  rep(i,1,n+1) cout<<i<<" "<<path[i]<<endl;
}
