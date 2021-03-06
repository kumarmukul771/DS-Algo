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
#define maxx         500005
#define inf          INT_MAX
#define zer          LLONG_MIN
ll mod=1e9+7,n,m,a[maxx];
ll lim,tim=1;
vec v1[maxx];
ll parent[maxx],sub[maxx],ans[maxx];
ll up[maxx][30],in[maxx],out[maxx];
ll level[maxx],mark[maxx],tot;

void dfsLca(ll u,ll par)
{
	up[u][0]=par;
	in[u]=tim++;

	rep(i,1,lim+1)
	up[u][i]=up[up[u][i-1]][i-1];

	for(auto it:v1[u])
	if(it!=par)
	{
	    level[it]=level[u]+1;
	    dfsLca(it,u);
	}

	out[u]=tim++;
}

bool isancestor(ll u,ll v)
{
	return (in[u]<in[v] && out[u]>out[v]);
}

ll lca(ll u,ll v)
{
	if(isancestor(u,v))
	return u;

	if(isancestor(v,u))
	return v;

	if(u==v)
	return u;

	for(ll i=lim;i>=0;i--)
	{
		if(!isancestor(up[u][i],v))
		u=up[u][i];
	}

	return up[u][0];
}
void dfs(ll u,ll par)
{
	sub[u]=1;
	tot++;

	for(auto it:v1[u])
	if(it!=par && !mark[it])
	{
	    dfs(it,u);
	    sub[u]+=sub[it];
	}

}
ll centroid(ll u,ll par)
{
    for(auto it:v1[u])
    if(it!=par &&  sub[it]>tot/2 && !mark[it])
    return centroid(it,u);

    return u;
}
void decompose(ll u,ll par)
{
    tot=0;
    dfs(u,u);

    ll cen=centroid(u,u);

    if(par==-1)
    par=cen;

    parent[cen]=par;
    mark[cen]=1;

    for(auto it:v1[cen])
    if(!mark[it])
    decompose(it,cen);
}
ll dis(ll u,ll v)
{
    ll distance=level[u]+level[v];
    distance-=2*level[lca(u,v)];

    return distance;
}
void update(ll u)
{
    ll v=u;

    while(1)
    {
        ans[v]=min(ans[v],dis(u,v));

        if(parent[v]==v)
        break;

        v=parent[v];
    }
}
ll query(ll u)
{
    ll v=u;
    ll res=inf;

    while(1)
    {
        res=min(res,dis(u,v)+ans[v]);

        if(parent[v]==v)
        break;

        v=parent[v];
    }

    return res;
}
int main(){
    scns(n,m);

    rep(i,1,n)
    {
        ll u,v;
        scns(u,v);

        v1[u].pb(v);
        v1[v].pb(u);
    }

    lim=ceil(log2(n)*1.0);
    dfsLca(1,1);

    decompose(1,-1);

    rep(i,0,n+1)
    ans[i]=inf;

    update(1);

    while(m--)
    {
        ll inp,node;
        scns(inp,node);

        if(inp==1)
        update(node);

        else
        {
            ll res=query(node);
            printf("%lld\n",res);
        }
    }
}
