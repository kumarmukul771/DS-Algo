#include<bits/stdc++.h>
using namespace std;
#define ll           long long
#define rep(i,j,n)   for(ll i=j;i<n;i++)
#define tc           ll t; cin>>t; while(t--)
#define inp	         cin>>n; rep(i,0,n) cin>>a[i];
#define vec          vector <ll>
#define pb           push_back
#define pairs        pair<ll,ll>
#define f            first
#define s            second
#define all(v)       v.begin(),v.end()
#define st(a,n)      sort(a,a+n)
#define srt(v)       sort(v.begin(),v.end())
#define srte(v)      sort(v.rbegin(),v.rend())
#define mem(a)       memset(a,0,sizeof(a));
#define im           int main()
#define maxx         100005
#define inf	         LONG_MAX
#define zer          LONG_MIN
ll mod=1e9+7,n,m,q,a[maxx];
vec v[maxx],g[maxx];
ll dis[maxx],low[maxx],times=1,par[maxx],vis[maxx],vis2[maxx];
ll bridge[maxx];

ll up[maxx][30],in[maxx],out[maxx];
ll lim,tim=1;


void dfs(ll u,ll par){
	up[u][0]=par;
	in[u]=tim++;
	if(par!=1)
	bridge[u]+=bridge[par];

	rep(i,1,lim+1)
	up[u][i]=up[up[u][i-1]][i-1];

	for(auto it:g[u])
	{
		if(it!=par)
		dfs(it,u);
	}

	out[u]=tim++;
}
bool isancestor(ll u,ll v)
{
	return (in[u]<in[v] && out[u]>out[v]);
}
ll lca(ll u,ll v){
	if(isancestor(u,v))
		return u;
	if(isancestor(v,u))
		return v;
	if(u==v)
		return u;
	for(ll i=lim;i>=0;i--){
		if(!isancestor(up[u][i],v))
			u=up[u][i];
	}
	return up[u][0];
}

void bridges(ll u)
{
    dis[u]=low[u]=times++;
    vis[u]=1;
    ll childs=0;
    for(auto t:v[u])
    {
        if(!vis[t])
        {
            g[u].pb(t);
            g[t].pb(u);

            par[t]=u;
            bridges(t);

            if(low[t]>dis[u]) bridge[t]+=1;
            low[u]=min(low[u],low[t]);
        }
        else if(t!=par[u])
        low[u]=min(low[t],low[u]);
    }
}
int main()
{
    cin>>n>>m;

    rep(i,0,m)
    {
        ll a,b;
        cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    }

    bridges(1);

    lim=ceil(log2(n)*1.0);
	dfs(1,1);

	// rep(i,1,5)
	// {
	// 	for(auto t:g[i])
	// 	cout<<t<<" ";
	// 	cout<<endl;
	// }
	// rep(i,1,n+1)
	// cout<<i<<" "<<bridge[i]<<endl;

    cin>>q;
    while(q--)
    {
        ll x;
        cin>>x;
        ll anc=lca(n,x);
        ll ans=bridge[n]-2*bridge[anc]+bridge[x];
        if(ans==0) cout<<"impossible";
        else cout<<ans;
		cout<<endl;
    }
}
